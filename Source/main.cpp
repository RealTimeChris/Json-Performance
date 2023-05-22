#if defined(JSONIFIER_CPU_INSTRUCTIONS)
//#undef JSONIFIER_CPU_INSTRUCTIONS
//#define JSONIFIER_CPU_INSTRUCTIONS (JSONIFIER_AVX2F | JSONIFIER_POPCNT | JSONIFIER_BMI | JSONIFIER_BMI2 | JSONIFIER_LZCNT)
#endif
#include "glaze/core/macros.hpp"
#include "glaze/glaze.hpp"
#include <jsonifier/Index.hpp>
#include <unordered_set>
#include <unordered_map>
#include "fmt/format.h"
#include <iostream>
#include <chrono>

constexpr static std::string_view discordData{
	"{\"t\":\"INTERACTION_CREATE\",\"s\":2078,\"op\":0,\"d\":{\"version\":1,\"type\":2,\"token\":[\" "
	"\\\"v,P@%L@H'\\bD\\n7[*qx*SJOG7x\\n&z?bCv\\b.\\\\9tq@[\\nYT.k6N`#\\fDZ\\bsJ/]e[FV&Ijav8{\\b/Mr!GP;$8PjvO)1cnFcq@%,^#hv;"
	">PYWSExp%=q.r9[r*|7He:Vcop$IRJu8c=&/el<|cQ|8kWE\\r@-Xu1\\b1NvY}\\n\\n`k=R`&8$N>Y4^oYQK\",\"d9ATBjrgqUiS6WJY@rR!kwq,Wm!/"
	",ot^\\nD'r)\\ntoB\\n&DRBMX_9TG\\rA<#6J@:$UNCSFa70q`%N6c.5IO3Z6Zis]pp/"
	"Z[\\b\\th]uC#p!5[\",\"(YgF(<D8{'0*M]8w''o$\\r{JuA!(.En\\\\R0J,9sgXFYB&lYIkBr\\nLarlqqJ0*@tNOA\\r[i<5.)m\\\\i=ECNG-b(k6p.nW+o2Bdn<b)v\"],"
	"\"member\":{\"user\":{\"username\":"
	"\"realtimechris\",\"public_flags\":0,\"id\":\"1030016136735100928\",\"global_name\":"
	"\"RealTimeChris\",\"discriminator\":\"0\",\"avatar_decoration_data\":null,\"avatar\":"
	"\"b5c11f6d27856436516ba250ef75977f\"},\"unusual_dm_activity_until\":null,\"roles\":["
	"4664426095629615104,9223372036854775808,9223372036854775808,9223372036854775808,2179174894194894080,"
	"3165323897209039360,1916602413940795904,1468567084515272960,9223372036854775808,3334121945094048256,9223372036854775808,"
	"3634686788879607296,3392015987855483392,205396450570152096,8294940615951355904,2410989935144898560,8043365604935430144,"
	"9223372036854775808,47672232262572224,5295565794863068160,3852374721831996928,"
	"995050810528501822],\"premium_since\":\"2023-09-02T06:36:51.214000+00:00\","
	"\"permissions\":\"562949953421311\",\"pending\":false,\"nick\":null,\"mute\":false,\"joined_"
	"at\":\"2022-10-13T07:24:59.734000+00:00\",\"flags\":0,\"deaf\":false,"
	"\"communication_disabled_until\":null,\"avatar\":null},\"locale\":\"en-US\",\"id\":"
	"\"1179713081920725002\",\"guild_locale\":\"en-US\",\"guild_id\":\"995048955215872071\","
	"\"guild\":{\"locale\":\"en-US\",\"id\":\"995048955215872071\",\"features\":[\"WELCOME_SCREEN_"
	"ENABLED\",\"NEWS\",\"BANNER\",\"THREE_DAY_THREAD_ARCHIVE\",\"SEVEN_DAY_THREAD_"
	"ARCHIVE\",\"VANITY_URL\",\"PRIVATE_THREADS\",\"INVITE_SPLASH\",\"MEMBER_PROFILES\","
	"\"COMMUNITY\",\"ANIMATED_BANNER\",\"ROLE_ICONS\",\"CHANNEL_ICON_EMOJIS_GENERATED\","
	"\"SOUNDBOARD\",\"ANIMATED_ICON\"]},\"entitlements\":[],\"entitlement_sku_ids\":[9223372036854775808,6664918887253381120,10393978869238558720,"
	"9223372036854775808,"
	"1841881418182146048,561410972580061184,9223372036854775808,6760323491399155712,"
	"10563819230501087232,10379853849639598080,8811782156079407104,11073018613044467712,9753503112392478720,242727529154713600,5671998498556622848,"
	"9223372036854775808,"
	"9223372036854775808,14792852609746368512,1195159336870201344,8813256932130197504,9280915220474646528,7210143484375654400,"
	"16629716992355760128,9713191412130514944,9223372036854775808,266982017658744832,13628756322552190976,9223372036854775808,10397695426574008320,"
	"9223372036854775808,"
	"16490483600763133952,16252332298412941312,13889781143355410432,"
	"3965796581387785216,14411686654392195072,9223372036854775808,11824049847355725824],\"data\":{"
	"\"type\":1,\"name\":\"botinfo\",\"id\":\"1142748249858523266\"},\"channel_id\":"
	"\"995056513456558150\",\"channel\":{\"type\":0,\"topic\":null,\"theme_color\":null,\"rate_"
	"limit_per_user\":0,\"position\":4,\"permissions\":\"562949953421311\",\"parent_id\":"
	"\"995048956235100240\",\"nsfw\":true,\"name\":\"casino\",\"last_pin_timestamp\":\"2023-11-"
	"29T17:37:03+00:00\",\"last_message_id\":\"1179476133528469586\",\"id\":"
	"\"995056513456558150\",\"icon_emoji\":{\"name\":\"≡ƒÄ▓\",\"id\":null},\"guild_id\":"
	"\"995048955215872071\",\"flags\":0},\"application_id\":\"1142733646600614004\",\"app_"
	"permissions\":\"562949953421311\"}}"
};

struct icon_emoji {
	std::string name;
	std::string id;
};

struct channel {
	int64_t type;
	std::string topic;
	std::string themeColor;
	int64_t rateLimitPerUser;
	int64_t position;
	std::string permissions;
	std::string parentId;
	bool nsfw;
	std::string name;
	std::string lastPinTimestamp;
	std::string lastMessageId;
	std::string id;
	icon_emoji iconEmoji;
	std::string guildId;
	int64_t flags;
};

struct data {
	int64_t type;
	std::string name;
	std::string id;
};

struct guild {
	std::string locale;
	std::string id;
	std::vector<std::string> features;
};

