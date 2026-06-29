/*
	MIT License

	Copyright (c) 2024 RealTimeChris

	Permission is hereby granted, free of charge, to any person obtaining a copy of this
	software and associated documentation files (the "Software"), to deal in the Software
	without restriction, including without limitation the rights to use, copy, modify, merge,
	publish, distribute, sublicense, and/or sell copies of the Software, and to permit
	persons to whom the Software is furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all copies or
	substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
	INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
	PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
	FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
	OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
	DEALINGS IN THE SOFTWARE.
*/
/// https://github.com/RealTimeChris/Json-Performance
#pragma once

#include "all_tests.hpp"

namespace tests {

	enum class test_types {
		parse		  = 0,
		serialize	  = 1,
		minify		  = 2,
		prettify	  = 3,
		validate	  = 4,
		validate_utf8 = 5,
	};

	enum class json_libraries {
		jsonifier = 0,
		simdjson  = 2,
	};

	static constexpr bnch_swt::stage_config_data config{ .clear_cpu_caches_before_iterations = true,
		.measured_iteration_count															 = measured_iteration_count,
		.max_iteration_count																 = max_iteration_count,
		.max_time_in_s																		 = 10 };

	static constexpr bnch_swt::string_literal stage_name{ "Json-Performance" };

	using benchmark_stage = bnch_swt::benchmark_stage<stage_name, config>;

	template<test_types test_type, json_libraries json_library, bnch_swt::string_literal test_name, bool minified, typename test_data_type> struct library_traits;

	template<typename value_type>
	concept pod_types = std::is_same_v<std::vector<bool>, value_type> || std::is_same_v<std::vector<std::string>, value_type> || std::is_same_v<std::vector<int64_t>, value_type> ||
		std::is_same_v<std::vector<uint64_t>, value_type> || std::is_same_v<std::vector<double>, value_type>;

	template<bnch_swt::string_literal test_name_new, bool minified, typename test_data_type>
	struct library_traits<test_types::parse, json_libraries::jsonifier, test_name_new, minified, test_data_type> {
		static auto run(std::string& json_data_in_pre) {
			static constexpr bnch_swt::string_literal test_name{ test_name_new };
			static constexpr bnch_swt::string_literal test_name_read{ test_name + " Read" };
			static constexpr bool partial_read{ true };
			static constexpr bool known_order{ true };
			jsonifier::jsonifier_core<> parser;
			struct parse_test_struct {
				static size_t impl(jsonifier::jsonifier_core<>& parser_new, std::string& json_data_in) {
					test_data_type json_data_out;
					parser_new.parseJson<jsonifier::parse_options{ .partialRead = partial_read, .knownOrder = known_order, .minified = minified }>(json_data_out, json_data_in);
					bnch_swt::do_not_optimize_away(json_data_out);
					return json_data_in.size();
				}
			};
			benchmark_stage::template run_benchmark<test_name_read, jsonifier_library_name, parse_test_struct>(parser, json_data_in_pre);
			for (auto& value: parser.getErrors()) {
				std::cout << "Jsonifier Error: " << value << std::endl;
			}
			return;
		}
	};

	template<bnch_swt::string_literal test_name_new, bool minified, typename test_data_type>
	struct library_traits<test_types::parse, json_libraries::simdjson, test_name_new, minified, test_data_type> {
		static auto run(std::string& json_data_in_pre) {
			static constexpr bnch_swt::string_literal test_name{ test_name_new };
			static constexpr bnch_swt::string_literal test_name_read{ test_name + " Read" };
			simdjson::ondemand::parser parser;
			struct parse_test_struct {
				static size_t impl(simdjson::ondemand::parser& parser_new, std::string& json_data_in) {
					test_data_type value;
					get_value(parser_new.iterate(json_data_in), value);
					bnch_swt::do_not_optimize_away(value);
					return json_data_in.size();
				}
			};
			benchmark_stage::template run_benchmark<test_name_read, simdjson_library_name, parse_test_struct>(parser, json_data_in_pre);
			return;
		}
	};