struct user {
	std::string username;
	int64_t publicFlags;
	std::string id;
	std::string globalName;
	std::string discriminator;
	std::string avatarDecorationData;
	std::string avatar;
};

struct member {
	user userVal;
	std::string unusualDmActivityUntil;
	std::vector<uint64_t> roles;
	std::string premiumSince;
	std::string permissions;
	bool pending;
	std::string nick;
	bool mute;
	std::string joinedAt;
	int64_t flags;
	bool deaf;
	std::string communicationDisabledUntil;
	std::string avatar;
};

struct d {
	int64_t version;
	int64_t type;
	std::vector<std::string> token;
	member memberVal;
	std::string locale;
	std::string id;
	std::string guildLocale;
	std::string guildId;
	guild guildVal;
	std::vector<std::string> entitlements;
	std::vector<uint64_t> entitlementSkuIds;
	data dataVal;
	std::string channelId;
	channel channelVal;
	std::string applicationId;
	std::string appPermissions;
};

struct welcome {
	std::string t;
	int64_t s;
	int64_t op;
	d dVal;
};

// Specialization for icon_emoji
template<> struct jsonifier::core<icon_emoji> {
	using OTy = icon_emoji;
	constexpr static auto parseValue = createValue("name", &OTy::name);
};

// Specialization for channel
template<> struct jsonifier::core<channel> {
	using OTy = channel;
	constexpr static auto parseValue =
		createValue("type", &OTy::type, "rate_limit_per_user", &OTy::rateLimitPerUser, "position", &OTy::position, "permissions", &OTy::permissions,
			"parent_id", &OTy::parentId, "nsfw", &OTy::nsfw, "name", &OTy::name, "last_pin_timestamp", &OTy::lastPinTimestamp, "last_message_id",
			&OTy::lastMessageId, "id", &OTy::id, "icon_emoji", &OTy::iconEmoji, "guild_id", &OTy::guildId, "flags", &OTy::flags);
};

// Specialization for data
template<> struct jsonifier::core<data> {
	using OTy = data;
	constexpr static auto parseValue = createValue("type", &OTy::type, "name", &OTy::name, "id", &OTy::id);
};

// Specialization for guild
template<> struct jsonifier::core<guild> {
	using OTy = guild;
	constexpr static auto parseValue = createValue("locale", &OTy::locale, "id", &OTy::id, "features", &OTy::features);
};

// Specialization for user
template<> struct jsonifier::core<user> {
	using OTy = user;
	constexpr static auto parseValue = createValue("username", &OTy::username, "public_flags", &OTy::publicFlags, "id", &OTy::id, "global_name",
		&OTy::globalName, "discriminator", &OTy::discriminator, "avatar", &OTy::avatar);
};

// Specialization for member
template<> struct jsonifier::core<member> {
	using OTy = member;
	constexpr static auto parseValue = createValue("user", &OTy::userVal, "roles", &OTy::roles, "premium_since", &OTy::premiumSince, "permissions",
		&OTy::permissions, "pending", &OTy::pending, "mute", &OTy::mute, "joined_at", &OTy::joinedAt, "flags", &OTy::flags, "deaf", &OTy::deaf);
};

// Specialization for d
template<> struct jsonifier::core<d> {
	using OTy = d;
	constexpr static auto parseValue = createValue("version", &OTy::version, "type", &OTy::type, "token", &OTy::token, "member", &OTy::memberVal,
		"locale", &OTy::locale, "id", &OTy::id, "guild_locale", &OTy::guildLocale, "guild_id", &OTy::guildId, "guild", &OTy::guildVal, "entitlements",
		&OTy::entitlements, "entitlement_sku_ids", &OTy::entitlementSkuIds, "data", &OTy::dataVal, "channel_id", &OTy::channelId, "channel",
		&OTy::channelVal, "application_id", &OTy::applicationId, "app_permissions", &OTy::appPermissions);
};

// Specialization for welcome
template<> struct jsonifier::core<welcome> {
	using OTy = welcome;
	constexpr static auto parseValue = createValue("t", &OTy::t, "s", &OTy::s, "op", &OTy::op, "d", &OTy::dVal);
};

// Specialization for icon_emoji
template<> struct glz::meta<icon_emoji> {
	using OTy = icon_emoji;
	constexpr static auto value = object("name", &OTy::name);
};

// Specialization for channel
template<> struct glz::meta<channel> {
	using OTy = channel;
	constexpr static auto value = object("type", &OTy::type, "rate_limit_per_user", &OTy::rateLimitPerUser, "position", &OTy::position, "permissions",
		&OTy::permissions, "parent_id", &OTy::parentId, "nsfw", &OTy::nsfw, "name", &OTy::name, "last_pin_timestamp", &OTy::lastPinTimestamp,
		"last_message_id", &OTy::lastMessageId, "id", &OTy::id, "icon_emoji", &OTy::iconEmoji, "guild_id", &OTy::guildId, "flags", &OTy::flags);
};

// Specialization for data
template<> struct glz::meta<data> {
	using OTy = data;
	constexpr static auto value = object("type", &OTy::type, "name", &OTy::name, "id", &OTy::id);
};

// Specialization for guild
template<> struct glz::meta<guild> {
	using OTy = guild;
	constexpr static auto value = object("locale", &OTy::locale, "id", &OTy::id, "features", &OTy::features);
};

// Specialization for user
template<> struct glz::meta<user> {
	using OTy = user;
	constexpr static auto value = object("username", &OTy::username, "public_flags", &OTy::publicFlags, "id", &OTy::id, "global_name",
		&OTy::globalName, "discriminator", &OTy::discriminator, "avatar", &OTy::avatar);
};

// Specialization for member
template<> struct glz::meta<member> {
	using OTy = member;
	constexpr static auto value = object("user", &OTy::userVal, "roles", &OTy::roles, "premium_since", &OTy::premiumSince, "permissions",
		&OTy::permissions, "pending", &OTy::pending, "mute", &OTy::mute, "joined_at", &OTy::joinedAt, "flags", &OTy::flags, "deaf", &OTy::deaf);
};

// Specialization for d
template<> struct glz::meta<d> {
	using OTy = d;
	constexpr static auto value = object("version", &OTy::version, "type", &OTy::type, "token", &OTy::token, "member", &OTy::memberVal, "locale",
		&OTy::locale, "id", &OTy::id, "guild_locale", &OTy::guildLocale, "guild_id", &OTy::guildId, "guild", &OTy::guildVal, "entitlements",
		&OTy::entitlements, "entitlement_sku_ids", &OTy::entitlementSkuIds, "data", &OTy::dataVal, "channel_id", &OTy::channelId, "channel",
		&OTy::channelVal, "application_id", &OTy::applicationId, "app_permissions", &OTy::appPermissions);
};