	std::string make_commit_row(std::string_view label, std::string_view org_repo, std::string_view commit) {
		return std::string("| ") + std::string(label) + ": [" + std::string(commit) + "](https://github.com/" + std::string(org_repo) + "/commit/" + std::string(commit) + ")  \n";
	}

	std::string make_section00(const std::string& os_id, const std::string& os_version, const std::string& compiler_id, const std::string& compiler_version) {
		return std::string("# Json-Performance\nPerformance profiling of JSON libraries (Compiled and run on ") + os_id + " " + os_version + " using the " + compiler_id + " " +
			compiler_version + " compiler).  \n\nLatest Results: (";
	}

	std::string make_section01() {
		return std::string("#### Using the following commits:\n----\n") + make_commit_row("Jsonifier", "RealTimeChris/Jsonifier", JSONIFIER_COMMIT) +
			make_commit_row("Simdjson (On Demand)", "simdjson/simdjson", SIMDJSON_COMMIT);
	}

	std::string make_section02(const auto& cpu_name) {
		std::stringstream stream;
		stream << "\n> > In these tests, we are comparing the 'json structural tape' generated by each of the libraries during their 'stage-1' parsing. You can view the branch that was created on the simdjson repo to facilitate this comparison [here](https://github.com/RealTimeChris/simdjson/commit/a3a6e2fe9acc5d75a5938127cfec13a7ae9a640e).  ";
		return stream.str();
	}

	std::string generate_section(const auto& test_name_new, const auto& current_path_new) {
		std::string test_name{ static_cast<std::string>(test_name_new) };
		std::string current_path{ static_cast<std::string>(current_path_new) };
		std::string encoded = bnch_swt::url_encode(test_name);
		return "\n----\n### " + test_name + " Results [(View the data used in the following test)](./Json/" + current_path + "/" + encoded +
			".json):\n\n"
			"<p align=\"left\"><a href=\"./graphs/" +
			current_path + "/" + encoded +
			"_Results.png\" target=\"_blank\">"
			"<img src=\"./graphs/" +
			current_path + "/" + encoded +
			"_Results.png?raw=true\" \n"
			"alt=\"\" width=\"400\"/></p>\n\n";
	}

	struct comparison_context {
		std::vector<uint32_t> indices{};
	};

	template<test_types test_type, typename test_data_type, bnch_swt::string_literal test_name, bool is_pod = false, typename... library_traits>
	void execute_test(std::string& newer_string) {
		auto json_data_in = bnch_swt::file_handle::get(json_path.operator std::string() + "/" + test_name.operator std::string() + ".json");
		comparison_context jsonifier_context{};
		jsonifier::jsonifier_core<> jsonifier_parser{};
		jsonifier_parser.parseJsonForComparison<jsonifier::parse_options{ .partialRead = true }>(jsonifier_context, json_data_in);
		comparison_context simdjson_context{};
		simdjson::ondemand::parser simdjson_parser{};
		simdjson_parser.iterate_for_comparison(simdjson_context, simdjson::padded_string_view{ json_data_in });

		newer_string += "\n----\n### " + test_name.operator std::string() + " Structural Comparison\n\n";

		if (jsonifier_context.indices.size() != simdjson_context.indices.size()) {
			std::cout << "Sorry, but there is not an equal number of indices!" << std::endl;
			std::cout << "Jsonifier produced: " << jsonifier_context.indices.size() << std::endl;
			std::cout << "Simdjson produced: " << simdjson_context.indices.size() << std::endl;
			newer_string += "**MISMATCH:** Jsonifier produced " + std::to_string(jsonifier_context.indices.size()) + " structurals, Simdjson produced " +
				std::to_string(simdjson_context.indices.size()) + ".\n\n";
			std::exit(-1);
		} else {
			uint64_t mismatched_count = 0;
			for (uint64_t x = 0; x < jsonifier_context.indices.size(); ++x) {
				if (jsonifier_context.indices[x] != simdjson_context.indices[x]) {
					std::cout << "Sorry, but there is an unequal structural index!" << std::endl;
					std::cout << "At index: " << x << std::endl;
					++mismatched_count;
				}
			}
			std::cout << "All " << jsonifier_context.indices.size() << " structurals match, for test: " << test_name << std::endl;

			if (mismatched_count == 0) {
				newer_string += "All **" + std::to_string(jsonifier_context.indices.size()) + "** structurals match between Jsonifier and Simdjson. ✅\n\n";
			} else {
				newer_string += "**" + std::to_string(mismatched_count) + "** of " + std::to_string(jsonifier_context.indices.size()) + " structurals mismatched. ❌\n\n";
			}
		}
	}