// Specialization for welcome
template<> struct glz::meta<welcome> {
	using OTy = welcome;
	constexpr static auto value = object("t", &OTy::t, "s", &OTy::s, "op", &OTy::op, "d", &OTy::dVal);
};


struct test_struct {
	jsonifier::vector<std::string> testStrings{};
	jsonifier::vector<uint64_t> testUints{};
	jsonifier::vector<double> testDoubles{};
	jsonifier::vector<int64_t> testInts{};
	jsonifier::vector<bool> testBools{};
};

struct json_data {
	std::string theData{};
	jsonifier::vector<int32_t> arraySizes{};
};

template<typename OTy> struct Test {
	jsonifier::vector<OTy> a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
};

template<typename OTy> struct TestGenerator {
	jsonifier::vector<OTy> a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;

	std::random_device randomEngine{};
	std::mt19937 gen{ randomEngine() };

	constexpr static std::string_view charset{
		"!#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[]^_`abcdefghijklmnopqrstuvwxyz{|}~\\\r\b\f\t\n"
	};

	template<typename value_type> value_type randomizeNumber(value_type mean, value_type stdDeviation) {
		std::normal_distribution<> normalDistributionTwo{ static_cast<double>(mean), static_cast<double>(stdDeviation) };
		auto theResult = normalDistributionTwo(randomEngine);
		if (theResult < 0) {
			theResult = -theResult;
		}
		return theResult;
	}

	JSONIFIER_INLINE static json_data generateJsonData() {
		std::string buffer{};
		TestGenerator generator{};
		jsonifier::jsonifier_core parser{};
		parser.serializeJson(generator, buffer);
		//std::cout << "SERIALIZED JSON: " << buffer << std::endl;
		json_data returnData{};
		returnData.theData = buffer;
		return returnData;
	}

	std::string generateString() {
		auto length{ randomizeNumber(45.0f, 25.0f) };
		static int32_t charsetSize = charset.size();
		std::mt19937 generator(std::random_device{}());
		std::uniform_int_distribution<int32_t> distribution(0, charsetSize - 1);
		std::string result{};
		for (int32_t x = 0; x < length; ++x) {
			result += charset[distribution(generator)];
		}
		return result;
	}

	double generateDouble() {
		auto newValue = randomizeNumber(double{}, std::numeric_limits<double>::max() / 50000000);
		return generateBool() ? newValue : -newValue;
	};

	bool generateBool() {
		return static_cast<bool>(randomizeNumber(50.0f, 50.0f) >= 50.0f);
	};

	uint64_t generateUint() {
		return randomizeNumber(std::numeric_limits<uint64_t>::max() / 2, std::numeric_limits<uint64_t>::max() / 2);
	};

	int64_t generateInt() {
		auto newValue = randomizeNumber(int64_t{}, std::numeric_limits<int64_t>::max());
		return generateBool() ? newValue : -newValue;
	};

	TestGenerator() {
		auto fill = [&](auto& v) {
			auto arraySize01 = randomizeNumber(35, 15);
			v.resize(arraySize01);
			for (uint64_t x = 0; x < arraySize01; ++x) {
				auto arraySize01 = randomizeNumber(20, 10);
				for (uint64_t y = 0; y < arraySize01; ++y) {
					auto newString = generateString();
					v[x].testStrings.emplace_back(newString);
				}
				arraySize01 = randomizeNumber(20, 10);
				for (uint64_t y = 0; y < arraySize01; ++y) {
					v[x].testUints.emplace_back(generateUint());
				}
				arraySize01 = randomizeNumber(20, 10);
				for (uint64_t y = 0; y < arraySize01; ++y) {
					v[x].testInts.emplace_back(generateInt());
				}
				arraySize01 = randomizeNumber(20, 10);
				for (uint64_t y = 0; y < arraySize01; ++y) {
					v[x].testBools.emplace_back(generateBool());
				}
				arraySize01 = randomizeNumber(20, 10);
				for (uint64_t y = 0; y < arraySize01; ++y) {
					v[x].testDoubles.emplace_back(generateDouble());
				}
			}
		};

		fill(a);
		fill(b);
		fill(c);
		fill(d);
		fill(e);
		fill(f);
		fill(g);
		fill(h);
		fill(i);
		fill(j);
		fill(k);
		fill(l);
		fill(m);
		fill(n);
		fill(o);
		fill(p);
		fill(q);
		fill(r);
		fill(s);
		fill(t);
		fill(u);
		fill(v);
		fill(w);
		fill(x);
		fill(y);
		fill(z);
	}
};

GLZ_META(test_struct, testBools, testInts, testUints, testDoubles, testStrings);
GLZ_META(Test<test_struct>, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z);
GLZ_META(TestGenerator<test_struct>, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z);
template<typename OTy> struct AbcTest {
	jsonifier::vector<OTy> z, y, x, w, v, u, t, s, r, q, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a;
};

template<> struct jsonifier::core<test_struct> {
	using OTy = test_struct;
	constexpr static auto parseValue = createValue("testBools", &OTy::testBools, "testInts", &OTy::testInts, "testUints", &OTy::testUints,
		"testDoubles", &OTy::testDoubles, "testStrings", &OTy::testStrings);
};

template<> struct jsonifier::core<Test<test_struct>> {
	using OTy = Test<test_struct>;
	constexpr static auto parseValue = createValue("a", &OTy::a, "b", &OTy::b, "c", &OTy::c, "d", &OTy::d, "e", &OTy::e, "f", &OTy::f, "g", &OTy::g,
		"h", &OTy::h, "i", &OTy::i, "j", &OTy::j, "k", &OTy::k, "l", &OTy::l, "m", &OTy::m, "n", &OTy::n, "o", &OTy::o, "p", &OTy::p, "q", &OTy::q,
		"r", &OTy::r, "s", &OTy::s, "t", &OTy::t, "u", &OTy::u, "v", &OTy::v, "w", &OTy::w, "x", &OTy::x, "y", &OTy::y, "z", &OTy::z);
};


template<> struct jsonifier::core<TestGenerator<test_struct>> {
	using OTy = TestGenerator<test_struct>;
	constexpr static auto parseValue = createValue("a", &OTy::a, "b", &OTy::b, "c", &OTy::c, "d", &OTy::d, "e", &OTy::e, "f", &OTy::f, "g", &OTy::g,
		"h", &OTy::h, "i", &OTy::i, "j", &OTy::j, "k", &OTy::k, "l", &OTy::l, "m", &OTy::m, "n", &OTy::n, "o", &OTy::o, "p", &OTy::p, "q", &OTy::q,
		"r", &OTy::r, "s", &OTy::s, "t", &OTy::t, "u", &OTy::u, "v", &OTy::v, "w", &OTy::w, "x", &OTy::x, "y", &OTy::y, "z", &OTy::z);
};