	void test_function() {
		bnch_swt::pin_for_benchmark();
		std::string newer_string{ make_section00(static_cast<std::string>(bnch_swt::system_info_data<bnch_swt::benchmark_types::cpu>::os_id),
									  static_cast<std::string>(bnch_swt::system_info_data<bnch_swt::benchmark_types::cpu>::os_version),
									  static_cast<std::string>(bnch_swt::system_info_data<bnch_swt::benchmark_types::cpu>::compiler_id),
									  static_cast<std::string>(bnch_swt::system_info_data<bnch_swt::benchmark_types::cpu>::compiler_version)) +
			bnch_swt::get_time() + ")\n" + make_section01() + static_cast<std::string>(make_section02(bnch_swt::internal::get_device_info<bnch_swt::benchmark_types::cpu>())) };
		execute_test<test_types::parse, abc_out_of_order_test<abc_out_of_order_test_struct>, "Abc (Out of Order) Test (Minified)", false,
			library_traits<test_types::parse, json_libraries::jsonifier, "Abc (Out of Order) Test (Minified)", true, abc_out_of_order_test<abc_out_of_order_test_struct>>,
			library_traits<test_types::parse, json_libraries::simdjson, "Abc (Out of Order) Test (Minified)", true, abc_out_of_order_test<abc_out_of_order_test_struct>>>(
			newer_string);
		execute_test<test_types::parse, abc_out_of_order_test<abc_out_of_order_test_struct>, "Abc (Out of Order) Test (Prettified)", false,
			library_traits<test_types::parse, json_libraries::jsonifier, "Abc (Out of Order) Test (Prettified)", false, abc_out_of_order_test<abc_out_of_order_test_struct>>,
			library_traits<test_types::parse, json_libraries::simdjson, "Abc (Out of Order) Test (Prettified)", false, abc_out_of_order_test<abc_out_of_order_test_struct>>>(
			newer_string);
		execute_test<test_types::parse, abc_in_order_partial_test<abc_in_order_partial_test_struct>, "Abc (In Order) Partial Test (Minified)", false,
			library_traits<test_types::parse, json_libraries::jsonifier, "Abc (In Order) Partial Test (Minified)", true,
				abc_in_order_partial_test<abc_in_order_partial_test_struct>>,
			library_traits<test_types::parse, json_libraries::simdjson, "Abc (In Order) Partial Test (Minified)", true,
				abc_in_order_partial_test<abc_in_order_partial_test_struct>>>(newer_string);
		execute_test<test_types::parse, abc_in_order_partial_test<abc_in_order_partial_test_struct>, "Abc (In Order) Partial Test (Prettified)", false,
			library_traits<test_types::parse, json_libraries::jsonifier, "Abc (In Order) Partial Test (Prettified)", false,
				abc_in_order_partial_test<abc_in_order_partial_test_struct>>,
			library_traits<test_types::parse, json_libraries::simdjson, "Abc (In Order) Partial Test (Prettified)", false,
				abc_in_order_partial_test<abc_in_order_partial_test_struct>>>(newer_string);
		execute_test<test_types::parse, apache_builds_message, "Apache Builds Test (Minified)", false,
			library_traits<test_types::parse, json_libraries::jsonifier, "Apache Builds Test (Minified)", true, apache_builds_message>,
			library_traits<test_types::parse, json_libraries::simdjson, "Apache Builds Test (Minified)", true, apache_builds_message>>(newer_string);
		execute_test<test_types::parse, apache_builds_message, "Apache Builds Test (Prettified)", false,
			library_traits<test_types::parse, json_libraries::jsonifier, "Apache Builds Test (Prettified)", false, apache_builds_message>,
			library_traits<test_types::parse, json_libraries::simdjson, "Apache Builds Test (Prettified)", false, apache_builds_message>>(newer_string);
		execute_test<test_types::parse, canada_message, "Canada Test (Minified)", false,
			library_traits<test_types::parse, json_libraries::jsonifier, "Canada Test (Minified)", true, canada_message>,
			library_traits<test_types::parse, json_libraries::simdjson, "Canada Test (Minified)", true, canada_message>>(newer_string);
		execute_test<test_types::parse, canada_message, "Canada Test (Prettified)", false,
			library_traits<test_types::parse, json_libraries::jsonifier, "Canada Test (Prettified)", false, canada_message>,
			library_traits<test_types::parse, json_libraries::simdjson, "Canada Test (Prettified)", false, canada_message>>(newer_string);
		execute_test<test_types::parse, citm_catalog_message, "CitmCatalog Test (Minified)", false,
			library_traits<test_types::parse, json_libraries::jsonifier, "CitmCatalog Test (Minified)", true, citm_catalog_message>,
			library_traits<test_types::parse, json_libraries::simdjson, "CitmCatalog Test (Minified)", true, citm_catalog_message>>(newer_string);
		execute_test<test_types::parse, citm_catalog_message, "CitmCatalog Test (Prettified)", false,
			library_traits<test_types::parse, json_libraries::jsonifier, "CitmCatalog Test (Prettified)", false, citm_catalog_message>,
			library_traits<test_types::parse, json_libraries::simdjson, "CitmCatalog Test (Prettified)", false, citm_catalog_message>>(newer_string);
		execute_test<test_types::parse, discord_message, "Discord Test (Minified)", false,
			library_traits<test_types::parse, json_libraries::jsonifier, "Discord Test (Minified)", true, discord_message>,
			library_traits<test_types::parse, json_libraries::simdjson, "Discord Test (Minified)", true, discord_message>>(newer_string);
		execute_test<test_types::parse, discord_message, "Discord Test (Prettified)", false,
			library_traits<test_types::parse, json_libraries::jsonifier, "Discord Test (Prettified)", false, discord_message>,
			library_traits<test_types::parse, json_libraries::simdjson, "Discord Test (Prettified)", false, discord_message>>(newer_string);
		execute_test<test_types::parse, github_events_message, "Github Events Test (Minified)", false,
			library_traits<test_types::parse, json_libraries::jsonifier, "Github Events Test (Minified)", true, github_events_message>,
			library_traits<test_types::parse, json_libraries::simdjson, "Github Events Test (Minified)", true, github_events_message>>(newer_string);
		execute_test<test_types::parse, github_events_message, "Github Events Test (Prettified)", false,
			library_traits<test_types::parse, json_libraries::jsonifier, "Github Events Test (Prettified)", false, github_events_message>,
			library_traits<test_types::parse, json_libraries::simdjson, "Github Events Test (Prettified)", false, github_events_message>>(newer_string);
		execute_test<test_types::parse, google_maps_response_message, "Google Maps Response Test (Minified)", false,
			library_traits<test_types::parse, json_libraries::jsonifier, "Google Maps Response Test (Minified)", true, google_maps_response_message>,
			library_traits<test_types::parse, json_libraries::simdjson, "Google Maps Response Test (Minified)", true, google_maps_response_message>>(newer_string);
		execute_test<test_types::parse, google_maps_response_message, "Google Maps Response Test (Prettified)", false,
			library_traits<test_types::parse, json_libraries::jsonifier, "Google Maps Response Test (Prettified)", false, google_maps_response_message>,
			library_traits<test_types::parse, json_libraries::simdjson, "Google Maps Response Test (Prettified)", false, google_maps_response_message>>(newer_string);
		execute_test<test_types::parse, instruments_message, "Instruments Test (Minified)", false,
			library_traits<test_types::parse, json_libraries::jsonifier, "Instruments Test (Minified)", true, instruments_message>,
			library_traits<test_types::parse, json_libraries::simdjson, "Instruments Test (Minified)", true, instruments_message>>(newer_string);
		execute_test<test_types::parse, instruments_message, "Instruments Test (Prettified)", false,
			library_traits<test_types::parse, json_libraries::jsonifier, "Instruments Test (Prettified)", false, instruments_message>,
			library_traits<test_types::parse, json_libraries::simdjson, "Instruments Test (Prettified)", false, instruments_message>>(newer_string);
		execute_test<test_types::parse, marine_ik, "Marine IK Test (Minified)", false,
			library_traits<test_types::parse, json_libraries::jsonifier, "Marine IK Test (Minified)", true, marine_ik>,
			library_traits<test_types::parse, json_libraries::simdjson, "Marine IK Test (Minified)", true, marine_ik>>(newer_string);
		execute_test<test_types::parse, marine_ik, "Marine IK Test (Prettified)", false,
			library_traits<test_types::parse, json_libraries::jsonifier, "Marine IK Test (Prettified)", false, marine_ik>,
			library_traits<test_types::parse, json_libraries::simdjson, "Marine IK Test (Prettified)", false, marine_ik>>(newer_string);
		execute_test<test_types::parse, mesh_message, "Mesh Test (Minified)", false,
			library_traits<test_types::parse, json_libraries::jsonifier, "Mesh Test (Minified)", true, mesh_message>,
			library_traits<test_types::parse, json_libraries::simdjson, "Mesh Test (Minified)", true, mesh_message>>(newer_string);
		execute_test<test_types::parse, mesh_message, "Mesh Test (Prettified)", false,
			library_traits<test_types::parse, json_libraries::jsonifier, "Mesh Test (Prettified)", false, mesh_message>,
			library_traits<test_types::parse, json_libraries::simdjson, "Mesh Test (Prettified)", false, mesh_message>>(newer_string);
		execute_test<test_types::parse, random_message, "Random Test (Minified)", false,
			library_traits<test_types::parse, json_libraries::jsonifier, "Random Test (Minified)", true, random_message>,
			library_traits<test_types::parse, json_libraries::simdjson, "Random Test (Minified)", true, random_message>>(newer_string);
		execute_test<test_types::parse, random_message, "Random Test (Prettified)", false,
			library_traits<test_types::parse, json_libraries::jsonifier, "Random Test (Prettified)", false, random_message>,
			library_traits<test_types::parse, json_libraries::simdjson, "Random Test (Prettified)", false, random_message>>(newer_string);
		execute_test<test_types::parse, twitter_partial_message, "Twitter Partial Test (Minified)", false,
			library_traits<test_types::parse, json_libraries::jsonifier, "Twitter Partial Test (Minified)", true, twitter_partial_message>,
			library_traits<test_types::parse, json_libraries::simdjson, "Twitter Partial Test (Minified)", true, twitter_partial_message>>(newer_string);
		execute_test<test_types::parse, twitter_partial_message, "Twitter Partial Test (Prettified)", false,
			library_traits<test_types::parse, json_libraries::jsonifier, "Twitter Partial Test (Prettified)", false, twitter_partial_message>,
			library_traits<test_types::parse, json_libraries::simdjson, "Twitter Partial Test (Prettified)", false, twitter_partial_message>>(newer_string);
		execute_test<test_types::parse, twitter_message, "Twitter Test (Minified)", false,
			library_traits<test_types::parse, json_libraries::jsonifier, "Twitter Test (Minified)", true, twitter_message>,
			library_traits<test_types::parse, json_libraries::simdjson, "Twitter Test (Minified)", true, twitter_message>>(newer_string);
		execute_test<test_types::parse, twitter_message, "Twitter Test (Prettified)", false,
			library_traits<test_types::parse, json_libraries::jsonifier, "Twitter Test (Prettified)", false, twitter_message>,
			library_traits<test_types::parse, json_libraries::simdjson, "Twitter Test (Prettified)", false, twitter_message>>(newer_string);
		bnch_swt::file_handle::save_file(static_cast<std::string>(newer_string), read_me_path.operator std::string() + "/" + current_path + ".md");
		auto stage_results = benchmark_stage::get_all_results();
		std::cout << "Md Data: " << newer_string << std::endl;
		bnch_swt::execute_python_script(base_path.operator std::string() + "/GenerateGraphs.py", csv_out_path + "/", graphs_path);
	}
}