template<> struct jsonifier::core<AbcTest<test_struct>> {
	using OTy = AbcTest<test_struct>;
	constexpr static auto parseValue = createValue("z", &OTy::z, "y", &OTy::y, "x", &OTy::x, "w", &OTy::w, "v", &OTy::v, "u", &OTy::u, "t", &OTy::t,
		"s", &OTy::s, "r", &OTy::r, "q", &OTy::q, "p", &OTy::p, "o", &OTy::o, "n", &OTy::n, "m", &OTy::m, "l", &OTy::l, "k", &OTy::k, "j", &OTy::j,
		"i", &OTy::i, "h", &OTy::h, "g", &OTy::g, "f", &OTy::f, "e", &OTy::e, "d", &OTy::d, "c", &OTy::c, "b", &OTy::b, "a", &OTy::a);
};

GLZ_META(AbcTest<test_struct>, z, y, x, w, v, u, t, s, r, q, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a);

#if defined(NDEBUG)
constexpr uint64_t iterations = 100;
#else
constexpr uint64_t iterations = 1;
#endif

struct results {
	std::string name{};
	std::string test{};
	std::string url{};
	uint64_t iterations{};

	std::optional<uint64_t> json_write_byte_length{};
	std::optional<uint64_t> json_read_byte_length{};
	std::optional<double> json_read{};
	std::optional<double> json_write{};

	void print() {
		std::cout << std::string{ "| " } + name + " " + test + ": " + url + "\n" +
				"| ------------------------------------------------------------ "
				"|\n";

		if (json_read_byte_length && json_read) {
			auto mbReadCount = static_cast<double>(*json_read_byte_length) / 1e+6l;
			auto readSecondCount = *json_read / 1e+9l;
			std::cout << "Read Length: " << *json_read_byte_length << std::endl;
			std::cout << "Read: " << mbReadCount / readSecondCount << " MB/s\n";
		}
		if (json_write_byte_length && json_write) {
			auto mbWrittenCount = static_cast<double>(*json_write_byte_length) / 1e+6l;
			auto writeSecondCount = *json_write / 1e+9l;
			std::cout << "Write Length: " << *json_write_byte_length << std::endl;
			std::cout << "Write: " << mbWrittenCount / writeSecondCount << " MB/s\n";
		}

		std::cout << "\n---" << std::endl;
	}

	std::string json_stats() {
		std::string write{};
		std::string read{};
		std::string finalstring{};
		if (json_read && json_read_byte_length) {
			auto mbReadCount = static_cast<double>(*json_read_byte_length) / 1e+6l;
			auto readSecondCount = *json_read / 1e+9l;
			read = fmt::format("{:.2f}", mbReadCount / readSecondCount);
		}
		if (json_write && json_write_byte_length) {
			auto mbWrittenCount = static_cast<double>(*json_write_byte_length) / 1e+6l;
			double writeSecondCount = *json_write / 1e+9l;
			write = fmt::format("{:.2f}", mbWrittenCount / writeSecondCount);
		} else {
			write = "N/A";
		}

		finalstring = fmt::format("| [**{}**]({}) | **{}** | **{}** |", name, url, write, read);
		return finalstring;
	}
};

class FileLoader {
  public:
	FileLoader(const char* filePathNew) {
		filePath = filePathNew;
		auto theStream = std::ofstream{ filePath.data(), std::ios::binary | std::ios::out | std::ios::in };
		std::stringstream inputStream{};
		inputStream << theStream.rdbuf();
		fileContents = inputStream.str();
		theStream.close();
	}

	void saveFile(const std::string& fileToSave) {
		auto theStream = std::ofstream{ filePath.data(), std::ios::binary | std::ios::out | std::ios::in | std::ios::trunc };
		theStream << "";
		theStream.write(fileToSave.data(), fileToSave.size());
		theStream.close();
	}

	operator std::string() {
		return fileContents;
	}

	~FileLoader() {
	}

  protected:
	std::string fileContents{};
	std::string filePath{};
};



template<typename Function> auto benchmark(Function function, int64_t iterationCount) {
	std::chrono::duration<double, std::nano> currentLowestTime{ std::numeric_limits<double>::max() };
	for (int64_t x = 0; x < iterationCount; ++x) {
		auto startTime = std::chrono::high_resolution_clock::now();
		function();
		auto endTime = std::chrono::high_resolution_clock::now();
		auto newTime = std::chrono::duration_cast<std::chrono::duration<double, std::nano>>(endTime - startTime);
		if (newTime < currentLowestTime) {
			currentLowestTime = newTime;
		}
	}
	return currentLowestTime;
}

auto jsonifier_single_test(const std::string& bufferNew, bool doWePrint = true) {
	std::string buffer{ bufferNew };

	results r{ "jsonifier", "Single Test", "https://github.com/realtimechris/jsonifier", 1 };
	Test<test_struct> uint64Test{};
	jsonifier::jsonifier_core parser{};
	auto result = benchmark(
		[&]() {
			parser.parseJson(uint64Test, buffer);
		},
		1);
	for (auto& value: parser.getErrors()) {
		std::cout << "Jsonifier Error: " << value << std::endl;
	}
	r.json_read_byte_length = buffer.size();
	r.json_read = result.count();
	buffer.clear();

	result = benchmark(
		[&]() {
			parser.serializeJson(uint64Test, buffer);
		},
		1);
	r.json_write_byte_length = buffer.size();
	for (auto& value: uint64Test.a) {
		for (auto& value02: value.testStrings) {
			//std::cout << "VALUE: " << value02 << std::endl;
		}
	}
	//std::cout << "BUFFER (JSONIFIER): " << buffer << std::endl;
	for (auto& value: parser.getErrors()) {
		std::cout << "Jsonifier Error: " << value << std::endl;
	}
	r.json_write = result.count();
	buffer.clear();
	if (doWePrint) {
		r.print();
	}

	return r;
}

auto jsonifier_test(const std::string& bufferNew, bool doWePrint = true) {
	std::string buffer{ bufferNew };

	results r{ "jsonifier", "Multi Test", "https://github.com/realtimechris/jsonifier", iterations };
	Test<test_struct> uint64Test{};
	jsonifier::jsonifier_core parser{};

	auto result = benchmark(
		[&]() {
			parser.parseJson(uint64Test, buffer);
		},
		iterations);
	for (auto& value: parser.getErrors()) {
		std::cout << "Jsonifier Error: " << value << std::endl;
	}

	r.json_read = result.count();
	r.json_read_byte_length = buffer.size();
	buffer.clear();

	result = benchmark(
		[&]() {
			parser.serializeJson(uint64Test, buffer);
		},
		iterations);
	r.json_write_byte_length = buffer.size();
	for (auto& value: parser.getErrors()) {
		std::cout << "Jsonifier Error: " << value << std::endl;
	}
	r.json_write = result.count();
	buffer.clear();
	if (doWePrint) {
		r.print();
	}

	return r;
}

auto jsonifier_abc_test(const std::string& bufferNew, bool doWePrint = true) {
	std::string buffer{ bufferNew };

	results r{ "jsonifier", "Abc Test", "https://github.com/realtimechris/jsonifier", iterations };
	AbcTest<test_struct> uint64Test{};
	jsonifier::jsonifier_core parser{};

	auto result = benchmark(
		[&]() {
			parser.parseJson(uint64Test, buffer);
		},
		iterations);
	for (auto& value: parser.getErrors()) {
		std::cout << "Jsonifier Error: " << value << std::endl;
	}

	r.json_read = result.count();

	r.json_read_byte_length = buffer.size();
	buffer.clear();

	result = benchmark(
		[&]() {
			parser.serializeJson(uint64Test, buffer);
		},
		iterations);
	r.json_write_byte_length = buffer.size();
	for (auto& value: parser.getErrors()) {
		std::cout << "Jsonifier Error: " << value << std::endl;
	}
	r.json_write = result.count();
	buffer.clear();
	if (doWePrint) {
		r.print();
	}

	return r;
}

auto jsonifier_discord_test(bool doWePrint = true) {
	std::string buffer{ discordData };
	auto newSize = buffer.size();

	results r{ "jsonifier", "Discord Test", "https://github.com/realtimechris/jsonifier", iterations };
	welcome discordDataTest{};
	jsonifier::jsonifier_core parser{};

	auto result = benchmark(
		[&]() {
			parser.parseJson(discordDataTest, buffer);
		},
		iterations);
	for (auto& value: parser.getErrors()) {
		std::cout << "Jsonifier Error: " << value << std::endl;
	}

	r.json_read = result.count();

	r.json_read_byte_length = buffer.size();
	buffer.clear();

	result = benchmark(
		[&]() {
			parser.serializeJson(discordDataTest, buffer);
		},
		iterations);
	r.json_write_byte_length = buffer.size();
	for (auto& value: parser.getErrors()) {
		std::cout << "Jsonifier Error: " << value << std::endl;
	}
	r.json_write = result.count();
	buffer.clear();
	if (doWePrint) {
		r.print();
	}

	return r;
}

auto glaze_single_test(const std::string bufferNew, bool doWePrint = true) {
	std::string buffer{ bufferNew };

	results r{ "glaze", "Single Test", "https://github.com/stephenberry/glaze", 1 };
	Test<test_struct> uint64Test{};

	auto result = benchmark(
		[&]() {
			if (auto error = glz::read<glz::opts{ .error_on_unknown_keys = false }>(uint64Test, buffer); error) {
				std::cout << "glaze Error: " << glz::format_error(error, buffer) << std::endl;
			}
		},
		1);

	r.json_read = result.count();
	r.json_read_byte_length = buffer.size();
	buffer.clear();

	result = benchmark(
		[&]() {
			glz::write_json(uint64Test, buffer);
		},
		1);
	//std::cout << "BUFFER (JSONIFIER): " << buffer << std::endl;
	r.json_write_byte_length = buffer.size();
	r.json_write = result.count();
	buffer.clear();
	if (doWePrint) {
		r.print();
	}

	return r;
}

auto glaze_test(const std::string bufferNew, bool doWePrint = true) {
	std::string buffer{ bufferNew };

	results r{ "glaze", "Multi Test", "https://github.com/stephenberry/glaze", iterations };
	Test<test_struct> uint64Test{};

	auto result = benchmark(
		[&]() {
			if (auto error = glz::read<glz::opts{ .error_on_unknown_keys = false }>(uint64Test, buffer); error) {
				std::cout << "glaze Error: " << glz::format_error(error, buffer) << std::endl;
			}
		},
		iterations);

	r.json_read = result.count();

	r.json_read_byte_length = buffer.size();
	buffer.clear();

	result = benchmark(
		[&]() {
			glz::write_json(uint64Test, buffer);
		},
		iterations);
	r.json_write_byte_length = buffer.size();
	r.json_write = result.count();
	buffer.clear();
	if (doWePrint) {
		r.print();
	}

	return r;
}

auto glaze_abc_test(const std::string bufferNew, bool doWePrint = true) {
	std::string buffer{ bufferNew };

	results r{ "glaze", "Abc Test", "https://github.com/stephenberry/glaze", iterations };
	AbcTest<test_struct> uint64Test{};

	auto result = benchmark(
		[&]() {
			if (auto error = glz::read<glz::opts{ .error_on_unknown_keys = false }>(uint64Test, buffer); error) {
				std::cout << "glaze Error: " << glz::format_error(error, buffer) << std::endl;
			}
		},
		iterations);

	r.json_read = result.count();

	r.json_read_byte_length = buffer.size();
	buffer.clear();

	result = benchmark(
		[&]() {
			glz::write_json(uint64Test, buffer);
		},
		iterations);
	r.json_write_byte_length = buffer.size();
	r.json_write = result.count();
	buffer.clear();
	if (doWePrint) {
		r.print();
	}

	return r;
}

auto glaze_discord_test(bool doWePrint = true) {
	std::string buffer{ discordData };

	results r{ "glaze", "Discord Test", "https://github.com/stephenberry/glaze", iterations };
	welcome discordDataTest{};

	auto result = benchmark(
		[&]() {
			if (auto error = glz::read<glz::opts{ .error_on_unknown_keys = false }>(discordDataTest, buffer); error) {
				std::cout << "glaze Error: " << glz::format_error(error, buffer) << std::endl;
			}
		},
		iterations);

	r.json_read = result.count();

	r.json_read_byte_length = buffer.size();
	buffer.clear();

	result = benchmark(
		[&]() {
			glz::write_json(discordDataTest, buffer);
		},
		iterations);
	r.json_write_byte_length = buffer.size();
	r.json_write = result.count();
	buffer.clear();
	if (doWePrint) {
		r.print();
	}
	return r;
}

#include "simdjson.h"

using namespace simdjson;

struct on_demand {
	bool read_in_order(Test<test_struct>& obj, const padded_string& json);

  protected:
	ondemand::parser parser{};
};

template<typename OTy2> void simdPullArray(ondemand::array newX, jsonifier::vector<OTy2>& newVector);

void simdPullMap(ondemand::object newX, std::unordered_map<std::string, std::string>& newVector) {
	for (auto iter = newX.begin(); iter != newX.end(); ++iter) {
		newVector.emplace(static_cast<std::string>(iter.operator*().key().value().raw()),
			static_cast<std::string>(iter.operator*().value().get_string().value()));
	}
}

template<> void simdPullArray<double>(ondemand::array newX, jsonifier::vector<double>& newVector) {
	for (ondemand::value value: newX) {
		double newValue{};
		if (!value.get_double().get(newValue)) {
			newVector.emplace_back(newValue);
		}
	}
}

template<> void simdPullArray<int64_t>(ondemand::array newX, jsonifier::vector<int64_t>& newVector) {
	for (ondemand::value value: newX) {
		int64_t newValue{};
		if (!value.get_int64().get(newValue)) {
			newVector.emplace_back(newValue);
		}
	}
}

template<> void simdPullArray<uint64_t>(ondemand::array newX, jsonifier::vector<uint64_t>& newVector) {
	for (ondemand::value value: newX) {
		uint64_t newValue{};
		if (!value.get_uint64().get(newValue)) {
			newVector.emplace_back(newValue);
		}
	}
}

template<> void simdPullArray<bool>(ondemand::array newX, jsonifier::vector<bool>& newVector) {
	for (ondemand::value value: newX) {
		bool newValue{};
		if (!value.get_bool().get(newValue)) {
			newVector.emplace_back(newValue);
		}
	}
}

template<> void simdPullArray<std::string>(ondemand::array newX, jsonifier::vector<std::string>& newVector) {
	for (ondemand::value value: newX) {
		std::string_view newValue{};
		if (!value.get_string().get(newValue)) {
			newVector.emplace_back(newValue);
		}
	}
}

#define SIMD_Pull(x) \
	{ \
		ondemand::array newX = doc[#x].get_array().value(); \
		ondemand::array newArray{}; \
		ondemand::object newObject{}; \
		for (ondemand::value value: newX) { \
			test_struct newStruct{}; \
			newObject = value.get_object(); \
			newArray = newObject["testInts"].get_array().value(); \
			simdPullArray(newArray, newStruct.testInts); \
			newArray = newObject["testDoubles"].get_array().value(); \
			simdPullArray(newArray, newStruct.testDoubles); \
			newArray = newObject["testStrings"].get_array().value(); \
			simdPullArray(newArray, newStruct.testStrings); \
			newArray = newObject["testUints"].get_array().value(); \
			simdPullArray(newArray, newStruct.testUints); \
			newArray = newObject["testBools"].get_array().value(); \
			simdPullArray(newArray, newStruct.testBools); \
			obj.x.emplace_back(std::move(newStruct)); \
		} \
	}

bool on_demand::read_in_order(Test<test_struct>& obj, const padded_string& json) {
	ondemand::document doc = parser.iterate(json).value();
	SIMD_Pull(a);
	SIMD_Pull(b);
	SIMD_Pull(c);
	SIMD_Pull(d);
	SIMD_Pull(e);
	SIMD_Pull(f);
	SIMD_Pull(g);
	SIMD_Pull(h);
	SIMD_Pull(i);
	SIMD_Pull(j);
	SIMD_Pull(k);
	SIMD_Pull(l);
	SIMD_Pull(m);
	SIMD_Pull(n);
	SIMD_Pull(o);
	SIMD_Pull(p);
	SIMD_Pull(q);
	SIMD_Pull(r);
	SIMD_Pull(s);
	SIMD_Pull(t);
	SIMD_Pull(u);
	SIMD_Pull(v);
	SIMD_Pull(w);
	SIMD_Pull(x);
	SIMD_Pull(y);
	SIMD_Pull(z);
	return false;
}

auto simdjson_single_test(const std::string& bufferNew, bool doWePrint = true) {
	std::string buffer{ bufferNew };
	on_demand parser{};

	results r{ "simdjson", "Single Test", "https://github.com/simdjson/simdjson", 1 };
	Test<test_struct> uint64Test{};

	r.json_read_byte_length = buffer.size();
	auto result = benchmark(
		[&]() {
			parser.read_in_order(uint64Test, padded_string{ buffer });
		},
		1);

	r.json_read = result.count();
	buffer.clear();
	if (doWePrint) {
		r.print();
	}

	return r;
}

auto simdjson_test(const std::string& bufferNew, bool doWePrint = true) {
	std::string buffer{ bufferNew };
	on_demand parser{};

	results r{ "simdjson", "Multi Test", "https://github.com/simdjson/simdjson", iterations };
	Test<test_struct> uint64Test{};

	r.json_read_byte_length = buffer.size();
	auto result = benchmark(
		[&]() {
			parser.read_in_order(uint64Test, padded_string{ buffer });
		},
		iterations);

	r.json_read = result.count();
	buffer.clear();
	if (doWePrint) {
		r.print();
	}

	return r;
}

struct on_demand_abc {
	bool read_out_of_order(AbcTest<test_struct>& obj, const padded_string& json);

  protected:
	ondemand::parser parser{};
};

bool on_demand_abc::read_out_of_order(AbcTest<test_struct>& obj, const padded_string& json) {
	ondemand::document doc = parser.iterate(json).value();
	SIMD_Pull(z);
	SIMD_Pull(y);
	SIMD_Pull(x);
	SIMD_Pull(w);
	SIMD_Pull(v);
	SIMD_Pull(u);
	SIMD_Pull(t);
	SIMD_Pull(s);
	SIMD_Pull(r);
	SIMD_Pull(q);
	SIMD_Pull(p);
	SIMD_Pull(o);
	SIMD_Pull(n);
	SIMD_Pull(m);
	SIMD_Pull(l);
	SIMD_Pull(k);
	SIMD_Pull(j);
	SIMD_Pull(i);
	SIMD_Pull(h);
	SIMD_Pull(g);
	SIMD_Pull(f);
	SIMD_Pull(e);
	SIMD_Pull(d);
	SIMD_Pull(c);
	SIMD_Pull(b);
	SIMD_Pull(a);
	return false;
}

std::string get_string(simdjson::ondemand::value value, const std::string& key) {
	simdjson::ondemand::value field;
	if (!value[key].get(field)) {
		std::string_view result;
		simdjson::error_code error{};
		field.get_string().tie(result, error);
		return static_cast<std::string>(result);
	}
	return "";
}

int64_t get_int(simdjson::ondemand::value value, const std::string& key) {
	simdjson::ondemand::value field;
	if (!value[key].get(field)) {
		int64_t result;
		simdjson::error_code error{};
		field.get_int64().tie(result, error);
		return result;
	}
	return 0;
}

bool get_bool(simdjson::ondemand::value value, const std::string& key) {
	simdjson::ondemand::value field;
	if (!value[key].get(field)) {
		bool result;
		simdjson::error_code error{};
		field.get_bool().tie(result, error);
		return result;
	}
	return false;
}

std::vector<uint64_t> get_roles(simdjson::ondemand::value value) {
	std::vector<uint64_t> roles;
	for (simdjson::ondemand::value role: value) {
		uint64_t roleValue;
		simdjson::error_code error{};
		role.get_uint64().tie(roleValue, error);
		roles.push_back(roleValue);
	}
	return roles;
}

icon_emoji extract_icon_emoji(simdjson::ondemand::value value) {
	icon_emoji result;
	result.name = get_string(value, "name");
	result.id = get_string(value, "id");
	return result;
}

channel extract_channel(simdjson::ondemand::value value) {
	channel result;
	result.type = get_int(value, "type");
	result.topic = get_string(value, "topic");
	result.themeColor = get_string(value, "theme_color");
	result.rateLimitPerUser = get_int(value, "rate_limit_per_user");
	result.position = get_int(value, "position");
	result.permissions = get_string(value, "permissions");
	result.parentId = get_string(value, "parent_id");
	result.nsfw = get_bool(value, "nsfw");
	result.name = get_string(value, "name");
	result.lastPinTimestamp = get_string(value, "last_pin_timestamp");
	result.lastMessageId = get_string(value, "last_message_id");
	result.id = get_string(value, "id");
	result.iconEmoji = extract_icon_emoji(value["icon_emoji"]);
	result.guildId = get_string(value, "guild_id");
	result.flags = get_int(value, "flags");
	return result;
}

user extract_user(simdjson::ondemand::value value) {
	user result;
	result.username = get_string(value, "username");
	result.publicFlags = get_int(value, "public_flags");
	result.id = get_string(value, "id");
	result.globalName = get_string(value, "global_name");
	result.discriminator = get_string(value, "discriminator");
	result.avatarDecorationData = get_string(value, "avatar_decoration_data");
	result.avatar = get_string(value, "avatar");
	return result;
}

member extract_member(simdjson::ondemand::value value) {
	member result;
	result.userVal = extract_user(value["user"]);
	result.unusualDmActivityUntil = get_string(value, "unusual_dm_activity_until");
	result.roles = get_roles(value["roles"]);
	result.premiumSince = get_string(value, "premium_since");
	result.permissions = get_string(value, "permissions");
	result.pending = get_bool(value, "pending");
	result.nick = get_string(value, "nick");
	result.mute = get_bool(value, "mute");
	result.joinedAt = get_string(value, "joined_at");
	result.flags = get_int(value, "flags");
	result.deaf = get_bool(value, "deaf");
	result.communicationDisabledUntil = get_string(value, "communication_disabled_until");
	result.avatar = get_string(value, "avatar");
	return result;
}

std::vector<std::string> get_features(simdjson::ondemand::value value) {
	std::vector<std::string> features;
	for (simdjson::ondemand::value feature: value) {
		std::string_view featureValue;
		simdjson::error_code error{};
		feature.get_string().tie(featureValue, error);
		features.push_back(static_cast<std::string>(featureValue));
	}
	return features;
}

std::vector<std::string> get_tokens(simdjson::ondemand::value value) {
	std::vector<std::string> features;
	for (simdjson::ondemand::value feature: value) {
		std::string_view featureValue;
		simdjson::error_code error{};
		feature.get_string().tie(featureValue, error);
		features.push_back(static_cast<std::string>(featureValue));
	}
	return features;
}

guild extract_guild(simdjson::ondemand::value value) {
	guild result;
	result.locale = get_string(value, "locale");
	result.id = get_string(value, "id");
	result.features = get_features(value["features"]);
	return result;
}

d extract_d(simdjson::ondemand::value value) {
	d result;
	result.version = get_int(value, "version");
	result.type = get_int(value, "type");
	result.token = get_tokens(value["token"]);
	result.memberVal = extract_member(value["member"]);
	result.locale = get_string(value, "locale");
	result.id = get_string(value, "id");
	result.guildLocale = get_string(value, "guildLocale");
	result.guildId = get_string(value, "guildId");
	result.guildVal = extract_guild(value["guild"]);
	return result;
}

welcome extract_welcome(simdjson::ondemand::value value) {
	welcome result;
	result.t = get_string(value, "t");
	result.s = get_int(value, "s");
	result.op = get_int(value, "op");
	result.dVal = extract_d(value["d"]);
	return result;
}

data extract_data(simdjson::ondemand::value value) {
	data result;
	result.type = get_int(value, "type");
	result.name = get_string(value, "name");
	result.id = get_string(value, "id");
	return result;
}
auto simdjson_discord_test(bool doWePrint = true) {
	std::string buffer{ discordData };

	AbcTest<test_struct> obj{};

	results r{ "simdjson", "Discord Test", "https://github.com/simdjson/simdjson", iterations };

	simdjson::ondemand::parser parser;

	welcome welcomeData;

	auto result = benchmark(
		[&]() {
			auto doc = parser.iterate(buffer);
			extract_welcome(doc);
		},
		iterations);

	r.json_read_byte_length = buffer.size();
	r.json_read = result.count();
	if (doWePrint) {
		r.print();
	}

	return r;
}

auto simdjson_abc_test(const std::string& bufferNew, bool doWePrint = true) {
	std::string buffer{ bufferNew };
	on_demand_abc parser{};

	AbcTest<test_struct> obj{};

	results r{ "simdjson", "Abc Test", "https://github.com/simdjson/simdjson", iterations };

	auto result = benchmark(
		[&]() {
			parser.read_out_of_order(obj, padded_string{ buffer });
		},
		iterations);

	r.json_read_byte_length = buffer.size();
	r.json_read = result.count();
	if (doWePrint) {
		r.print();
	}

	return r;
}

static std::string table_header = R"(
| Library | Write (MB/s) | Read (MB/s) |
| ------------------------------------------------- | ---------- | ----------- |)";

std::string regular_test(const json_data& jsonData) {
	jsonifier::vector<results> results{};
	for (uint32_t x = 0; x < 2; ++x) {
		simdjson_test(jsonData.theData, false);
	}
	results.emplace_back(simdjson_test(jsonData.theData));
	for (uint32_t x = 0; x < 2; ++x) {
		glaze_test(jsonData.theData, false);
	}
	results.emplace_back(glaze_test(jsonData.theData));
	for (uint32_t x = 0; x < 2; ++x) {
		jsonifier_test(jsonData.theData, false);
	}
	results.emplace_back(jsonifier_test(jsonData.theData));

	std::string table{};
	const auto n = results.size();
	table += table_header + '\n';
	for (uint64_t x = 0; x < n; ++x) {
		table += results[x].json_stats();
		if (x != n - 1) {
			table += "\n";
		}
	}
	return table;
}

std::string abc_test(const json_data& jsonData) {
	jsonifier::vector<results> results{};
	for (uint32_t x = 0; x < 2; ++x) {
		simdjson_abc_test(jsonData.theData, false);
	}
	results.emplace_back(simdjson_abc_test(jsonData.theData));
	for (uint32_t x = 0; x < 2; ++x) {
		glaze_abc_test(jsonData.theData, false);
	}
	results.emplace_back(glaze_abc_test(jsonData.theData));
	for (uint32_t x = 0; x < 2; ++x) {
		jsonifier_abc_test(jsonData.theData, false);
	}
	results.emplace_back(jsonifier_abc_test(jsonData.theData));

	std::string table{};
	const auto n = results.size();
	table += table_header + '\n';
	for (uint64_t x = 0; x < n; ++x) {
		table += results[x].json_stats();
		if (x != n - 1) {
			table += "\n";
		}
	}
	return table;
}

std::string discord_test(const json_data& jsonData) {
	jsonifier::vector<results> results{};
	for (uint32_t x = 0; x < 2; ++x) {
		simdjson_discord_test(false);
	}
	results.emplace_back(simdjson_discord_test());
	for (uint32_t x = 0; x < 2; ++x) {
		glaze_discord_test(false);
	}
	results.emplace_back(glaze_discord_test());
	for (uint32_t x = 0; x < 2; ++x) {
		jsonifier_discord_test(false);
	}
	results.emplace_back(jsonifier_discord_test());

	std::string table{};
	const auto n = results.size();
	table += table_header + '\n';
	for (uint64_t x = 0; x < n; ++x) {
		table += results[x].json_stats();
		if (x != n - 1) {
			table += "\n";
		}
	}
	return table;
}

std::string single_test(const json_data& jsonData) {
	jsonifier::vector<results> results{};
	for (uint32_t x = 0; x < 2; ++x) {
		simdjson_single_test(jsonData.theData, false);
	}
	results.emplace_back(simdjson_single_test(jsonData.theData));
	for (uint32_t x = 0; x < 2; ++x) {
		glaze_single_test(jsonData.theData, false);
	}
	results.emplace_back(glaze_single_test(jsonData.theData));
	for (uint32_t x = 0; x < 2; ++x) {
		jsonifier_single_test(jsonData.theData, false);
	}
	results.emplace_back(jsonifier_single_test(jsonData.theData));

	std::string table{};
	const auto n = results.size();
	table += table_header + '\n';
	for (uint64_t x = 0; x < n; ++x) {
		table += results[x].json_stats();
		if (x != n - 1) {
			table += "\n";
		}
	}
	return table;
};

int32_t main() {
	try {
		jsonifier::string newString03{ "1234\n567\r234567" };
		jsonifier::string newString04{ "1234\n567\r234567" };
		std::string newString05{ "1234\n567\r234567" };
		std::string newString06{ "1234\n567\r234567" };
		bool resultNewer{ false };
		std::cout << "BENCHMARK jsonifier_internal::shortCompare(): "
				  << benchmark(
						 [&]() {
							 for (volatile uint64_t x = 0; x < 1024 * 16; ++x) {
								 resultNewer = newString03 == newString04;
							 }
						 },
						 1024)
				  << std::endl;
		std::cout << "RESULT: " << resultNewer << std::endl;
		std::cout << "BENCHMARK std::memcmp(): "
				  << benchmark(
						 [&]() {
							 for (volatile uint64_t x = 0; x < 1024 * 16; ++x) {
								 resultNewer = newString05 == newString06;
							 }
						 },
						 1024)
				  << std::endl;
		std::cout << "RESULT: " << resultNewer << std::endl;
		json_data jsonData{ TestGenerator<test_struct>::generateJsonData() };
#if defined(_WIN32)
		FileLoader fileLoader01{ "../../../ReadMe.md" };
		FileLoader fileLoader02{ "../../../JsonData.json" };
		fileLoader02.saveFile(glz::prettify(jsonData.theData));
#else
		FileLoader fileLoader01{ "../ReadMe.md" };
		FileLoader fileLoader02{ "../JsonData.json" };
		fileLoader02.saveFile(glz::prettify(jsonData.theData));
#endif
		std::string newTimeString{};
		newTimeString.resize(1024);
		std::tm resultTwo{};
		std::time_t result = std::time(nullptr);
		resultTwo = *localtime(&result);
		newTimeString.resize(strftime(newTimeString.data(), 1024, "%b %d, %Y", &resultTwo));
		//discord_test(jsonData);
		auto singlTestResults = single_test(jsonData);
		auto multiTestResults = regular_test(jsonData);
		auto abcTestResults = abc_test(jsonData);
		std::string newString = fileLoader01;
		uint64_t currentStart{ 0 };
		uint64_t currentEnd{ 0 };
		currentEnd = newString.find("Latest results (") + std::string{ "Latest results (" }.size();
		std::string dateLine = newString.substr(currentStart, currentEnd);
		currentStart = newString.find("Single Iteration Test Results:");
		currentEnd = newString.find("Single Iteration Test Results:") + std::string{ "Single Iteration Test Results:" }.size();
		std::string section02 = newString.substr(currentStart, (currentEnd - currentStart));
		currentStart = newString.find("Multi Iteration Test Results:");
		currentEnd = newString.find("Multi Iteration Test Results:") + std::string{ "Multi Iteration Test Results:" }.size();
		std::string section03 = newString.substr(currentStart, (currentEnd - currentStart));
		currentStart = newString.find("## ABC Test (Out of Sequence Performance)");
		currentEnd = newString.find("In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining "
									"optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.") +
			std::string{ "In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal "
						 "performance regardless of the JSON document's scale, or ordering of the keys being parsed." }
				.size();
		std::string section04 = newString.substr(currentStart, (currentEnd - currentStart));
		std::string newerString = dateLine + newTimeString + "):" + "\n\n" +
			"[Test value, used in the following tests:](https://github.com/RealTimeChris/Json-Performance/blob/main/JsonData.json)\n\n" + section02 +
			"\n" + singlTestResults + "\n\n" + section03 + "\n" + multiTestResults + "\n" + "> " + std::to_string(iterations) +
			" iterations on a 6 core (Intel i7 8700k)\n\n" + section04 + "\n" + abcTestResults + "\n" + "> " + std::to_string(iterations) +
			" iterations on a 6 core (Intel i7 8700k)";
		fileLoader01.saveFile(newerString);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}