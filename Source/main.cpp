#if defined(JSONIFIER_CPU_INSTRUCTIONS)
//#undef JSONIFIER_CPU_INSTRUCTIONS
//#define JSONIFIER_CPU_INSTRUCTIONS (JSONIFIER_AVX2 | JSONIFIER_POPCNT)
#endif
#include "UnicodeEmoji.hpp"
#include <jsonifier/Index.hpp>
#include "glaze/glaze.hpp"
#include <unordered_set>
#include <unordered_map>
#include <filesystem>
#include <algorithm>
#include <iostream>
#include <random>
#include <thread>
#include <chrono>

struct geometry_data {
	std::vector<std::vector<std::vector<double>>> coordinates{};
	std::string type{};
};

struct properties_data {
	std::string name{};
};

struct feature {
	properties_data properties{};
	geometry_data geometry{};
	std::string type{};
};

struct canada_message {
	std::vector<feature> features{};
	std::string type{};
};

struct search_metadata_data {
	std::string since_id_str{};
	std::string next_results{};
	std::string refresh_url{};
	std::string max_id_str{};
	double completed_in{};
	std::string query{};
	int64_t since_id{};
	int64_t count{};
	double max_id{};
};

struct hashtag {
	std::vector<int64_t> indices{};
	std::string text{};
};

struct large_data {
	std::string resize{};
	int64_t w{};
	int64_t h{};
};

struct sizes_data {
	large_data medium{};
	large_data small{};
	large_data thumb{};
	large_data large{};
};

struct media_data {
	std::optional<std::string> source_status_id_str{};
	std::optional<double> source_status_id{};
	std::vector<int64_t> indices{};
	std::string media_url_https{};
	std::string expanded_url{};
	std::string display_url{};
	std::string media_url{};
	std::string id_str{};
	std::string type{};
	sizes_data sizes{};
	std::string url{};
	double id{};
};

struct url_data {
	std::vector<int64_t> indices{};
	std::string expanded_url{};
	std::string display_url{};
	std::string url{};
};

struct user_mention {
	std::vector<int64_t> indices{};
	std::string screen_name{};
	std::string id_str{};
	std::string name{};
	int64_t id{};
};

struct status_entities {
	std::optional<std::vector<media_data>> media{};
	std::vector<user_mention> user_mentions{};
	std::vector<std::nullptr_t> symbols{};
	std::vector<hashtag> hashtags{};
	std::vector<url_data> urls{};
};

struct metadata_data {
	std::string iso_language_code{};
	std::string result_type{};
};

struct description_data {
	std::vector<url_data> urls{};
};

struct user_entities {
	std::optional<description_data> url{};
	description_data description{};
};

struct twitter_user {
	std::string profile_background_image_url_https{};
	std::optional<std::string> profile_banner_url{};
	std::string profile_sidebar_border_color{};
	std::string profile_background_image_url{};
	std::string profile_sidebar_fill_color{};
	std::optional<std::string> time_zone{};
	std::string profile_background_color{};
	std::string profile_image_url_https{};
	std::optional<int64_t> utc_offset{};
	bool profile_use_background_image{};
	std::optional<std::string> url{};
	std::string profile_text_color{};
	std::string profile_link_color{};
	std::string profile_image_url{};
	bool profile_background_tile{};
	bool is_translation_enabled{};
	bool default_profile_image{};
	bool contributors_enabled{};
	bool follow_request_sent{};
	int64_t favourites_count{};
	std::string description{};
	std::string screen_name{};
	int64_t followers_count{};
	int64_t statuses_count{};
	std::string created_at{};
	user_entities entities{};
	int64_t friends_count{};
	bool default_profile{};
	int64_t listed_count{};
	std::string location{};
	bool user_protected{};
	bool is_translator{};
	std::string id_str{};
	bool notifications{};
	std::string string{};
	std::string name{};
	bool geo_enabled{};
	std::string lang{};
	bool following{};
	bool verified{};
	int64_t id{};
};

struct retweeted_status_data {
	std::optional<std::string> in_reply_to_status_id_str{};
	std::optional<std::string> in_reply_to_user_id_str{};
	std::optional<std::string> in_reply_to_screen_name{};
	std::optional<double> in_reply_to_status_id{};
	std::optional<int64_t> in_reply_to_user_id{};
	std::optional<bool> possibly_sensitive{};
	std::nullptr_t contributors{ nullptr };
	std::nullptr_t coordinates{ nullptr };
	std::nullptr_t place{ nullptr };
	std::nullptr_t geo{ nullptr };
	status_entities entities{};
	int64_t favorite_count{};
	metadata_data metadata{};
	std::string created_at{};
	int64_t retweet_count{};
	std::string source{};
	std::string id_str{};
	twitter_user user{};
	std::string lang{};
	std::string text{};
	bool truncated{};
	bool favorited{};
	bool retweeted{};
	double id{};
};

struct status_data {
	std::optional<retweeted_status_data> retweeted_status{};
	std::optional<std::string> in_reply_to_status_id_str{};
	std::optional<std::string> in_reply_to_user_id_str{};
	std::optional<std::string> in_reply_to_screen_name{};
	std::optional<double> in_reply_to_status_id{};
	std::optional<int64_t> in_reply_to_user_id{};
	std::optional<bool> possibly_sensitive{};
	std::nullptr_t contributors{ nullptr };
	std::nullptr_t coordinates{ nullptr };
	std::nullptr_t place{ nullptr };
	std::nullptr_t geo{ nullptr };
	status_entities entities{};
	int64_t favorite_count{};
	metadata_data metadata{};
	std::string created_at{};
	int64_t retweet_count{};
	std::string source{};
	std::string id_str{};
	twitter_user user{};
	std::string lang{};
	std::string text{};
	bool truncated{};
	bool favorited{};
	bool retweeted{};
	double id{};
};

struct twitter_message {
	search_metadata_data search_metadata{};
	std::vector<status_data> statuses{};
};

struct icon_emoji_data {
	std::optional<std::string> name{};
	std::nullptr_t id{ nullptr };
};

struct permission_overwrite {
	std::string allow{};
	std::string deny{};
	std::string id{};
	int64_t type{};
};

struct channel_data {
	std::vector<permission_overwrite> permission_overwrites{};
	std::optional<std::string> last_message_id{};
	int64_t default_thread_rate_limit_per_user{};
	std::vector<std::nullptr_t> applied_tags{};
	std::vector<std::nullptr_t> recipients{};
	int64_t default_auto_archive_duration{};
	std::nullptr_t rtc_region{ nullptr };
	std::nullptr_t status{ nullptr };
	std::string last_pin_timestamp{};
	std::nullptr_t topic{ nullptr };
	int64_t rate_limit_per_user{};
	icon_emoji_data icon_emoji{};
	int64_t total_message_sent{};
	int64_t video_quality_mode{};
	std::string application_id{};
	std::string permissions{};
	int64_t message_count{};
	std::string parent_id{};
	int64_t member_count{};
	std::string owner_id{};
	std::string guild_id{};
	int64_t user_limit{};
	int64_t position{};
	std::string name{};
	std::string icon{};
	int64_t version{};
	int64_t bitrate{};
	std::string id{};
	int64_t flags{};
	int64_t type{};
	bool managed{};
	bool nsfw{};
};

struct user_data {
	std::nullptr_t avatar_decoration_data{ nullptr };
	std::optional<std::string> display_name{};
	std::optional<std::string> global_name{};
	std::optional<std::string> avatar{};
	std::nullptr_t banner{ nullptr };
	std::nullptr_t locale{ nullptr };
	std::string discriminator{};
	std::string user_name{};
	int64_t accent_color{};
	int64_t premium_type{};
	int64_t public_flags{};
	std::string email{};
	bool mfa_enabled{};
	std::string id{};
	int64_t flags{};
	bool verified{};
	bool system{};
	bool bot{};
};

struct member_data {
	std::nullptr_t communication_disabled_until{ nullptr };
	std::nullptr_t premium_since{ nullptr };
	std::optional<std::string> nick{};
	std::nullptr_t avatar{ nullptr };
	std::vector<std::string> roles{};
	std::string permissions{};
	std::string joined_at{};
	std::string guild_id{};
	user_data user{};
	int64_t flags{};
	bool pending{};
	bool deaf{};
	bool mute{};
};

struct tags_data {
	std::nullptr_t premium_subscriber{ nullptr };
	std::optional<std::string> bot_id{};
};

struct role_data {
	std::nullptr_t unicode_emoji{ nullptr };
	std::nullptr_t icon{ nullptr };
	std::string permissions{};
	int64_t position{};
	std::string name{};
	bool mentionable{};
	int64_t version{};
	std::string id{};
	tags_data tags{};
	int64_t color{};
	int64_t flags{};
	bool managed{};
	bool hoist{};
};

struct guild_data {
	std::nullptr_t latest_on_boarding_question_id{ nullptr };
	std::vector<std::nullptr_t> guild_scheduled_events{};
	std::nullptr_t safety_alerts_channel_id{ nullptr };
	std::nullptr_t inventory_settings{ nullptr };
	std::vector<std::nullptr_t> voice_states{};
	std::nullptr_t discovery_splash{ nullptr };
	std::nullptr_t vanity_url_code{ nullptr };
	std::nullptr_t application_id{ nullptr };
	std::nullptr_t afk_channel_id{ nullptr };
	int64_t default_message_notifications{};
	int64_t max_stage_video_channel_users{};
	std::string public_updates_channel_id{};
	std::nullptr_t description{ nullptr };
	std::vector<std::nullptr_t> threads{};
	std::vector<channel_data> channels{};
	int64_t premium_subscription_count{};
	int64_t approximate_presence_count{};
	std::vector<std::string> features{};
	std::vector<std::string> stickers{};
	bool premium_progress_bar_enabled{};
	std::vector<member_data> members{};
	std::nullptr_t hub_type{ nullptr };
	int64_t approximate_member_count{};
	int64_t explicit_content_filter{};
	int64_t max_video_channel_users{};
	std::nullptr_t splash{ nullptr };
	std::nullptr_t banner{ nullptr };
	std::string system_channel_id{};
	std::string widget_channel_id{};
	std::string preferred_locale{};
	int64_t system_channel_flags{};
	std::string rules_channel_id{};
	std::vector<role_data> roles{};
	int64_t verification_level{};
	std::string permissions{};
	int64_t max_presences{};
	std::string discovery{};
	std::string joined_at{};
	int64_t member_count{};
	int64_t premium_tier{};
	std::string owner_id{};
	int64_t max_members{};
	int64_t afk_timeout{};
	bool widget_enabled{};
	std::string region{};
	int64_t nsfw_level{};
	int64_t mfa_level{};
	std::string name{};
	std::string icon{};
	bool unavailable{};
	std::string id{};
	int64_t flags{};
	bool large{};
	bool owner{};
	bool nsfw{};
	bool lazy{};
};

struct discord_message {
	std::string t{};
	guild_data d{};
	int64_t op{};
	int64_t s{};
};

template<> struct jsonifier::core<geometry_data> {
	using value_type				 = geometry_data;
	static constexpr auto parseValue = createValue<&value_type::coordinates, &value_type::type>();
};

template<> struct jsonifier::core<properties_data> {
	using value_type				 = properties_data;
	static constexpr auto parseValue = createValue<&value_type::name>();
};

template<> struct jsonifier::core<feature> {
	using value_type				 = feature;
	static constexpr auto parseValue = createValue<&value_type::properties, &value_type::geometry, &value_type::type>();
};

template<> struct jsonifier::core<canada_message> {
	using value_type				 = canada_message;
	static constexpr auto parseValue = createValue<&value_type::features, &value_type::type>();
};

#if !defined(ASAN)

template<> struct glz::meta<geometry_data> {
	using value_type			= geometry_data;
	static constexpr auto value = object("coordinates", &value_type::coordinates, "type", &value_type::type);
};

template<> struct glz::meta<properties_data> {
	using value_type			= properties_data;
	static constexpr auto value = object("name", &value_type::name);
};

template<> struct glz::meta<feature> {
	using value_type			= feature;
	static constexpr auto value = object("properties", &value_type::properties, "geometry", &value_type::geometry, "type", &value_type::type);
};

template<> struct glz::meta<canada_message> {
	using value_type			= canada_message;
	static constexpr auto value = object("features", &value_type::features, "type", &value_type::type);
};

#endif

template<> struct jsonifier::core<search_metadata_data> {
	using value_type				 = search_metadata_data;
	static constexpr auto parseValue = createValue<&value_type::since_id_str, &value_type::next_results, &value_type::refresh_url, &value_type::max_id_str,
		&value_type::completed_in, &value_type::query, &value_type::since_id, &value_type::count, &value_type::max_id>();
};

template<> struct jsonifier::core<hashtag> {
	using value_type				 = hashtag;
	static constexpr auto parseValue = createValue<&value_type::indices, &value_type::text>();
};

template<> struct jsonifier::core<large_data> {
	using value_type				 = large_data;
	static constexpr auto parseValue = createValue<&value_type::resize, &value_type::w, &value_type::h>();
};

template<> struct jsonifier::core<sizes_data> {
	using value_type				 = sizes_data;
	static constexpr auto parseValue = createValue<&value_type::medium, &value_type::small, &value_type::thumb, &value_type::large>();
};

template<> struct jsonifier::core<media_data> {
	using value_type = media_data;
	static constexpr auto parseValue =
		createValue<&value_type::source_status_id_str, &value_type::source_status_id, &value_type::indices, &value_type::media_url_https, &value_type::expanded_url,
			&value_type::display_url, &value_type::media_url, &value_type::id_str, &value_type::type, &value_type::sizes, &value_type::url, &value_type::id>();
};

template<> struct jsonifier::core<url_data> {
	using value_type				 = url_data;
	static constexpr auto parseValue = createValue<&value_type::indices, &value_type::expanded_url, &value_type::display_url, &value_type::url>();
};

template<> struct jsonifier::core<user_mention> {
	using value_type				 = user_mention;
	static constexpr auto parseValue = createValue<&value_type::indices, &value_type::screen_name, &value_type::id_str, &value_type::name, &value_type::id>();
};

template<> struct jsonifier::core<status_entities> {
	using value_type				 = status_entities;
	static constexpr auto parseValue = createValue<&value_type::media, &value_type::user_mentions, &value_type::symbols, &value_type::hashtags, &value_type::urls>();
};

template<> struct jsonifier::core<metadata_data> {
	using value_type				 = metadata_data;
	static constexpr auto parseValue = createValue<&value_type::iso_language_code, &value_type::result_type>();
};

template<> struct jsonifier::core<description_data> {
	using value_type				 = description_data;
	static constexpr auto parseValue = createValue<&value_type::urls>();
};

template<> struct jsonifier::core<user_entities> {
	using value_type				 = user_entities;
	static constexpr auto parseValue = createValue<&value_type::url, &value_type::description>();
};

template<> struct jsonifier::core<twitter_user> {
	using value_type				 = twitter_user;
	static constexpr auto parseValue = createValue<&value_type::profile_background_image_url_https, &value_type::profile_banner_url, &value_type::profile_background_image_url,
		&value_type::profile_sidebar_border_color, &value_type::profile_sidebar_fill_color, &value_type::time_zone, &value_type::profile_background_color,
		&value_type::profile_image_url_https, &value_type::utc_offset, &value_type::profile_use_background_image, &value_type::url, &value_type::profile_text_color,
		&value_type::profile_link_color, &value_type::profile_image_url, &value_type::profile_background_tile, &value_type::is_translation_enabled,
		&value_type::default_profile_image, &value_type::contributors_enabled, &value_type::follow_request_sent, &value_type::favourites_count, &value_type::description,
		&value_type::screen_name, &value_type::followers_count, &value_type::statuses_count, &value_type::created_at, &value_type::entities, &value_type::friends_count,
		&value_type::default_profile, &value_type::listed_count, &value_type::location, &value_type::user_protected, &value_type::is_translator, &value_type::id_str,
		&value_type::notifications, &value_type::string, &value_type::name, &value_type::geo_enabled, &value_type::lang, &value_type::following, &value_type::verified,
		&value_type::id>();
};

template<> struct jsonifier::core<retweeted_status_data> {
	using value_type				 = retweeted_status_data;
	static constexpr auto parseValue = createValue<&value_type::in_reply_to_status_id_str, &value_type::in_reply_to_user_id_str, &value_type::in_reply_to_screen_name,
		&value_type::in_reply_to_status_id, &value_type::in_reply_to_user_id, &value_type::possibly_sensitive, &value_type::contributors, &value_type::coordinates,
		&value_type::place, &value_type::geo, &value_type::entities, &value_type::favorite_count, &value_type::metadata, &value_type::created_at, &value_type::retweet_count,
		&value_type::source, &value_type::id_str, &value_type::user, &value_type::lang, &value_type::text, &value_type::truncated, &value_type::favorited, &value_type::retweeted,
		&value_type::id>();
};

template<> struct jsonifier::core<status_data> {
	using value_type				 = status_data;
	static constexpr auto parseValue = createValue<&value_type::in_reply_to_status_id_str, &value_type::in_reply_to_user_id_str, &value_type::in_reply_to_screen_name,
		&value_type::in_reply_to_status_id, &value_type::in_reply_to_user_id, &value_type::possibly_sensitive, &value_type::contributors, &value_type::coordinates,
		&value_type::retweeted_status, &value_type::place, &value_type::geo, &value_type::entities, &value_type::favorite_count, &value_type::metadata, &value_type::created_at,
		&value_type::retweet_count, &value_type::source, &value_type::id_str, &value_type::user, &value_type::lang, &value_type::text, &value_type::truncated,
		&value_type::favorited, &value_type::retweeted, &value_type::id>();
};

template<> struct jsonifier::core<twitter_message> {
	using value_type				 = twitter_message;
	static constexpr auto parseValue = createValue<&value_type::search_metadata, &value_type::statuses>();
};

#if !defined(ASAN)

template<> struct glz::meta<search_metadata_data> {
	using value_type = search_metadata_data;
	static constexpr auto value =
		object("since_id_str", &value_type::since_id_str, "next_results", &value_type::next_results, "refresh_url", &value_type::refresh_url, "max_id_str", &value_type::max_id_str,
			"completed_in", &value_type::completed_in, "query", &value_type::query, "since_id", &value_type::since_id, "count", &value_type::count, "max_id", &value_type::max_id);
};

template<> struct glz::meta<hashtag> {
	using value_type			= hashtag;
	static constexpr auto value = object("indices", &value_type::indices, "text", &value_type::text);
};

template<> struct glz::meta<large_data> {
	using value_type			= large_data;
	static constexpr auto value = object("resize", &value_type::resize, "w", &value_type::w, "h", &value_type::h);
};

template<> struct glz::meta<sizes_data> {
	using value_type			= sizes_data;
	static constexpr auto value = object("medium", &value_type::medium, "small", &value_type::small, "thumb", &value_type::thumb, "large", &value_type::large);
};

template<> struct glz::meta<media_data> {
	using value_type			= media_data;
	static constexpr auto value = object("source_status_id_str", &value_type::source_status_id_str, "source_status_id", &value_type::source_status_id, "indices",
		&value_type::indices, "media_url_https", &value_type::media_url_https, "expanded_url", &value_type::expanded_url, "display_url", &value_type::display_url, "media_url",
		&value_type::media_url, "id_str", &value_type::id_str, "type", &value_type::type, "sizes", &value_type::sizes, "url", &value_type::url, "id", &value_type::id);
};

template<> struct glz::meta<url_data> {
	using value_type = url_data;
	static constexpr auto value =
		object("indices", &value_type::indices, "expanded_url", &value_type::expanded_url, "display_url", &value_type::display_url, "url", &value_type::url);
};

template<> struct glz::meta<user_mention> {
	using value_type = user_mention;
	static constexpr auto value =
		object("indices", &value_type::indices, "screen_name", &value_type::screen_name, "id_str", &value_type::id_str, "name", &value_type::name, "id", &value_type::id);
};

template<> struct glz::meta<status_entities> {
	using value_type			= status_entities;
	static constexpr auto value = object("media", &value_type::media, "user_mentions", &value_type::user_mentions, "symbols", &value_type::symbols, "hashtags",
		&value_type::hashtags, "urls", &value_type::urls);
};

template<> struct glz::meta<metadata_data> {
	using value_type			= metadata_data;
	static constexpr auto value = object("iso_language_code", &value_type::iso_language_code, "result_type", &value_type::result_type);
};

template<> struct glz::meta<description_data> {
	using value_type			= description_data;
	static constexpr auto value = object("urls", &value_type::urls);
};

template<> struct glz::meta<user_entities> {
	using value_type			= user_entities;
	static constexpr auto value = object("url", &value_type::url, "description", &value_type::description);
};

template<> struct glz::meta<twitter_user> {
	using value_type			= twitter_user;
	static constexpr auto value = object("profile_background_image_url_https", &value_type::profile_background_image_url_https, "profile_banner_url",
		&value_type::profile_banner_url, "profile_background_image_url", &value_type::profile_banner_url, "profile_sidebar_border_color", &value_type::profile_sidebar_border_color,
		"profile_sidebar_fill_color", &value_type::profile_sidebar_fill_color, "time_zone", &value_type::time_zone, "profile_background_color",
		&value_type::profile_background_color, "profile_image_url_https", &value_type::profile_image_url_https, "utc_offset", &value_type::utc_offset,
		"profile_use_background_image", &value_type::profile_use_background_image, "url", &value_type::url, "profile_text_color", &value_type::profile_text_color,
		"profile_link_color", &value_type::profile_link_color, "profile_image_url", &value_type::profile_image_url, "profile_background_tile", &value_type::profile_background_tile,
		"is_translation_enabled", &value_type::is_translation_enabled, "default_profile_image", &value_type::default_profile_image, "contributors_enabled",
		&value_type::contributors_enabled, "follow_request_sent", &value_type::follow_request_sent, "favourites_count", &value_type::favourites_count, "description",
		&value_type::description, "screen_name", &value_type::screen_name, "followers_count", &value_type::followers_count, "statuses_count", &value_type::statuses_count,
		"created_at", &value_type::created_at, "entities", &value_type::entities, "friends_count", &value_type::friends_count, "default_profile", &value_type::default_profile,
		"listed_count", &value_type::listed_count, "location", &value_type::location, "user_protected", &value_type::user_protected, "is_translator", &value_type::is_translator,
		"id_str", &value_type::id_str, "notifications", &value_type::notifications, "string", &value_type::string, "name", &value_type::name, "geo_enabled",
		&value_type::geo_enabled, "lang", &value_type::lang, "following", &value_type::following, "verified", &value_type::verified, "id", &value_type::id);
};

template<> struct glz::meta<retweeted_status_data> {
	using value_type			= retweeted_status_data;
	static constexpr auto value = object("in_reply_to_status_id_str", &value_type::in_reply_to_status_id_str, "in_reply_to_user_id_str", &value_type::in_reply_to_user_id_str,
		"in_reply_to_screen_name", &value_type::in_reply_to_screen_name, "in_reply_to_status_id", &value_type::in_reply_to_status_id, "in_reply_to_user_id",
		&value_type::in_reply_to_user_id, "possibly_sensitive", &value_type::possibly_sensitive, "contributors", &value_type::contributors, "coordinates", &value_type::coordinates,
		"place", &value_type::place, "geo", &value_type::geo, "entities", &value_type::entities, "favorite_count", &value_type::favorite_count, "metadata", &value_type::metadata,
		"created_at", &value_type::created_at, "retweet_count", &value_type::retweet_count, "source", &value_type::source, "id_str", &value_type::id_str, "user", &value_type::user,
		"lang", &value_type::lang, "text", &value_type::text, "truncated", &value_type::truncated, "favorited", &value_type::favorited, "retweeted", &value_type::retweeted, "id",
		&value_type::id);
};

template<> struct glz::meta<status_data> {
	using value_type			= status_data;
	static constexpr auto value = object("in_reply_to_status_id_str", &value_type::in_reply_to_status_id_str, "in_reply_to_user_id_str", &value_type::in_reply_to_user_id_str,
		"in_reply_to_screen_name", &value_type::in_reply_to_screen_name, "in_reply_to_status_id", &value_type::in_reply_to_status_id, "in_reply_to_user_id",
		&value_type::in_reply_to_user_id, "possibly_sensitive", &value_type::possibly_sensitive, "contributors", &value_type::contributors, "coordinates", &value_type::coordinates,
		"place", &value_type::place, "geo", &value_type::geo, "entities", &value_type::entities, "favorite_count", &value_type::favorite_count, "metadata", &value_type::metadata,
		"created_at", &value_type::created_at, "retweeted_status", &value_type::retweeted_status, "retweet_count", &value_type::retweet_count, "source", &value_type::source,
		"id_str", &value_type::id_str, "user", &value_type::user, "lang", &value_type::lang, "text", &value_type::text, "truncated", &value_type::truncated, "favorited",
		&value_type::favorited, "retweeted", &value_type::retweeted, "id", &value_type::id);
};

template<> struct glz::meta<twitter_message> {
	using value_type			= twitter_message;
	static constexpr auto value = object("search_metadata", &value_type::search_metadata, "statuses", &value_type::statuses);
};

#endif

template<> struct jsonifier::core<icon_emoji_data> {
	using value_type				 = icon_emoji_data;
	static constexpr auto parseValue = createValue<&value_type::name, &value_type::id>();
};

template<> struct jsonifier::core<permission_overwrite> {
	using value_type				 = permission_overwrite;
	static constexpr auto parseValue = createValue<&value_type::allow, &value_type::deny, &value_type::id, &value_type::type>();
};

template<> struct jsonifier::core<channel_data> {
	using value_type				 = channel_data;
	static constexpr auto parseValue = createValue<&value_type::permission_overwrites, &value_type::last_message_id, &value_type::default_thread_rate_limit_per_user,
		&value_type::applied_tags, &value_type::recipients, &value_type::default_auto_archive_duration, &value_type::rtc_region, &value_type::status,
		&value_type::last_pin_timestamp, &value_type::topic, &value_type::rate_limit_per_user, &value_type::icon_emoji, &value_type::total_message_sent,
		&value_type::video_quality_mode, &value_type::application_id, &value_type::permissions, &value_type::message_count, &value_type::parent_id, &value_type::member_count,
		&value_type::owner_id, &value_type::guild_id, &value_type::user_limit, &value_type::position, &value_type::name, &value_type::icon, &value_type::version,
		&value_type::bitrate, &value_type::id, &value_type::flags, &value_type::type, &value_type::managed, &value_type::nsfw>();
};

template<> struct jsonifier::core<user_data> {
	using value_type = user_data;
	static constexpr auto parseValue =
		createValue<&value_type::avatar_decoration_data, &value_type::display_name, &value_type::global_name, &value_type::avatar, &value_type::banner, &value_type::locale,
			&value_type::discriminator, &value_type::user_name, &value_type::accent_color, &value_type::premium_type, &value_type::public_flags, &value_type::email,
			&value_type::mfa_enabled, &value_type::id, &value_type::flags, &value_type::verified, &value_type::system, &value_type::bot>();
};

template<> struct jsonifier::core<member_data> {
	using value_type = member_data;
	static constexpr auto parseValue =
		createValue<&value_type::communication_disabled_until, &value_type::premium_since, &value_type::nick, &value_type::avatar, &value_type::roles, &value_type::permissions,
			&value_type::joined_at, &value_type::guild_id, &value_type::user, &value_type::flags, &value_type::pending, &value_type::deaf, &value_type::mute>();
};

template<> struct jsonifier::core<tags_data> {
	using value_type				 = tags_data;
	static constexpr auto parseValue = createValue<&value_type::premium_subscriber, &value_type::bot_id>();
};

template<> struct jsonifier::core<role_data> {
	using value_type				 = role_data;
	static constexpr auto parseValue = createValue<&value_type::unicode_emoji, &value_type::icon, &value_type::permissions, &value_type::position, &value_type::name,
		&value_type::mentionable, &value_type::version, &value_type::id, &value_type::tags, &value_type::color, &value_type::flags, &value_type::managed, &value_type::hoist>();
};

template<> struct jsonifier::core<guild_data> {
	using value_type				 = guild_data;
	static constexpr auto parseValue = createValue<&value_type::latest_on_boarding_question_id, &value_type::guild_scheduled_events, &value_type::safety_alerts_channel_id,
		&value_type::inventory_settings, &value_type::voice_states, &value_type::discovery_splash, &value_type::vanity_url_code, &value_type::application_id,
		&value_type::afk_channel_id, &value_type::default_message_notifications, &value_type::max_stage_video_channel_users, &value_type::public_updates_channel_id,
		&value_type::description, &value_type::threads, &value_type::channels, &value_type::premium_subscription_count, &value_type::approximate_presence_count,
		&value_type::features, &value_type::stickers, &value_type::premium_progress_bar_enabled, &value_type::members, &value_type::hub_type, &value_type::approximate_member_count,
		&value_type::explicit_content_filter, &value_type::max_video_channel_users, &value_type::splash, &value_type::banner, &value_type::system_channel_id,
		&value_type::widget_channel_id, &value_type::preferred_locale, &value_type::system_channel_flags, &value_type::rules_channel_id, &value_type::roles,
		&value_type::verification_level, &value_type::permissions, &value_type::max_presences, &value_type::discovery, &value_type::joined_at, &value_type::member_count,
		&value_type::premium_tier, &value_type::owner_id, &value_type::max_members, &value_type::afk_timeout, &value_type::widget_enabled, &value_type::region,
		&value_type::nsfw_level, &value_type::mfa_level, &value_type::name, &value_type::icon, &value_type::unavailable, &value_type::id, &value_type::flags, &value_type::large,
		&value_type::owner, &value_type::nsfw, &value_type::lazy>();
};

template<> struct jsonifier::core<discord_message> {
	using value_type				 = discord_message;
	static constexpr auto parseValue = createValue<&value_type::t, &value_type::d, &value_type::op, &value_type::s>();
};

#if !defined(ASAN)

template<> struct glz::meta<icon_emoji_data> {
	using value_type			= icon_emoji_data;
	static constexpr auto value = object("name", &value_type::name, "id", &value_type::id);
};

template<> struct glz::meta<permission_overwrite> {
	using value_type			= permission_overwrite;
	static constexpr auto value = object("allow", &value_type::allow, "deny", &value_type::deny, "id", &value_type::id, "type", &value_type::type);
};

template<> struct glz::meta<channel_data> {
	using value_type			= channel_data;
	static constexpr auto value = object("permission_overwrites", &value_type::permission_overwrites, "last_message_id", &value_type::last_message_id,
		"default_thread_rate_limit_per_user", &value_type::default_thread_rate_limit_per_user, "applied_tags", &value_type::applied_tags, "recipients", &value_type::recipients,
		"default_auto_archive_duration", &value_type::default_auto_archive_duration, "rtc_region", &value_type::rtc_region, "status", &value_type::status, "last_pin_timestamp",
		&value_type::last_pin_timestamp, "topic", &value_type::topic, "rate_limit_per_user", &value_type::rate_limit_per_user, "icon_emoji", &value_type::icon_emoji,
		"total_message_sent", &value_type::total_message_sent, "video_quality_mode", &value_type::video_quality_mode, "application_id", &value_type::application_id, "permissions",
		&value_type::permissions, "message_count", &value_type::message_count, "parent_id", &value_type::parent_id, "member_count", &value_type::member_count, "owner_id",
		&value_type::owner_id, "guild_id", &value_type::guild_id, "user_limit", &value_type::user_limit, "position", &value_type::position, "name", &value_type::name, "icon",
		&value_type::icon, "version", &value_type::version, "bitrate", &value_type::bitrate, "id", &value_type::id, "flags", &value_type::flags, "type", &value_type::type,
		"managed", &value_type::managed, "nsfw", &value_type::nsfw);
};

template<> struct glz::meta<user_data> {
	using value_type			= user_data;
	static constexpr auto value = object("avatar_decoration_data", &value_type::avatar_decoration_data, "display_name", &value_type::display_name, "global_name",
		&value_type::global_name, "avatar", &value_type::avatar, "banner", &value_type::banner, "locale", &value_type::locale, "discriminator", &value_type::discriminator,
		"user_name", &value_type::user_name, "accent_color", &value_type::accent_color, "premium_type", &value_type::premium_type, "public_flags", &value_type::public_flags,
		"email", &value_type::email, "mfa_enabled", &value_type::mfa_enabled, "id", &value_type::id, "flags", &value_type::flags, "verified", &value_type::verified, "system",
		&value_type::system, "bot", &value_type::bot);
};

template<> struct glz::meta<member_data> {
	using value_type			= member_data;
	static constexpr auto value = object("communication_disabled_until", &value_type::communication_disabled_until, "premium_since", &value_type::premium_since, "nick",
		&value_type::nick, "avatar", &value_type::avatar, "roles", &value_type::roles, "permissions", &value_type::permissions, "joined_at", &value_type::joined_at, "guild_id",
		&value_type::guild_id, "user", &value_type::user, "flags", &value_type::flags, "pending", &value_type::pending, "deaf", &value_type::deaf, "mute", &value_type::mute);
};

template<> struct glz::meta<tags_data> {
	using value_type			= tags_data;
	static constexpr auto value = object("premium_subscriber", &value_type::premium_subscriber, "bot_id", &value_type::bot_id);
};

template<> struct glz::meta<role_data> {
	using value_type			= role_data;
	static constexpr auto value = object("unicode_emoji", &value_type::unicode_emoji, "icon", &value_type::icon, "permissions", &value_type::permissions, "position",
		&value_type::position, "name", &value_type::name, "mentionable", &value_type::mentionable, "version", &value_type::version, "id", &value_type::id, "tags",
		&value_type::tags, "color", &value_type::color, "flags", &value_type::flags, "managed", &value_type::managed, "hoist", &value_type::hoist);
};

template<> struct glz::meta<guild_data> {
	using value_type			= guild_data;
	static constexpr auto value = object("latest_on_boarding_question_id", &value_type::latest_on_boarding_question_id, "guild_scheduled_events",
		&value_type::guild_scheduled_events, "safety_alerts_channel_id", &value_type::safety_alerts_channel_id, "inventory_settings", &value_type::inventory_settings,
		"voice_states", &value_type::voice_states, "discovery_splash", &value_type::discovery_splash, "vanity_url_code", &value_type::vanity_url_code, "application_id",
		&value_type::application_id, "afk_channel_id", &value_type::afk_channel_id, "default_message_notifications", &value_type::default_message_notifications,
		"max_stage_video_channel_users", &value_type::max_stage_video_channel_users, "public_updates_channel_id", &value_type::public_updates_channel_id, "description",
		&value_type::description, "threads", &value_type::threads, "channels", &value_type::channels, "premium_subscription_count", &value_type::premium_subscription_count,
		"approximate_presence_count", &value_type::approximate_presence_count, "features", &value_type::features, "stickers", &value_type::stickers, "premium_progress_bar_enabled",
		&value_type::premium_progress_bar_enabled, "members", &value_type::members, "hub_type", &value_type::hub_type, "approximate_member_count",
		&value_type::approximate_member_count, "explicit_content_filter", &value_type::explicit_content_filter, "max_video_channel_users", &value_type::max_video_channel_users,
		"splash", &value_type::splash, "banner", &value_type::banner, "system_channel_id", &value_type::system_channel_id, "widget_channel_id", &value_type::widget_channel_id,
		"preferred_locale", &value_type::preferred_locale, "system_channel_flags", &value_type::system_channel_flags, "rules_channel_id", &value_type::rules_channel_id, "roles",
		&value_type::roles, "verification_level", &value_type::verification_level, "permissions", &value_type::permissions, "max_presences", &value_type::max_presences,
		"discovery", &value_type::discovery, "joined_at", &value_type::joined_at, "member_count", &value_type::member_count, "premium_tier", &value_type::premium_tier, "owner_id",
		&value_type::owner_id, "max_members", &value_type::max_members, "afk_timeout", &value_type::afk_timeout, "widget_enabled", &value_type::widget_enabled, "region",
		&value_type::region, "nsfw_level", &value_type::nsfw_level, "mfa_level", &value_type::mfa_level, "name", &value_type::name, "icon", &value_type::icon, "unavailable",
		&value_type::unavailable, "id", &value_type::id, "flags", &value_type::flags, "large", &value_type::large, "owner", &value_type::owner, "nsfw", &value_type::nsfw, "lazy",
		&value_type::lazy);
};

template<> struct glz::meta<discord_message> {
	using value_type			= discord_message;
	static constexpr auto value = object("t", &value_type::t, "d", &value_type::d, "op", &value_type::op, "s", &value_type::s);
};

#endif

struct test_struct {
	std::vector<std::string> testStrings{};
	std::vector<uint64_t> testUints{};
	std::vector<double> testDoubles{};
	std::vector<int64_t> testInts{};
	std::vector<bool> testBools{};
};

namespace fs = std::filesystem;

class file_loader {
  public:
	file_loader(const std::string& filePathNew) {
		filePath = filePathNew;
		std::string directory{ filePathNew.substr(0, filePathNew.find_last_of("/")) };
		if (!fs::exists(directory)) {
			std::filesystem::create_directories(directory);
		}

		if (!fs::exists(filePath)) {
			std::ofstream createFile(filePath.data());
			createFile.close();
		}

		std::ifstream theStream(filePath.data(), std::ios::binary | std::ios::in);
		std::stringstream inputStream{};
		inputStream << theStream.rdbuf();
		fileContents = inputStream.str();
		theStream.close();
	}

	void saveFile(const std::string& fileToSave) {
		std::ofstream theStream(filePath.data(), std::ios::binary | std::ios::out | std::ios::trunc);
		theStream.write(fileToSave.data(), static_cast<int64_t>(fileToSave.size()));
		theStream.close();
	}

	operator std::string() {
		return std::string{ fileContents };
	}

  protected:
	std::string fileContents{};
	std::string filePath{};
};

template<typename value_type> struct test {
	std::vector<value_type> a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
};

template<typename value_type> struct test_generator {
	std::vector<value_type> a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;

	std::random_device randomEngine{};
	std::mt19937_64 gen{ randomEngine() };

	static constexpr std::string_view charset{ "!#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[]^_`abcdefghijklmnopqrstuvwxyz{|}~\"\\\r\b\f\t\n" };

	template<typename value_type_new> value_type_new randomizeNumberNormal(value_type_new mean, value_type_new stdDeviation) {
		std::normal_distribution<> normalDistributionTwo{ static_cast<double>(mean), static_cast<double>(stdDeviation) };
		auto theResult = normalDistributionTwo(randomEngine);
		if (theResult < 0) {
			theResult = -theResult;
		}
		return theResult;
	}

	template<typename value_type_new> value_type_new randomizeNumberUniform(value_type_new range) {
		std::uniform_int_distribution<uint64_t> dis(0, range);
		return dis(randomEngine);
	}

	void insertUnicodeInJSON(std::string& jsonString) {
		auto newStringView = unicode_emoji::unicodeEmoji[randomizeNumberUniform(std::size(unicode_emoji::unicodeEmoji) - 1)];
		jsonString += static_cast<std::string>(newStringView);
	}

	std::string generateString() {
		auto length{ randomizeNumberNormal(64.0f, 16.0f) };
		static constexpr uint32_t charsetSize = charset.size();
		auto unicodeCount					  = randomizeNumberUniform(length / 8);
		std::string result{};
		for (int32_t x = 0; x < length; ++x) {
			if (x == static_cast<int32_t>(length / unicodeCount)) {
				insertUnicodeInJSON(result);
			}
			result += charset[randomizeNumberUniform(charsetSize - 1)];
		}
		return result;
	}

	double generateDouble() {
		auto newValue = randomizeNumberNormal(double{}, std::numeric_limits<double>::max() / 50000000);
		return generateBool() ? newValue : -newValue;
	};

	bool generateBool() {
		return static_cast<bool>(randomizeNumberNormal(50.0f, 50.0f) >= 50.0f);
	};

	uint64_t generateUint() {
		return randomizeNumberNormal(std::numeric_limits<uint64_t>::max() / 2, std::numeric_limits<uint64_t>::max() / 2);
	};

	int64_t generateInt() {
		auto newValue = randomizeNumberNormal(int64_t{}, std::numeric_limits<int64_t>::max());
		return generateBool() ? newValue : -newValue;
	};

	test_generator() {
		auto fill = [&](auto& v) {
			auto arraySize01 = randomizeNumberNormal(35ull, 10ull);
			auto arraySize02 = randomizeNumberNormal(15ull, 10ull);
			auto arraySize03 = randomizeNumberNormal(5ull, 1ull);
			v.resize(arraySize01);
			for (uint64_t x = 0; x < arraySize01; ++x) {
				auto arraySize01 = randomizeNumberNormal(arraySize02, arraySize03);
				for (uint64_t y = 0; y < arraySize01; ++y) {
					auto newString = generateString();
					v[x].testStrings.emplace_back(newString);
				}
				arraySize01 = randomizeNumberNormal(arraySize02, arraySize03);
				for (uint64_t y = 0; y < arraySize01; ++y) {
					v[x].testUints.emplace_back(generateUint());
				}
				arraySize01 = randomizeNumberNormal(arraySize02, arraySize03);
				for (uint64_t y = 0; y < arraySize01; ++y) {
					v[x].testInts.emplace_back(generateInt());
				}
				arraySize01 = randomizeNumberNormal(arraySize02, arraySize03);
				for (uint64_t y = 0; y < arraySize01; ++y) {
					auto newBool = generateBool();
					v[x].testBools.emplace_back(newBool);
				}
				arraySize01 = randomizeNumberNormal(arraySize02, arraySize03);
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

struct test_element_final {
	std::string libraryName{};
	std::string resultType{};
	double resultSpeed{};
	double Mape{};
	std::string color{};
	bool operator>(const test_element_final& other) const {
		return resultSpeed > other.resultSpeed;
	}
};

struct test_element_pair {
	test_element_final writeData{};
	test_element_final readData{};
	bool operator>(const test_element_pair& other) const {
		return writeData > other.writeData && readData > other.readData;
	}
};

struct test_elements_final {
	std::vector<test_element_final> results{};
	std::string testName{};
};

using test_results_final = std::vector<test_elements_final>;

template<> struct jsonifier::core<test_element_final> {
	using value_type				 = test_element_final;
	static constexpr auto parseValue = createValue<&value_type::libraryName, &value_type::resultType, &value_type::resultSpeed, &value_type::Mape, &value_type::color>();
};

template<> struct jsonifier::core<test_elements_final> {
	using value_type				 = test_elements_final;
	static constexpr auto parseValue = createValue<&value_type::results, &value_type::testName>();
};

template<typename value_type> struct abc_test {
	std::vector<value_type> z, y, x, w, v, u, t, s, r, q, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a;
};

template<> struct jsonifier::core<test_struct> {
	using value_type				 = test_struct;
	static constexpr auto parseValue = createValue<&value_type::testStrings, &value_type::testUints, &value_type::testDoubles, &value_type::testInts, &value_type::testBools>();
};

template<> struct jsonifier::core<test<test_struct>> {
	using value_type				 = test<test_struct>;
	static constexpr auto parseValue = createValue<&value_type::a, &value_type::b, &value_type::c, &value_type::d, &value_type::e, &value_type::f, &value_type::g, &value_type::h,
		&value_type::i, &value_type::j, &value_type::k, &value_type::l, &value_type::m, &value_type::n, &value_type::o, &value_type::p, &value_type::q, &value_type::r,
		&value_type::s, &value_type::t, &value_type::u, &value_type::v, &value_type::w, &value_type::x, &value_type::y, &value_type::z>();
};

template<> struct jsonifier::core<test_generator<test_struct>> {
	using value_type				 = test_generator<test_struct>;
	static constexpr auto parseValue = createValue<&value_type::a, &value_type::b, &value_type::c, &value_type::d, &value_type::e, &value_type::f, &value_type::g, &value_type::h,
		&value_type::i, &value_type::j, &value_type::k, &value_type::l, &value_type::m, &value_type::n, &value_type::o, &value_type::p, &value_type::q, &value_type::r,
		&value_type::s, &value_type::t, &value_type::u, &value_type::v, &value_type::w, &value_type::x, &value_type::y, &value_type::z>();
};

template<> struct jsonifier::core<abc_test<test_struct>> {
	using value_type				 = abc_test<test_struct>;
	static constexpr auto parseValue = createValue<&value_type::z, &value_type::y, &value_type::x, &value_type::w, &value_type::v, &value_type::u, &value_type::t, &value_type::s,
		&value_type::r, &value_type::q, &value_type::p, &value_type::o, &value_type::n, &value_type::m, &value_type::l, &value_type::k, &value_type::j, &value_type::i,
		&value_type::h, &value_type::g, &value_type::f, &value_type::e, &value_type::d, &value_type::c, &value_type::b, &value_type::a>();
};

#if !defined(ASAN)

template<> struct glz::meta<test_struct> {
	using value_type			= test_struct;
	static constexpr auto value = object("testStrings", &value_type::testStrings, "testUints", &value_type::testUints, "testDoubles", &value_type::testDoubles, "testInts",
		&value_type::testInts, "testBools", &value_type::testBools);
};

template<> struct glz::meta<test<test_struct>> {
	using value_type			= test<test_struct>;
	static constexpr auto value = object("a", &value_type::a, "b", &value_type::b, "c", &value_type::c, "d", &value_type::d, "e", &value_type::e, "f", &value_type::f, "g",
		&value_type::g, "h", &value_type::h, "i", &value_type::i, "j", &value_type::j, "k", &value_type::k, "l", &value_type::l, "m", &value_type::m, "n", &value_type::n, "o",
		&value_type::o, "p", &value_type::p, "q", &value_type::q, "r", &value_type::r, "s", &value_type::s, "t", &value_type::t, "u", &value_type::u, "v", &value_type::v, "w",
		&value_type::w, "x", &value_type::x, "y", &value_type::y, "z", &value_type::z);
};

template<> struct glz::meta<test_generator<test_struct>> {
	using value_type			= test_generator<test_struct>;
	static constexpr auto value = object("a", &value_type::a, "b", &value_type::b, "c", &value_type::c, "d", &value_type::d, "e", &value_type::e, "f", &value_type::f, "g",
		&value_type::g, "h", &value_type::h, "i", &value_type::i, "j", &value_type::j, "k", &value_type::k, "l", &value_type::l, "m", &value_type::m, "n", &value_type::n, "o",
		&value_type::o, "p", &value_type::p, "q", &value_type::q, "r", &value_type::r, "s", &value_type::s, "t", &value_type::t, "u", &value_type::u, "v", &value_type::v, "w",
		&value_type::w, "x", &value_type::x, "y", &value_type::y, "z", &value_type::z);
};

template<> struct glz::meta<abc_test<test_struct>> {
	using value_type			= abc_test<test_struct>;
	static constexpr auto value = object("z", &value_type::z, "y", &value_type::y, "x", &value_type::x, "w", &value_type::w, "v", &value_type::v, "u", &value_type::u, "t",
		&value_type::t, "s", &value_type::s, "r", &value_type::r, "q", &value_type::q, "p", &value_type::p, "o", &value_type::o, "n", &value_type::n, "m", &value_type::m, "l",
		&value_type::l, "k", &value_type::k, "j", &value_type::j, "i", &value_type::i, "h", &value_type::h, "g", &value_type::g, "f", &value_type::f, "e", &value_type::e, "d",
		&value_type::d, "c", &value_type::c, "b", &value_type::b, "a", &value_type::a);
};

#endif

#if defined(NDEBUG) && !defined(ASAN)
constexpr uint64_t iterationsVal = 400;
#else
constexpr uint64_t iterationsVal = 1;
#endif

enum class result_type { read = 0, write = 1 };

template<result_type type> std::string enumToString() {
	return type == result_type::read ? "Read" : "Write";
}

struct benchmark_results {
	double resultTime{};
	double Mape{};
};

template<result_type type> struct result {
	std::optional<uint64_t> byteLength{};
	std::optional<double> jsonSpeed{};
	std::optional<double> jsonTime{};
	std::optional<double> Mape{};
	std::string color{};

	result& operator=(result&&) noexcept	  = default;
	result(result&&) noexcept				  = default;
	result& operator=(const result&) noexcept = default;
	result(const result&) noexcept			  = default;

	result() noexcept = default;

	result(const std::string& colorNew, uint64_t byteLengthNew, const benchmark_results& results) {
		byteLength.emplace(byteLengthNew);
		jsonTime.emplace(results.resultTime);
		Mape.emplace(results.Mape * 100.0f);
		auto mbWrittenCount	  = static_cast<double>(byteLength.value()) / 1e+6l;
		auto writeSecondCount = jsonTime.value() / 1e+9l;
		jsonSpeed.emplace(mbWrittenCount / writeSecondCount);
		color = colorNew;
	}

	operator bool() const {
		return jsonSpeed.has_value();
	}

	bool operator>(const result& other) const {
		if (jsonSpeed.has_value() && other.jsonSpeed.has_value()) {
			return this->jsonSpeed.value() > other.jsonSpeed.value();
		} else if (!jsonSpeed.has_value()) {
			return false;
		} else if (!other.jsonSpeed.has_value()) {
			return true;
		}
		return false;
	}
};

struct results_data {
	std::unordered_set<std::string> jsonifierExcludedKeys{};
	result<result_type::write> writeResult{};
	result<result_type::read> readResult{};
	uint64_t iterations{};
	std::string name{};
	std::string test{};
	std::string url{};

	bool operator>(const results_data& other) const {
		if (readResult && other.readResult) {
			return readResult > other.readResult;
		} else if (writeResult && other.writeResult) {
			return writeResult > other.writeResult;
		} else {
			return false;
		}
	}

	results_data& operator=(results_data&&) noexcept	  = default;
	results_data(results_data&&) noexcept				  = default;
	results_data& operator=(const results_data&) noexcept = default;
	results_data(const results_data&) noexcept			  = default;

	results_data() noexcept = default;

	results_data(const std::string& nameNew, const std::string& testNew, const std::string& urlNew, uint64_t iterationsNew) {
		iterations = iterationsNew;
		name	   = nameNew;
		test	   = testNew;
		url		   = urlNew;
	}

	void checkForMissingKeys() {
		if (!writeResult.jsonSpeed.has_value()) {
			jsonifierExcludedKeys.emplace("writeResult");
		} else if (!readResult.jsonSpeed.has_value()) {
			jsonifierExcludedKeys.emplace("readResult");
		}
	}

	void print() const {
		std::cout << std::string{ "| " } + name + " " + test + ": " + url + "\n" +
				"| ------------------------------------------------------------ "
				"|\n";
		if (readResult.byteLength.has_value() && readResult.jsonSpeed.has_value()) {
			std::cout << enumToString<result_type::read>() + " Speed (MB/S): " << std::setprecision(6) << readResult.jsonSpeed.value() << std::endl;
			std::cout << enumToString<result_type::read>() + " Length (Bytes): " << readResult.byteLength.value() << std::endl;
			std::cout << enumToString<result_type::read>() + " Runtime (ns): " << std::setprecision(6) << readResult.jsonTime.value() << std::endl;
			std::cout << enumToString<result_type::read>() + " Mape (%): " << std::setprecision(4) << readResult.Mape.value() << std::endl;
		}
		if (writeResult.byteLength.has_value() && writeResult.jsonSpeed.has_value()) {
			std::cout << enumToString<result_type::write>() + " Speed (MB/S): " << std::setprecision(6) << writeResult.jsonSpeed.value() << std::endl;
			std::cout << enumToString<result_type::write>() + " Length (Bytes): " << writeResult.byteLength.value() << std::endl;
			std::cout << enumToString<result_type::write>() + " Runtime (ns): " << std::setprecision(6) << writeResult.jsonTime.value() << std::endl;
			std::cout << enumToString<result_type::write>() + " Mape (%): " << std::setprecision(4) << writeResult.Mape.value() << std::endl;
		}
		std::cout << "\n---" << std::endl;
	}

	std::string jsonStats() const {
		std::string writeLength{};
		std::string writeTime{};
		std::string writeMape{};
		std::string write{};
		std::string readLength{};
		std::string readTime{};
		std::string readMape{};
		std::string read{};
		std::string finalString{ "| [" + name + "](" + url + ") | " };
		if (readResult.jsonTime.has_value() && readResult.byteLength.has_value()) {
			std::stringstream stream01{};
			stream01 << std::setprecision(6) << readResult.jsonSpeed.value();
			read = stream01.str();
			std::stringstream stream02{};
			stream02 << readResult.byteLength.value();
			readLength = stream02.str();
			std::stringstream stream03{};
			stream03 << std::setprecision(6) << readResult.jsonTime.value();
			readTime = stream03.str();
			std::stringstream stream04{};
			stream04 << std::setprecision(4) << readResult.Mape.value();
			readMape = stream04.str();
			finalString += read + " | " + readLength + " | " + readTime + " | " + readMape + " | ";
		} else {
			readLength = "N/A";
			readTime   = "N/A";
			read	   = "N/A";
			readMape   = "N/A";
		}
		if (writeResult.jsonTime.has_value() && writeResult.byteLength.has_value()) {
			std::stringstream stream01{};
			stream01 << std::setprecision(6) << writeResult.jsonSpeed.value();
			write = stream01.str();
			std::stringstream stream02{};
			stream02 << writeResult.byteLength.value();
			writeLength = stream02.str();
			std::stringstream stream03{};
			stream03 << std::setprecision(6) << writeResult.jsonTime.value();
			writeTime = stream03.str();
			std::stringstream stream04{};
			stream04 << std::setprecision(4) << writeResult.Mape.value();
			writeMape = stream04.str();
			finalString += write + " | " + writeLength + " | " + writeTime + " | " + writeMape + " |";
		} else {
			writeLength = "N/A";
			writeTime	= "N/A";
			write		= "N/A";
			writeMape	= "N/A";
		}
		return finalString;
	}
};

struct test_results {
	std::vector<results_data> results{};
	std::string markdownResults{};
	std::string testName{};
};

template<result_type type> struct jsonifier::core<result<type>> {
	using value_type				 = result<type>;
	static constexpr auto parseValue = createValue<&value_type::byteLength, &value_type::jsonSpeed, &value_type::jsonTime, &value_type::color>();
};

template<> struct jsonifier::core<results_data> {
	using value_type				 = results_data;
	static constexpr auto parseValue = createValue<&value_type::name, &value_type::readResult, &value_type::writeResult, &value_type::test, &value_type::url>();
};

template<> struct jsonifier::core<test_results> {
	using value_type				 = test_results;
	static constexpr auto parseValue = createValue<&value_type::results, &value_type::testName>();
};

#if defined(JSONIFIER_MSVC)

	#define NEVER_INLINE __declspec(noinline)
	#define rdtsc() __rdtsc()

#else

	#define NEVER_INLINE __attribute__((noinline))

__inline__ uint64_t rdtsc() {
	#ifdef __x86_64__
	unsigned int a, d;
	__asm__ volatile("rdtsc" : "=a"(a), "=d"(d));
	return ( unsigned long )a | (( unsigned long )d << 32);
	#elif defined(__i386__)
	uint64_t x;
	__asm__ volatile("rdtsc" : "=A"(x));
	return x;
	#else
		#define NO_CYCLE_COUNTER
	return 0;
	#endif
}
#endif

double cyclesToTime(uint64_t cycles, double frequencyMHz) {
	return (static_cast<double>(cycles) * 1e9) / (frequencyMHz * 1e6);
}

#if defined(JSONIFIER_WIN)
	#include <Windows.h>
	#include <Pdh.h>
	#pragma comment(lib, "Pdh.lib")

double getCpuFrequency() {
	LARGE_INTEGER qwWait, qwStart, qwCurrent;
	QueryPerformanceCounter(&qwStart);
	QueryPerformanceFrequency(&qwWait);
	qwWait.QuadPart >>= 5;
	uint64_t start = __rdtsc();
	do {
		QueryPerformanceCounter(&qwCurrent);
	} while (qwCurrent.QuadPart - qwStart.QuadPart < qwWait.QuadPart);
	return static_cast<double>((__rdtsc() - start) << 5) / 1000000.0l;
}

template<typename function_type> NEVER_INLINE double collectTime(function_type&& functionNew, double cpuFrequency) {
	volatile uint64_t startTime{}, endTime{};
	startTime = rdtsc();
	functionNew();
	endTime = rdtsc();
	return cyclesToTime(endTime - startTime, cpuFrequency);
}

#elif defined(JSONIFIER_LINUX)
	#include <fstream>

double getCpuFrequency() {
	std::ifstream file("/proc/cpuinfo");
	if (!file.is_open()) {
		std::cerr << "Error opening /proc/cpuinfo" << std::endl;
		return 0.0;
	}

	std::string line;
	double frequency = 0.0;
	while (std::getline(file, line)) {
		if (line.find("cpu MHz") != std::string::npos) {
			size_t pos = line.find(":");
			if (pos != std::string::npos) {
				frequency = std::stod(line.substr(pos + 1));
				break;
			}
		}
	}
	file.close();

	return frequency;
}

template<typename function_type> NEVER_INLINE double collectTime(function_type&& functionNew, double cpuFrequency) {
	volatile uint64_t startTime{}, endTime{};
	startTime = rdtsc();
	functionNew();
	endTime = rdtsc();
	return cyclesToTime(endTime - startTime, cpuFrequency);
}

#elif defined(JSONIFIER_MAC)
	#include <sys/sysctl.h>

double getCpuFrequency() {
	return 0;
}

template<typename function_type> NEVER_INLINE double collectTime(function_type&& functionNew, double cpuFrequency) {
	auto startTime = std::chrono::high_resolution_clock::now();
	functionNew();
	auto endTime = std::chrono::high_resolution_clock::now();
	return std::chrono::duration_cast<std::chrono::duration<double, std::nano>>(endTime - startTime).count();
}

#else

uint64_t collectTime(function_type&& functionNew, uint64_t cpuFrequency) {
	return 0.0;
}

#endif

#if defined(small)
	#undef small
#endif

static void const volatile* volatile globalForceEscapePointer;

void useCharPointer(char const volatile* const v) {
	globalForceEscapePointer = reinterpret_cast<void const volatile*>(v);
}

template<typename value_type> using unwrap_t = jsonifier_internal::unwrap_t<value_type>;

template<typename function_type, typename... arg_types> struct return_type_helper {
	using type = std::invoke_result_t<function_type, arg_types...>;
};

template<typename value_type, typename... arg_types>
concept invocable = std::is_invocable_v<unwrap_t<value_type>, arg_types...>;

template<typename value_type, typename... arg_types>
concept not_invocable = !std::is_invocable_v<unwrap_t<value_type>, arg_types...>;

template<typename value_type, typename... arg_types>
concept invocable_void = invocable<value_type, arg_types...> && std::is_void_v<typename return_type_helper<value_type, arg_types...>::type>;

template<typename value_type, typename... arg_types>
concept invocable_not_void = invocable<value_type, arg_types...> && !std::is_void_v<typename return_type_helper<value_type, arg_types...>::type>;

#if defined(JSONIFIER_MSVC)
	#define doNotOptimize(value) \
		useCharPointer(&reinterpret_cast<char const volatile&>(value)); \
		_ReadWriteBarrier();
#elif defined(JSONIFIER_CLANG)
	#define doNotOptimize(value) asm volatile("" : "+r,m"(value) : : "memory");
#else
	#define doNotOptimize(value) asm volatile("" : "+m,r"(value) : : "memory");
#endif

template<not_invocable value_type> JSONIFIER_INLINE void doNotOptimizeAway(value_type&& value) {
	const auto* valuePtr = &value;
	doNotOptimize(valuePtr)
}

template<invocable_void function_type, typename... arg_types> JSONIFIER_INLINE void doNotOptimizeAway(function_type&& value, arg_types&&... args) {
	std::forward<function_type>(value)(std::forward<arg_types>(args)...);
	doNotOptimize(value);
}

template<invocable_not_void function_type, typename... arg_types> JSONIFIER_INLINE void doNotOptimizeAway(function_type&& value, arg_types&&... args) {
	auto resultVal = std::forward<function_type>(value)(std::forward<arg_types>(args)...);
	doNotOptimize(resultVal);
}

bool checkDoubleForValidLt(double valueToCheck, double valueToCheckAgainst) {
	return (valueToCheck != std::numeric_limits<double>::infinity() && valueToCheck != std::numeric_limits<double>::quiet_NaN() &&
			   valueToCheck != -std::numeric_limits<double>::infinity() && valueToCheck != -std::numeric_limits<double>::quiet_NaN()) &&
		valueToCheck < valueToCheckAgainst;
}

double calcMedian(jsonifier::vector<double>& data) {
	std::sort(data.begin(), data.end());
	auto midIdx = data.size() / 2U;
	if (1U == (data.size() & 1U)) {
		return data[midIdx];
	}
	return (data[midIdx - 1U] + data[midIdx]) / 2U;
}

double medianAbsolutePercentError(const jsonifier::vector<double>& data) {
	jsonifier::vector<double> dataNew{ data };
	if (dataNew.empty()) {
		return 0.0;
	}
	auto med = calcMedian(dataNew);
	for (double& x: dataNew) {
		x = (x - med) / x;
		if (x < 0.0f) {
			x = -x;
		}
	}
	return calcMedian(dataNew);
}

benchmark_results collectMape(auto lambda, uint64_t maxIterationCount, uint64_t minIterationCount) {
	double medianAbsolutePercentageError{};
	jsonifier::vector<double> durations{};
	auto newFunction{ lambda };
	jsonifier::vector<decltype(newFunction)> lambdasNew{};
	for (uint64_t x = 0; x < maxIterationCount; ++x) {
		lambdasNew.emplace_back(newFunction);
	}
	uint64_t currentIterationCount{};
	while (currentIterationCount < maxIterationCount) {
		auto duration = collectTime(lambdasNew[currentIterationCount], getCpuFrequency());
		durations.emplace_back(duration);

		if (currentIterationCount > minIterationCount) {
			medianAbsolutePercentageError = medianAbsolutePercentError(durations);
		}
		if (currentIterationCount > minIterationCount && checkDoubleForValidLt(medianAbsolutePercentageError, 0.05)) {
			return { durations[currentIterationCount - 1], medianAbsolutePercentageError };
		}

		++currentIterationCount;
	}
#if !defined(ASAN)
	if (medianAbsolutePercentageError >= 0.05) {
		return collectMape(newFunction, maxIterationCount * 2, minIterationCount);
	} else {
#endif
		return { durations[currentIterationCount - 1], medianAbsolutePercentageError };
#if !defined(ASAN)
	}
#endif
}

template<uint64_t iterationCount, typename function_type> benchmark_results benchmark(function_type&& function) {
	static constexpr int64_t warmupCount	   = iterationCount;
	static constexpr int64_t minIterationCount = static_cast<int64_t>(static_cast<float>(iterationCount) * 0.10f);
	using function_type_final				   = jsonifier_internal::unwrap_t<function_type>;
	function_type_final functionNew{ function };

	jsonifier::vector<function_type_final> warmupLambdas{};
	for (uint64_t x = 0; x < warmupCount; ++x) {
		warmupLambdas.emplace_back(functionNew);
	}

	int64_t currentIterationCount = 0;

	while (currentIterationCount < warmupCount) {
		doNotOptimizeAway(std::move(warmupLambdas[currentIterationCount]));
		++currentIterationCount;
	}
	return collectMape(functionNew, iterationCount, minIterationCount);
}

enum class test_type {
	parse_and_serialize = 0,
	minify				= 1,
	prettify			= 2,
	validate			= 3,
};

enum class json_library {
	jsonifier = 0,
	glaze	  = 1,
	simdjson  = 2,
};

const std::string basePath{ JSON_PATH };

template<json_library lib, test_type type, typename test_data_type, bool minified, uint64_t iterations> struct json_test_helper;

template<typename test_data_type, bool minified, uint64_t iterations>
struct json_test_helper<json_library::jsonifier, test_type::parse_and_serialize, test_data_type, minified, iterations> {
	static auto run(const std::string& newBuffer, const std::string& testName, bool doWePrint = true) {
		const std::string buffer{ newBuffer };

		results_data r{ "jsonifier", testName, "https://github.com/realtimechris/jsonifier", iterations };
		jsonifier::jsonifier_core parser{};
		test_data_type testData{};
		auto readResult = benchmark<iterations>([&]() {
			parser.parseJson<jsonifier::parse_options{ .minified = minified }>(testData, buffer);
			auto* newPtr = &testData;
			doNotOptimizeAway(newPtr);
		});
		for (auto& value: parser.getErrors()) {
			std::cout << "Jsonifier Error: " << value << std::endl;
		}
		std::string newerBuffer{};
		auto readSize	 = buffer.size();
		auto writeResult = benchmark<iterations>([&]() {
			parser.serializeJson<jsonifier::serialize_options{ .prettify = !minified }>(testData, newerBuffer);
			auto* newPtr = &newerBuffer;
			doNotOptimizeAway(newPtr);
		});

		for (auto& value: parser.getErrors()) {
			std::cout << "Jsonifier Error: " << value << std::endl;
		}

		auto writtenSize = newerBuffer.size();
		r.readResult	 = result<result_type::read>{ "teal", readSize, readResult };
		r.writeResult	 = result<result_type::write>{ "steelblue", writtenSize, writeResult };
		file_loader fileLoader{ basePath + "/" + testName + "-jsonifier.json" };
		fileLoader.saveFile(buffer);
		if (doWePrint) {
			r.print();
		}

		return r;
	}
};

template<uint64_t iterations> struct json_test_helper<json_library::jsonifier, test_type::prettify, std::string, false, iterations> {
	static auto run(const std::string& newBuffer, const std::string& testName, bool doWePrint = true) {
		const std::string buffer{ newBuffer };

		results_data r{ "jsonifier", testName, "https://github.com/realtimechris/jsonifier", iterations };
		jsonifier::jsonifier_core parser{};
		std::string newerBuffer{};
		auto writeResult = benchmark<iterations>([&]() {
			parser.prettifyJson(buffer, newerBuffer);
			doNotOptimizeAway(newerBuffer);
		});
		for (auto& value: parser.getErrors()) {
			std::cout << "Jsonifier Error: " << value << std::endl;
		}
		file_loader fileLoader{ basePath + "/" + testName + "-jsonifier.json" };
		fileLoader.saveFile(newerBuffer);

		r.writeResult = result<result_type::write>{ "steelblue", newerBuffer.size(), writeResult };

		if (doWePrint) {
			r.print();
		}

		return r;
	}
};

template<uint64_t iterations> struct json_test_helper<json_library::jsonifier, test_type::minify, std::string, false, iterations> {
	static auto run(const std::string& newBuffer, const std::string& testName, bool doWePrint = true) {
		const std::string buffer{ newBuffer };
		std::string newerBuffer{};
		results_data r{ "jsonifier", testName, "https://github.com/realtimechris/jsonifier", iterations };
		jsonifier::jsonifier_core parser{};
		auto writeResult = benchmark<iterations>([&]() {
			parser.minifyJson(buffer, newerBuffer);
			doNotOptimizeAway(newerBuffer);
		});
		for (auto& value: parser.getErrors()) {
			std::cout << "Jsonifier Error: " << value << std::endl;
		}
		file_loader fileLoader{ basePath + "/" + testName + "-jsonifier.json" };
		fileLoader.saveFile(newerBuffer);

		r.writeResult = result<result_type::write>{ "steelblue", newerBuffer.size(), writeResult };
		;

		if (doWePrint) {
			r.print();
		}
		return r;
	}
};

template<uint64_t iterations> struct json_test_helper<json_library::jsonifier, test_type::validate, std::string, false, iterations> {
	static auto run(const std::string& newBuffer, const std::string& testName, bool doWePrint = true) {
		const std::string buffer{ newBuffer };

		results_data r{ "jsonifier", testName, "https://github.com/realtimechris/jsonifier", iterations };
		jsonifier::jsonifier_core parser{};

		auto readResult = benchmark<iterations>([&]() {
			parser.validateJson(buffer);
			doNotOptimizeAway(buffer);
		});

		for (auto& value: parser.getErrors()) {
			std::cout << "Jsonifier Error: " << value << std::endl;
		}

		r.readResult = result<result_type::read>{ "teal", buffer.size(), readResult };

		if (doWePrint) {
			r.print();
		}


		return r;
	}
};

#if !defined(ASAN)
template<typename test_data_type, bool minified, uint64_t iterations>
struct json_test_helper<json_library::glaze, test_type::parse_and_serialize, test_data_type, minified, iterations> {
	static auto run(const std::string& newBuffer, const std::string& testName, bool doWePrint = true) {
		const std::string buffer{ newBuffer };

		results_data r{ "glaze", testName, "https://github.com/stephenberry/glaze", iterations };
		test_data_type testData{};
		auto readResult = benchmark<iterations>([&]() {
			if (auto error = glz::read<glz::opts{ .skip_null_members = false, .minified = minified, .force_conformance = true }>(testData, buffer); error) {
				std::cout << "Glaze Error: " << glz::format_error(error, buffer) << std::endl;
			}
			auto* newPtr = &testData;
			doNotOptimizeAway(newPtr);
		});
		std::string newerBuffer{};
		auto readSize	 = buffer.size();
		auto writeResult = benchmark<iterations>([&]() {
			doNotOptimizeAway(glz::write<glz::opts{ .skip_null_members = false, .prettify = !minified, .minified = minified, .force_conformance = true }>(testData, newerBuffer));
			auto* newPtr = &newerBuffer;
			doNotOptimizeAway(newPtr);
		});

		auto writtenSize = newerBuffer.size();
		r.readResult	 = result<result_type::read>{ "dodgerblue", readSize, readResult };
		r.writeResult	 = result<result_type::write>{ "skyblue", writtenSize, writeResult };
		file_loader fileLoader{ basePath + "/" + testName + "-glaze.json" };
		fileLoader.saveFile(buffer);
		if (doWePrint) {
			r.print();
		}

		return r;
	}
};

template<uint64_t iterations> struct json_test_helper<json_library::glaze, test_type::prettify, std::string, false, iterations> {
	static auto run(const std::string& newBuffer, const std::string& testName, bool doWePrint = true) {
		const std::string buffer{ newBuffer };

		results_data r{ "glaze", testName, "https://github.com/stephenberry/glaze", iterations };
		std::string newerBuffer{};
		auto writeResult = benchmark<iterations>([&]() {
			glz::prettify_json(buffer, newerBuffer);
			doNotOptimizeAway(newerBuffer);
		});

		file_loader fileLoader{ basePath + "/" + testName + "-glaze.json" };
		fileLoader.saveFile(newerBuffer);
		r.writeResult = result<result_type::write>{ "skyblue", newerBuffer.size(), writeResult };
		if (doWePrint) {
			r.print();
		}

		return r;
	}
};

template<uint64_t iterations> struct json_test_helper<json_library::glaze, test_type::minify, std::string, false, iterations> {
	static auto run(const std::string& newBuffer, const std::string& testName, bool doWePrint = true) {
		const std::string buffer{ newBuffer };

		results_data r{ "glaze", testName, "https://github.com/stephenberry/glaze", iterations };
		std::string newerBuffer{};
		auto writeResult = benchmark<iterations>([&]() {
			glz::minify_json(buffer, newerBuffer);
			doNotOptimizeAway(newerBuffer);
		});

		file_loader fileLoader{ basePath + "/" + testName + "-glaze.json" };
		fileLoader.saveFile(newerBuffer);
		r.writeResult = result<result_type::write>{ "skyblue", newerBuffer.size(), writeResult };
		if (doWePrint) {
			r.print();
		}

		return r;
	}
};

	#include "simdjson.h"

template<typename value_type> void getValue(value_type& valueNew, simdjson::ondemand::value value) {
	value.get(valueNew);
}

template<jsonifier::concepts::bool_t value_type> void getValue(value_type&& valueNew, simdjson::ondemand::value value) {
	getValue<bool>(valueNew, value);
}

template<> void getValue(std::nullptr_t&, simdjson::ondemand::value) {
}

template<jsonifier::concepts::vector_t value_type> void getValue(value_type& valueNew, simdjson::ondemand::value value) {
	simdjson::ondemand::array result;
	auto oldSize = valueNew.size();
	if (auto resultCode = value.get(result); !resultCode) {
		auto iter = result.begin();
		for (uint64_t x = 0; x < oldSize && iter != result.end(); ++x, ++iter) {
			getValue(valueNew[x], iter.operator*().value());
		}
		for (; iter != result.end(); ++iter) {
			getValue(valueNew.emplace_back(), iter.operator*().value());
		}
	}
}

template<> void getValue<std::string>(std::string& valueNew, simdjson::ondemand::value value) {
	std::string_view result;
	if (auto resultCode = value.get(result); !resultCode) {
		valueNew = static_cast<std::string>(result);
	}
}

template<jsonifier::concepts::optional_t value_type> void getValue(value_type& valueNew, simdjson::ondemand::value valueNewer) {
	simdjson::ondemand::value result;
	if (auto resultCode = valueNewer.get(result); !resultCode) {
		getValue(valueNew.emplace(), result);
	}
}

template<jsonifier::concepts::optional_t value_type> void getValue(value_type& returnValue, simdjson::ondemand::value value, const std::string& key) {
	simdjson::ondemand::value result;
	if (auto resultCode = value[key].get(result); !resultCode) {
		if (result.type() != simdjson::ondemand::json_type::null) {
			getValue(returnValue.emplace(), result);
		}
	}
}

template<typename value_type> void getValue(value_type& returnValue, simdjson::ondemand::value value, const std::string& key) {
	simdjson::ondemand::value result;
	if (auto resultCode = value[key].get(result); !resultCode) {
		getValue(returnValue, result);
	}
}

template<> void getValue(std::nullptr_t&, simdjson::ondemand::value, const std::string&) {
}

template<jsonifier::concepts::vector_t value_type> void getValue(value_type& returnValues, simdjson::ondemand::value value, const std::string& key) {
	simdjson::ondemand::array result;
	if (auto resultCode = value[key].get(result); !resultCode) {
		auto oldSize = returnValues.size();
		auto iter	 = result.begin();
		for (uint64_t x = 0; iter != result.end() && x < oldSize; ++x, ++iter) {
			getValue(returnValues[x], iter.operator*().value());
		}
		for (; iter != result.end(); ++iter) {
			getValue(returnValues.emplace_back(), iter.operator*().value());
		}
	}
	return;
}

template<jsonifier::concepts::map_t value_type> void getValue(value_type& returnValues, simdjson::ondemand::value value, const std::string& key) {
	simdjson::ondemand::object result;
	if (auto resultCode = value[key].get(result); !resultCode) {
		auto oldSize = returnValues.size();
		auto iter	 = result.begin();
		for (uint64_t x = 0; iter != result.end() && x < oldSize; ++x, ++iter) {
			typename value_type::mapped_type returnValue{};
			getValue(returnValue, iter.operator*().value());
			returnValues[static_cast<typename value_type::key_type>(iter.operator*().key().raw())] = std::move(returnValue);
		}
		for (; iter != result.end(); ++iter) {
			typename value_type::mapped_type returnValue{};
			getValue(returnValue, iter.operator*().value());
			returnValues[static_cast<typename value_type::key_type>(iter.operator*().key().raw())] = std::move(returnValue);
		}
	}
	return;
}

template<> void getValue(geometry_data& returnValue, simdjson::ondemand::value jsonDataNew) {
	getValue(returnValue.coordinates, jsonDataNew, "coordinates");
	getValue(returnValue.type, jsonDataNew, "type");
}

template<> void getValue(properties_data& returnValue, simdjson::ondemand::value jsonDataNew) {
	getValue(returnValue.name, jsonDataNew, "name");
}

template<> void getValue(feature& returnValue, simdjson::ondemand::value jsonDataNew) {
	getValue(returnValue.properties, jsonDataNew, "properties");
	getValue(returnValue.geometry, jsonDataNew, "geometry");
	getValue(returnValue.type, jsonDataNew, "type");
}

template<> void getValue(canada_message& returnValue, simdjson::ondemand::value jsonDataNew) {
	getValue(returnValue.features, jsonDataNew, "features");
	getValue(returnValue.type, jsonDataNew, "type");
}

template<> void getValue(search_metadata_data& returnValue, simdjson::ondemand::value jsonDataNew) {
	getValue(returnValue.since_id_str, jsonDataNew, "since_id_str");
	getValue(returnValue.next_results, jsonDataNew, "next_results");
	getValue(returnValue.refresh_url, jsonDataNew, "refresh_url");
	getValue(returnValue.max_id_str, jsonDataNew, "max_id_str");
	getValue(returnValue.completed_in, jsonDataNew, "completed_in");
	getValue(returnValue.query, jsonDataNew, "query");
	getValue(returnValue.since_id, jsonDataNew, "since_id");
	getValue(returnValue.count, jsonDataNew, "count");
	getValue(returnValue.max_id, jsonDataNew, "max_id");
}

template<> void getValue(hashtag& returnValue, simdjson::ondemand::value jsonDataNew) {
	getValue(returnValue.indices, jsonDataNew, "indices");
	getValue(returnValue.text, jsonDataNew, "text");
}

template<> void getValue(large_data& returnValue, simdjson::ondemand::value jsonDataNew) {
	getValue(returnValue.resize, jsonDataNew, "resize");
	getValue(returnValue.w, jsonDataNew, "w");
	getValue(returnValue.h, jsonDataNew, "h");
}

template<> void getValue(sizes_data& returnValue, simdjson::ondemand::value jsonDataNew) {
	getValue(returnValue.medium, jsonDataNew, "medium");
	getValue(returnValue.small, jsonDataNew, "small");
	getValue(returnValue.thumb, jsonDataNew, "thumb");
	getValue(returnValue.large, jsonDataNew, "large");
}

template<> void getValue(media_data& returnValue, simdjson::ondemand::value jsonDataNew) {
	getValue(returnValue.source_status_id_str, jsonDataNew, "source_status_id_str");
	getValue(returnValue.source_status_id, jsonDataNew, "source_status_id");
	getValue(returnValue.indices, jsonDataNew, "indices");
	getValue(returnValue.media_url_https, jsonDataNew, "media_url_https");
	getValue(returnValue.expanded_url, jsonDataNew, "expanded_url");
	getValue(returnValue.display_url, jsonDataNew, "display_url");
	getValue(returnValue.media_url, jsonDataNew, "media_url");
	getValue(returnValue.id_str, jsonDataNew, "id_str");
	getValue(returnValue.type, jsonDataNew, "type");
	getValue(returnValue.sizes, jsonDataNew, "sizes");
	getValue(returnValue.url, jsonDataNew, "url");
	getValue(returnValue.id, jsonDataNew, "id");
}

template<> void getValue(url_data& returnValue, simdjson::ondemand::value jsonDataNew) {
	getValue(returnValue.indices, jsonDataNew, "indices");
	getValue(returnValue.expanded_url, jsonDataNew, "expanded_url");
	getValue(returnValue.display_url, jsonDataNew, "display_url");
	getValue(returnValue.url, jsonDataNew, "url");
}

template<> void getValue(user_mention& returnValue, simdjson::ondemand::value jsonDataNew) {
	getValue(returnValue.indices, jsonDataNew, "indices");
	getValue(returnValue.screen_name, jsonDataNew, "screen_name");
	getValue(returnValue.id_str, jsonDataNew, "id_str");
	getValue(returnValue.name, jsonDataNew, "name");
	getValue(returnValue.id, jsonDataNew, "id");
}

template<> void getValue(status_entities& returnValue, simdjson::ondemand::value jsonDataNew) {
	getValue(returnValue.media, jsonDataNew, "media");
	getValue(returnValue.user_mentions, jsonDataNew, "user_mentions");
	getValue(returnValue.symbols, jsonDataNew, "symbols");
	getValue(returnValue.hashtags, jsonDataNew, "hashtags");
	getValue(returnValue.urls, jsonDataNew, "urls");
}

template<> void getValue(metadata_data& returnValue, simdjson::ondemand::value jsonDataNew) {
	getValue(returnValue.iso_language_code, jsonDataNew, "iso_language_code");
	getValue(returnValue.result_type, jsonDataNew, "result_type");
}

template<> void getValue(description_data& returnValue, simdjson::ondemand::value jsonDataNew) {
	getValue(returnValue.urls, jsonDataNew, "urls");
}

template<> void getValue(user_entities& returnValue, simdjson::ondemand::value jsonDataNew) {
	getValue(returnValue.url, jsonDataNew, "url");
	getValue(returnValue.description, jsonDataNew, "description");
}

template<> void getValue(twitter_user& returnValue, simdjson::ondemand::value jsonDataNew) {
	getValue(returnValue.profile_background_image_url_https, jsonDataNew, "profile_background_image_url_https");
	getValue(returnValue.profile_banner_url, jsonDataNew, "profile_banner_url");
	getValue(returnValue.profile_background_image_url, jsonDataNew, "profile_background_image_url");
	getValue(returnValue.profile_sidebar_fill_color, jsonDataNew, "profile_sidebar_fill_color");
	getValue(returnValue.time_zone, jsonDataNew, "time_zone");
	getValue(returnValue.profile_background_color, jsonDataNew, "profile_background_color");
	getValue(returnValue.profile_image_url_https, jsonDataNew, "profile_image_url_https");
	getValue(returnValue.utc_offset, jsonDataNew, "utc_offset");
	getValue(returnValue.profile_use_background_image, jsonDataNew, "profile_use_background_image");
	getValue(returnValue.url, jsonDataNew, "url");
	getValue(returnValue.profile_text_color, jsonDataNew, "profile_text_color");
	getValue(returnValue.profile_link_color, jsonDataNew, "profile_link_color");
	getValue(returnValue.profile_image_url, jsonDataNew, "profile_image_url");
	getValue(returnValue.profile_background_tile, jsonDataNew, "profile_background_tile");
	getValue(returnValue.is_translation_enabled, jsonDataNew, "is_translation_enabled");
	getValue(returnValue.default_profile_image, jsonDataNew, "default_profile_image");
	getValue(returnValue.contributors_enabled, jsonDataNew, "contributors_enabled");
	getValue(returnValue.follow_request_sent, jsonDataNew, "follow_request_sent");
	getValue(returnValue.favourites_count, jsonDataNew, "favourites_count");
	getValue(returnValue.description, jsonDataNew, "description");
	getValue(returnValue.screen_name, jsonDataNew, "screen_name");
	getValue(returnValue.followers_count, jsonDataNew, "followers_count");
	getValue(returnValue.statuses_count, jsonDataNew, "statuses_count");
	getValue(returnValue.created_at, jsonDataNew, "created_at");
	getValue(returnValue.entities, jsonDataNew, "entities");
	getValue(returnValue.friends_count, jsonDataNew, "friends_count");
	getValue(returnValue.default_profile, jsonDataNew, "default_profile");
	getValue(returnValue.listed_count, jsonDataNew, "listed_count");
	getValue(returnValue.location, jsonDataNew, "location");
	getValue(returnValue.user_protected, jsonDataNew, "user_protected");
	getValue(returnValue.is_translator, jsonDataNew, "is_translator");
	getValue(returnValue.id_str, jsonDataNew, "id_str");
	getValue(returnValue.notifications, jsonDataNew, "notifications");
	getValue(returnValue.string, jsonDataNew, "string");
	getValue(returnValue.name, jsonDataNew, "name");
	getValue(returnValue.geo_enabled, jsonDataNew, "geo_enabled");
	getValue(returnValue.lang, jsonDataNew, "lang");
	getValue(returnValue.following, jsonDataNew, "following");
	getValue(returnValue.verified, jsonDataNew, "verified");
	getValue(returnValue.id, jsonDataNew, "id");
}

template<> void getValue(retweeted_status_data& returnValue, simdjson::ondemand::value jsonDataNew) {
	getValue(returnValue.in_reply_to_status_id_str, jsonDataNew, "in_reply_to_status_id_str");
	getValue(returnValue.in_reply_to_user_id_str, jsonDataNew, "in_reply_to_user_id_str");
	getValue(returnValue.in_reply_to_screen_name, jsonDataNew, "in_reply_to_screen_name");
	getValue(returnValue.in_reply_to_status_id, jsonDataNew, "in_reply_to_status_id");
	getValue(returnValue.in_reply_to_user_id, jsonDataNew, "in_reply_to_user_id");
	getValue(returnValue.possibly_sensitive, jsonDataNew, "possibly_sensitive");
	getValue(returnValue.contributors, jsonDataNew, "contributors");
	getValue(returnValue.coordinates, jsonDataNew, "coordinates");
	getValue(returnValue.place, jsonDataNew, "place");
	getValue(returnValue.geo, jsonDataNew, "geo");
	getValue(returnValue.entities, jsonDataNew, "entities");
	getValue(returnValue.favorite_count, jsonDataNew, "favorite_count");
	getValue(returnValue.metadata, jsonDataNew, "metadata");
	getValue(returnValue.created_at, jsonDataNew, "created_at");
	getValue(returnValue.retweet_count, jsonDataNew, "retweet_count");
	getValue(returnValue.source, jsonDataNew, "source");
	getValue(returnValue.id_str, jsonDataNew, "id_str");
	getValue(returnValue.user, jsonDataNew, "user");
	getValue(returnValue.lang, jsonDataNew, "lang");
	getValue(returnValue.text, jsonDataNew, "text");
	getValue(returnValue.truncated, jsonDataNew, "truncated");
	getValue(returnValue.favorited, jsonDataNew, "favorited");
	getValue(returnValue.retweeted, jsonDataNew, "retweeted");
	getValue(returnValue.id, jsonDataNew, "id");
}

template<> void getValue(status_data& returnValue, simdjson::ondemand::value jsonDataNew) {
	getValue(returnValue.in_reply_to_status_id_str, jsonDataNew, "in_reply_to_status_id_str");
	getValue(returnValue.in_reply_to_user_id_str, jsonDataNew, "in_reply_to_user_id_str");
	getValue(returnValue.in_reply_to_screen_name, jsonDataNew, "in_reply_to_screen_name");
	getValue(returnValue.in_reply_to_status_id, jsonDataNew, "in_reply_to_status_id");
	getValue(returnValue.in_reply_to_user_id, jsonDataNew, "in_reply_to_user_id");
	getValue(returnValue.possibly_sensitive, jsonDataNew, "possibly_sensitive");
	getValue(returnValue.contributors, jsonDataNew, "contributors");
	getValue(returnValue.coordinates, jsonDataNew, "coordinates");
	getValue(returnValue.place, jsonDataNew, "place");
	getValue(returnValue.geo, jsonDataNew, "geo");
	getValue(returnValue.entities, jsonDataNew, "entities");
	getValue(returnValue.favorite_count, jsonDataNew, "favorite_count");
	getValue(returnValue.metadata, jsonDataNew, "metadata");
	getValue(returnValue.created_at, jsonDataNew, "created_at");
	getValue(returnValue.retweet_count, jsonDataNew, "retweet_count");
	getValue(returnValue.source, jsonDataNew, "source");
	getValue(returnValue.id_str, jsonDataNew, "id_str");
	getValue(returnValue.user, jsonDataNew, "user");
	getValue(returnValue.lang, jsonDataNew, "lang");
	getValue(returnValue.text, jsonDataNew, "text");
	getValue(returnValue.truncated, jsonDataNew, "truncated");
	getValue(returnValue.favorited, jsonDataNew, "favorited");
	getValue(returnValue.retweeted, jsonDataNew, "retweeted");
	getValue(returnValue.retweeted_status, jsonDataNew, "retweeted_status");
	getValue(returnValue.id, jsonDataNew, "id");
}

template<> void getValue(twitter_message& returnValue, simdjson::ondemand::value jsonDataNew) {
	getValue(returnValue.search_metadata, jsonDataNew, "search_metadata");
	getValue(returnValue.statuses, jsonDataNew, "statuses");
}

template<> void getValue(icon_emoji_data& returnValue, simdjson::ondemand::value jsonDataNew) {
	getValue(returnValue.name, jsonDataNew, "name");
	// Since nullptr_t is not typically deserialized, handling it as necessary.
}

template<> void getValue(permission_overwrite& returnValue, simdjson::ondemand::value jsonDataNew) {
	getValue(returnValue.allow, jsonDataNew, "allow");
	getValue(returnValue.deny, jsonDataNew, "deny");
	getValue(returnValue.id, jsonDataNew, "id");
	getValue(returnValue.type, jsonDataNew, "type");
}

template<> void getValue(channel_data& returnValue, simdjson::ondemand::value jsonDataNew) {
	getValue(returnValue.permission_overwrites, jsonDataNew, "permission_overwrites");
	getValue(returnValue.last_message_id, jsonDataNew, "last_message_id");
	getValue(returnValue.default_thread_rate_limit_per_user, jsonDataNew, "default_thread_rate_limit_per_user");
	getValue(returnValue.applied_tags, jsonDataNew, "applied_tags");
	getValue(returnValue.recipients, jsonDataNew, "recipients");
	getValue(returnValue.default_auto_archive_duration, jsonDataNew, "default_auto_archive_duration");
	getValue(returnValue.rtc_region, jsonDataNew, "rtc_region");
	getValue(returnValue.status, jsonDataNew, "status");
	getValue(returnValue.last_pin_timestamp, jsonDataNew, "last_pin_timestamp");
	getValue(returnValue.topic, jsonDataNew, "topic");
	getValue(returnValue.rate_limit_per_user, jsonDataNew, "rate_limit_per_user");
	getValue(returnValue.icon_emoji, jsonDataNew, "icon_emoji");
	getValue(returnValue.total_message_sent, jsonDataNew, "total_message_sent");
	getValue(returnValue.video_quality_mode, jsonDataNew, "video_quality_mode");
	getValue(returnValue.application_id, jsonDataNew, "application_id");
	getValue(returnValue.permissions, jsonDataNew, "permissions");
	getValue(returnValue.message_count, jsonDataNew, "message_count");
	getValue(returnValue.parent_id, jsonDataNew, "parent_id");
	getValue(returnValue.member_count, jsonDataNew, "member_count");
	getValue(returnValue.owner_id, jsonDataNew, "owner_id");
	getValue(returnValue.guild_id, jsonDataNew, "guild_id");
	getValue(returnValue.user_limit, jsonDataNew, "user_limit");
	getValue(returnValue.position, jsonDataNew, "position");
	getValue(returnValue.name, jsonDataNew, "name");
	getValue(returnValue.icon, jsonDataNew, "icon");
	getValue(returnValue.version, jsonDataNew, "version");
	getValue(returnValue.bitrate, jsonDataNew, "bitrate");
	getValue(returnValue.id, jsonDataNew, "id");
	getValue(returnValue.flags, jsonDataNew, "flags");
	getValue(returnValue.type, jsonDataNew, "type");
	getValue(returnValue.managed, jsonDataNew, "managed");
	getValue(returnValue.nsfw, jsonDataNew, "nsfw");
}

template<> void getValue(user_data& returnValue, simdjson::ondemand::value jsonDataNew) {
	getValue(returnValue.avatar_decoration_data, jsonDataNew, "avatar_decoration_data");
	getValue(returnValue.display_name, jsonDataNew, "display_name");
	getValue(returnValue.global_name, jsonDataNew, "global_name");
	getValue(returnValue.avatar, jsonDataNew, "avatar");
	getValue(returnValue.banner, jsonDataNew, "banner");
	getValue(returnValue.locale, jsonDataNew, "locale");
	getValue(returnValue.discriminator, jsonDataNew, "discriminator");
	getValue(returnValue.user_name, jsonDataNew, "user_name");
	getValue(returnValue.accent_color, jsonDataNew, "accent_color");
	getValue(returnValue.premium_type, jsonDataNew, "premium_type");
	getValue(returnValue.public_flags, jsonDataNew, "public_flags");
	getValue(returnValue.email, jsonDataNew, "email");
	getValue(returnValue.mfa_enabled, jsonDataNew, "mfa_enabled");
	getValue(returnValue.id, jsonDataNew, "id");
	getValue(returnValue.flags, jsonDataNew, "flags");
	getValue(returnValue.verified, jsonDataNew, "verified");
	getValue(returnValue.system, jsonDataNew, "system");
	getValue(returnValue.bot, jsonDataNew, "bot");
}

template<> void getValue(member_data& returnValue, simdjson::ondemand::value jsonDataNew) {
	getValue(returnValue.communication_disabled_until, jsonDataNew, "communication_disabled_until");
	getValue(returnValue.premium_since, jsonDataNew, "premium_since");
	getValue(returnValue.nick, jsonDataNew, "nick");
	getValue(returnValue.avatar, jsonDataNew, "avatar");
	getValue(returnValue.roles, jsonDataNew, "roles");
	getValue(returnValue.permissions, jsonDataNew, "permissions");
	getValue(returnValue.joined_at, jsonDataNew, "joined_at");
	getValue(returnValue.guild_id, jsonDataNew, "guild_id");
	getValue(returnValue.user, jsonDataNew, "user");
	getValue(returnValue.flags, jsonDataNew, "flags");
	getValue(returnValue.pending, jsonDataNew, "pending");
	getValue(returnValue.deaf, jsonDataNew, "deaf");
	getValue(returnValue.mute, jsonDataNew, "mute");
}

template<> void getValue(tags_data& returnValue, simdjson::ondemand::value jsonDataNew) {
	getValue(returnValue.premium_subscriber, jsonDataNew, "premium_subscriber");
	getValue(returnValue.bot_id, jsonDataNew, "bot_id");
}

template<> void getValue(role_data& returnValue, simdjson::ondemand::value jsonDataNew) {
	getValue(returnValue.unicode_emoji, jsonDataNew, "unicode_emoji");
	getValue(returnValue.icon, jsonDataNew, "icon");
	getValue(returnValue.permissions, jsonDataNew, "permissions");
	getValue(returnValue.position, jsonDataNew, "position");
	getValue(returnValue.name, jsonDataNew, "name");
	getValue(returnValue.mentionable, jsonDataNew, "mentionable");
	getValue(returnValue.version, jsonDataNew, "version");
	getValue(returnValue.id, jsonDataNew, "id");
	getValue(returnValue.tags, jsonDataNew, "tags");
	getValue(returnValue.color, jsonDataNew, "color");
	getValue(returnValue.flags, jsonDataNew, "flags");
	getValue(returnValue.managed, jsonDataNew, "managed");
	getValue(returnValue.hoist, jsonDataNew, "hoist");
}

template<> void getValue(guild_data& returnValue, simdjson::ondemand::value jsonDataNew) {
	getValue(returnValue.latest_on_boarding_question_id, jsonDataNew, "latest_on_boarding_question_id");
	getValue(returnValue.guild_scheduled_events, jsonDataNew, "guild_scheduled_events");
	getValue(returnValue.safety_alerts_channel_id, jsonDataNew, "safety_alerts_channel_id");
	getValue(returnValue.inventory_settings, jsonDataNew, "inventory_settings");
	getValue(returnValue.voice_states, jsonDataNew, "voice_states");
	getValue(returnValue.discovery_splash, jsonDataNew, "discovery_splash");
	getValue(returnValue.vanity_url_code, jsonDataNew, "vanity_url_code");
	getValue(returnValue.application_id, jsonDataNew, "application_id");
	getValue(returnValue.afk_channel_id, jsonDataNew, "afk_channel_id");
	getValue(returnValue.default_message_notifications, jsonDataNew, "default_message_notifications");
	getValue(returnValue.max_stage_video_channel_users, jsonDataNew, "max_stage_video_channel_users");
	getValue(returnValue.public_updates_channel_id, jsonDataNew, "public_updates_channel_id");
	getValue(returnValue.description, jsonDataNew, "description");
	getValue(returnValue.threads, jsonDataNew, "threads");
	getValue(returnValue.channels, jsonDataNew, "channels");
	getValue(returnValue.premium_subscription_count, jsonDataNew, "premium_subscription_count");
	getValue(returnValue.approximate_presence_count, jsonDataNew, "approximate_presence_count");
	getValue(returnValue.features, jsonDataNew, "features");
	getValue(returnValue.stickers, jsonDataNew, "stickers");
	getValue(returnValue.premium_progress_bar_enabled, jsonDataNew, "premium_progress_bar_enabled");
	getValue(returnValue.members, jsonDataNew, "members");
	getValue(returnValue.hub_type, jsonDataNew, "hub_type");
	getValue(returnValue.approximate_member_count, jsonDataNew, "approximate_member_count");
	getValue(returnValue.explicit_content_filter, jsonDataNew, "explicit_content_filter");
	getValue(returnValue.max_video_channel_users, jsonDataNew, "max_video_channel_users");
	getValue(returnValue.splash, jsonDataNew, "splash");
	getValue(returnValue.banner, jsonDataNew, "banner");
	getValue(returnValue.system_channel_id, jsonDataNew, "system_channel_id");
	getValue(returnValue.widget_channel_id, jsonDataNew, "widget_channel_id");
	getValue(returnValue.preferred_locale, jsonDataNew, "preferred_locale");
	getValue(returnValue.system_channel_flags, jsonDataNew, "system_channel_flags");
	getValue(returnValue.rules_channel_id, jsonDataNew, "rules_channel_id");
	getValue(returnValue.roles, jsonDataNew, "roles");
	getValue(returnValue.verification_level, jsonDataNew, "verification_level");
	getValue(returnValue.permissions, jsonDataNew, "permissions");
	getValue(returnValue.max_presences, jsonDataNew, "max_presences");
	getValue(returnValue.discovery, jsonDataNew, "discovery");
	getValue(returnValue.joined_at, jsonDataNew, "joined_at");
	getValue(returnValue.member_count, jsonDataNew, "member_count");
	getValue(returnValue.premium_tier, jsonDataNew, "premium_tier");
	getValue(returnValue.owner_id, jsonDataNew, "owner_id");
	getValue(returnValue.max_members, jsonDataNew, "max_members");
	getValue(returnValue.afk_timeout, jsonDataNew, "afk_timeout");
	getValue(returnValue.widget_enabled, jsonDataNew, "widget_enabled");
	getValue(returnValue.region, jsonDataNew, "region");
	getValue(returnValue.nsfw_level, jsonDataNew, "nsfw_level");
	getValue(returnValue.mfa_level, jsonDataNew, "mfa_level");
	getValue(returnValue.name, jsonDataNew, "name");
	getValue(returnValue.icon, jsonDataNew, "icon");
	getValue(returnValue.unavailable, jsonDataNew, "unavailable");
	getValue(returnValue.id, jsonDataNew, "id");
	getValue(returnValue.flags, jsonDataNew, "flags");
	getValue(returnValue.large, jsonDataNew, "large");
	getValue(returnValue.owner, jsonDataNew, "owner");
	getValue(returnValue.nsfw, jsonDataNew, "nsfw");
	getValue(returnValue.lazy, jsonDataNew, "lazy");
}

template<> void getValue(discord_message& returnValue, simdjson::ondemand::value jsonDataNew) {
	getValue(returnValue.t, jsonDataNew, "t");
	getValue(returnValue.d, jsonDataNew, "d");
	getValue(returnValue.op, jsonDataNew, "op");
	getValue(returnValue.s, jsonDataNew, "s");
}

	#define SIMD_PULL(x) \
		{ \
			simdjson::ondemand::array newX = doc[#x].get_array().value(); \
			for (simdjson::ondemand::value value: newX) { \
				test_struct newStruct{}; \
				getValue(newStruct.testStrings, value, "testStrings"); \
				getValue(newStruct.testUints, value, "testUints"); \
				getValue(newStruct.testDoubles, value, "testDoubles"); \
				getValue(newStruct.testInts, value, "testInts"); \
				getValue(newStruct.testBools, value, "testBools"); \
				obj.x.emplace_back(std::move(newStruct)); \
			} \
		}

	#define SIMD_PULL_ABC(x) \
		{ \
			simdjson::ondemand::array newX = doc[#x].get_array().value(); \
			for (simdjson::ondemand::value value: newX) { \
				test_struct newStruct{}; \
				getValue(newStruct.testBools, value, "testBools"); \
				getValue(newStruct.testInts, value, "testInts"); \
				getValue(newStruct.testDoubles, value, "testDoubles"); \
				getValue(newStruct.testUints, value, "testUints"); \
				getValue(newStruct.testStrings, value, "testStrings"); \
				obj.x.emplace_back(std::move(newStruct)); \
			} \
		}


template<> void getValue<test<test_struct>>(test<test_struct>& obj, simdjson::ondemand::value doc) {
	SIMD_PULL(a);
	SIMD_PULL(b);
	SIMD_PULL(c);
	SIMD_PULL(d);
	SIMD_PULL(e);
	SIMD_PULL(f);
	SIMD_PULL(g);
	SIMD_PULL(h);
	SIMD_PULL(i);
	SIMD_PULL(j);
	SIMD_PULL(k);
	SIMD_PULL(l);
	SIMD_PULL(m);
	SIMD_PULL(n);
	SIMD_PULL(o);
	SIMD_PULL(p);
	SIMD_PULL(q);
	SIMD_PULL(r);
	SIMD_PULL(s);
	SIMD_PULL(t);
	SIMD_PULL(u);
	SIMD_PULL(v);
	SIMD_PULL(w);
	SIMD_PULL(x);
	SIMD_PULL(y);
	SIMD_PULL(z);
}

template<> void getValue<abc_test<test_struct>>(abc_test<test_struct>& obj, simdjson::ondemand::value doc) {
	SIMD_PULL_ABC(z);
	SIMD_PULL_ABC(y);
	SIMD_PULL_ABC(x);
	SIMD_PULL_ABC(w);
	SIMD_PULL_ABC(v);
	SIMD_PULL_ABC(u);
	SIMD_PULL_ABC(t);
	SIMD_PULL_ABC(s);
	SIMD_PULL_ABC(r);
	SIMD_PULL_ABC(q);
	SIMD_PULL_ABC(p);
	SIMD_PULL_ABC(o);
	SIMD_PULL_ABC(n);
	SIMD_PULL_ABC(m);
	SIMD_PULL_ABC(l);
	SIMD_PULL_ABC(k);
	SIMD_PULL_ABC(j);
	SIMD_PULL_ABC(i);
	SIMD_PULL_ABC(h);
	SIMD_PULL_ABC(g);
	SIMD_PULL_ABC(f);
	SIMD_PULL_ABC(e);
	SIMD_PULL_ABC(d);
	SIMD_PULL_ABC(c);
	SIMD_PULL_ABC(b);
	SIMD_PULL_ABC(a);
}

template<typename test_data_type, bool minified, uint64_t iterations>
struct json_test_helper<json_library::simdjson, test_type::parse_and_serialize, test_data_type, minified, iterations> {
	static auto run(const std::string& newBuffer, const std::string& testName, bool doWePrint = true) {
		std::string buffer{ newBuffer };

		results_data r{ "simdjson", testName, "https://github.com/simdjson/simdjson", iterations };

		simdjson::ondemand::parser parser{};
		auto readSize	= buffer.size();
		auto readResult = benchmark<iterations>([&]() {
			test_data_type testData{};
			try {
				getValue(testData, parser.iterate(buffer).value());
				doNotOptimizeAway(testData);
			} catch (std ::exception& error) {
				std::cout << "Simdjson Error: " << error.what() << std::endl;
			}
		});

		r.readResult = result<result_type::read>{ "cadetblue", readSize, readResult };
		file_loader fileLoader{ basePath + "/" + testName + "-simdjson.json" };
		fileLoader.saveFile(buffer);
		if (doWePrint) {
			r.print();
		}

		return r;
	}
};

template<uint64_t iterations> struct json_test_helper<json_library::simdjson, test_type::minify, std::string, false, iterations> {
	static auto run(const std::string& newBuffer, const std::string& testName, bool doWePrint = true) {
		std::string buffer{ newBuffer };

		results_data r{ "simdjson", testName, "https://github.com/simdjson/simdjson", iterations };

		simdjson::dom::parser parser{};
		std::string newerBuffer{};

		auto writeResult = benchmark<iterations>([&]() {
			try {
				newerBuffer = simdjson::minify(parser.parse(buffer));
				doNotOptimizeAway(newerBuffer);
			} catch (std ::exception& error) {
				std::cout << "Simdjson Error: " << error.what() << std::endl;
			}
			return;
		});

		file_loader fileLoader{ basePath + "/" + testName + "-simdjson.json" };
		fileLoader.saveFile(newerBuffer);
		r.writeResult = result<result_type::write>{ "cornflowerblue", newerBuffer.size(), writeResult };

		if (doWePrint) {
			r.print();
		}

		return r;
	}
};
#endif

std::string table_header = R"(
| Library | Read (MB/s) | ReadLength (Bytes) | ReadTime (ns) | ReadMape (%) | Write (MB/s) | WriteLength (Bytes) | WriteTime (ns) | WriteMape (%) |
| ------------------------------------------------- | ---------- | ----------- | ---------- | ----------- | ---------- | ---------- | ---------- | ---------- |)";

std::string read_table_header = R"(
| Library | Read (MB/s) | ReadLength (Bytes) | ReadTime (ns) | ReadMape (%) |
| ------------------------------------------------- | ---------- | ----------- | ---------- | ----------- |)";

std::string write_table_header = R"(
| Library | Write (MB/s) | WriteLength (Bytes) | WriteTime (ns) | WriteMape (%) |
| ------------------------------------------------- | ---------- | ----------- | ---------- | ----------- |)";

template<test_type type, typename test_data_type, bool minified, uint64_t iterations> struct json_tests_helper;

template<test_type type, typename test_data_type, bool minified, uint64_t iterations> struct json_tests_helper {
	static test_results run(const std::string& jsonDataNew, const std::string& testName) {
		jsonifier::vector<results_data> resultsNew{};
		test_results jsonResults{};
		jsonResults.testName = testName;
#if !defined(ASAN)
		resultsNew.emplace_back(json_test_helper<json_library::simdjson, type, test_data_type, minified, iterations>::run(jsonDataNew, jsonResults.testName, true));
		resultsNew.emplace_back(json_test_helper<json_library::glaze, type, test_data_type, minified, iterations>::run(jsonDataNew, jsonResults.testName, true));
#endif
		resultsNew.emplace_back(json_test_helper<json_library::jsonifier, type, test_data_type, minified, iterations>::run(jsonDataNew, jsonResults.testName, true));

		std::string table{};
		const auto n = resultsNew.size();
		table += table_header + "\n";
		std::sort(resultsNew.begin(), resultsNew.end(), std::greater<results_data>());
		for (uint64_t x = 0; x < n; ++x) {
			jsonResults.results.emplace_back(resultsNew[x]);
			table += resultsNew[x].jsonStats();
			if (x != n - 1) {
				table += "\n";
			}
		}
		jsonResults.markdownResults = table;
		return jsonResults;
	}
};

template<uint64_t iterations> struct json_tests_helper<test_type::prettify, std::string, false, iterations> {
	static test_results run(const std::string& jsonDataNew, const std::string& testName) {
		jsonifier::vector<results_data> resultsNew{};
		test_results jsonResults{};
		jsonResults.testName = testName;
#if !defined(ASAN)
		resultsNew.emplace_back(json_test_helper<json_library::glaze, test_type::prettify, std::string, false, iterations>::run(jsonDataNew, jsonResults.testName, true));
#endif
		resultsNew.emplace_back(json_test_helper<json_library::jsonifier, test_type::prettify, std::string, false, iterations>::run(jsonDataNew, jsonResults.testName, true));

		std::string table{};
		const auto n = resultsNew.size();
		table += write_table_header + "\n";
		std::sort(resultsNew.begin(), resultsNew.end(), std::greater<results_data>());
		for (uint64_t x = 0; x < n; ++x) {
			jsonResults.results.emplace_back(resultsNew[x]);
			table += resultsNew[x].jsonStats();
			if (x != n - 1) {
				table += "\n";
			}
		}
		jsonResults.markdownResults = table;
		return jsonResults;
	}
};

template<uint64_t iterations> struct json_tests_helper<test_type::minify, std::string, false, iterations> {
	static test_results run(const std::string& jsonDataNew, const std::string& testName) {
		jsonifier::vector<results_data> resultsNew{};
		test_results jsonResults{};
		jsonResults.testName = testName;
#if !defined(ASAN)
		resultsNew.emplace_back(json_test_helper<json_library::simdjson, test_type::minify, std::string, false, iterations>::run(jsonDataNew, jsonResults.testName, true));
		resultsNew.emplace_back(json_test_helper<json_library::glaze, test_type::minify, std::string, false, iterations>::run(jsonDataNew, jsonResults.testName, true));
#endif
		resultsNew.emplace_back(json_test_helper<json_library::jsonifier, test_type::minify, std::string, false, iterations>::run(jsonDataNew, jsonResults.testName, true));

		std::string table{};
		const auto n = resultsNew.size();
		table += write_table_header + "\n";
		std::sort(resultsNew.begin(), resultsNew.end(), std::greater<results_data>());
		for (uint64_t x = 0; x < n; ++x) {
			jsonResults.results.emplace_back(resultsNew[x]);
			table += resultsNew[x].jsonStats();
			if (x != n - 1) {
				table += "\n";
			}
		}
		jsonResults.markdownResults = table;
		return jsonResults;
	}
};

template<uint64_t iterations> struct json_tests_helper<test_type::validate, std::string, false, iterations> {
	static test_results run(const std::string& jsonDataNew, const std::string& testName) {
		jsonifier::vector<results_data> resultsNew{};
		test_results jsonResults{};
		jsonResults.testName = testName;
		resultsNew.emplace_back(json_test_helper<json_library::jsonifier, test_type::validate, std::string, false, iterations>::run(jsonDataNew, jsonResults.testName, true));

		std::string table{};
		const auto n = resultsNew.size();
		table += read_table_header + "\n";
		std::sort(resultsNew.begin(), resultsNew.end(), std::greater<results_data>());
		for (uint64_t x = 0; x < n; ++x) {
			jsonResults.results.emplace_back(resultsNew[x]);
			table += resultsNew[x].jsonStats();
			if (x != n - 1) {
				table += "\n";
			}
		}
		jsonResults.markdownResults = table;
		return jsonResults;
	}
};

static const std::string section001{ R"(
 > At least )" +
	jsonifier::toString(static_cast<uint64_t>(static_cast<float>(iterationsVal) * 0.10f)) +
	R"( iterations on a 6 core (Intel i7 8700k), until Median Absolute Percentage Error (Mape) reduced below 5.0%.
)" };

static constexpr std::string_view section00{ R"(# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Ubuntu-22.04 using the Clang++18 compiler)

Latest Results: ()" };

static constexpr std::string_view section01{
	R"(

### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>

)"
};

static constexpr std::string_view section02{
	R"(

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>

)"
};

static const std::string_view section03{
	R"(

### ABC Test (Out of Sequence Performance - Prettified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z," where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.
)"
};

static constexpr std::string_view section04{ R"(

### ABC Test (Out of Sequence Performance - Minified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>

)" };

static constexpr std::string_view section05{ R"(

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>

)" };

static constexpr std::string_view section06{ R"(

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>

)" };

static constexpr std::string_view section07{ R"(

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>

)" };

static constexpr std::string_view section08{ R"(

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>

)" };

static constexpr std::string_view section09{ R"(

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>

)" };

static constexpr std::string_view section10{ R"(

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>

)" };

static constexpr std::string_view section11{
	R"(

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>

)"
};

static constexpr std::string_view section12{
	R"(

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>

)"
};

static constexpr std::string_view section13{
	R"(

### Validation Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>

)"
};

#include "ConformanceTests.hpp"

int32_t main() {
	try {
		test_generator<test_struct> testJsonData{};
		std::string jsonDataNew{};
		jsonifier::jsonifier_core parser{};
		file_loader fileLoader01{ README_PATH };
		file_loader fileLoader02{ basePath + "/JsonData-Prettified.json" };
		parser.serializeJson<jsonifier::serialize_options{ .prettify = true }>(testJsonData, jsonDataNew);
		fileLoader02.saveFile(jsonDataNew);
		file_loader fileLoader03{ basePath + "/JsonData-Minified.json" };
		std::string jsonMinifiedData{ parser.minifyJson(jsonDataNew) };
		fileLoader03.saveFile(jsonMinifiedData);
		file_loader fileLoader04{ basePath + "/Results.json" };
		file_loader fileLoader05{ basePath + "/DiscordData-Prettified.json" };
		std::string discordData{ fileLoader05.operator std::string() };
		discord_message discordMessage{};
		parser.parseJson(discordMessage, discordData);
		for (auto& value: parser.getErrors()) {
			std::cout << "PARSER ERROR: " << value << std::endl;
		}
		parser.serializeJson<jsonifier::serialize_options{ .prettify = true }>(discordMessage, discordData);
		fileLoader05.saveFile(discordData);
		file_loader fileLoader06{ basePath + "/DiscordData-Minified.json" };
		std::string discordMinifiedData{ fileLoader06.operator std::string() };
		discordMinifiedData = parser.minifyJson(discordData);
		fileLoader06.saveFile(discordMinifiedData);
		file_loader fileLoader07{ basePath + "/CanadaData-Prettified.json" };
		std::string canadaData{ fileLoader07.operator std::string() };
		canada_message canadaMessage{};
		parser.parseJson(canadaMessage, canadaData);
		for (auto& value: parser.getErrors()) {
			std::cout << "PARSER ERROR: " << value << std::endl;
		}
		parser.serializeJson<jsonifier::serialize_options{ .prettify = true }>(canadaMessage, canadaData);
		fileLoader07.saveFile(canadaData);
		file_loader fileLoader08{ basePath + "/CanadaData-Minified.json" };
		std::string canadaMinifiedData{ fileLoader08.operator std::string() };
		canadaMinifiedData = parser.minifyJson(canadaData);
		fileLoader08.saveFile(canadaMinifiedData);
		file_loader fileLoader09{ basePath + "/TwitterData-Prettified.json" };
		std::string twitterData{ fileLoader09.operator std::string() };
		twitter_message twitterMessage{};
		parser.parseJson(twitterMessage, twitterData);
		for (auto& value: parser.getErrors()) {
			std::cout << "PARSER ERROR: " << value << std::endl;
		}
		parser.serializeJson<jsonifier::serialize_options{ .prettify = true }>(twitterMessage, twitterData);
		fileLoader09.saveFile(twitterData);
		file_loader fileLoader10{ basePath + "/TwitterData-Minified.json" };
		std::string twitterMinifiedData{ fileLoader10.operator std::string() };
		twitterMinifiedData = parser.minifyJson(twitterData);
		fileLoader10.saveFile(twitterMinifiedData);
		for (auto& value: parser.getErrors()) {
			std::cout << "PARSER ERROR: " << value << std::endl;
		}
		std::string newTimeString{};
		newTimeString.resize(1024);
		std::tm resultTwo{};
		std::time_t result = std::time(nullptr);
		resultTwo		   = *localtime(&result);
		//conformanceTests();
		std::vector<test_results> benchmark_data{};
		newTimeString.resize(strftime(newTimeString.data(), 1024, "%b %d, %Y", &resultTwo));
		std::string newerString{ static_cast<std::string>(section00) + newTimeString + ")\n" + section001 + static_cast<std::string>(section01) };
		auto testResults = json_tests_helper<test_type::parse_and_serialize, test<test_struct>, false, iterationsVal>::run(jsonDataNew, "Json Test (Prettified)");
		newerString += testResults.markdownResults;
		benchmark_data.emplace_back(testResults);
		testResults = json_tests_helper<test_type::parse_and_serialize, test<test_struct>, true, iterationsVal>::run(jsonMinifiedData, "Json Test (Minified)");
		newerString += section02;
		newerString += testResults.markdownResults;
		benchmark_data.emplace_back(testResults);
		testResults = json_tests_helper<test_type::parse_and_serialize, abc_test<test_struct>, false, iterationsVal>::run(jsonDataNew, "Abc Test (Prettified)");
		newerString += section03;
		newerString += testResults.markdownResults;
		benchmark_data.emplace_back(testResults);
		testResults = json_tests_helper<test_type::parse_and_serialize, abc_test<test_struct>, true, iterationsVal>::run(jsonMinifiedData, "Abc Test (Minified)");
		newerString += section04;
		newerString += testResults.markdownResults;
		benchmark_data.emplace_back(testResults);
		testResults = json_tests_helper<test_type::parse_and_serialize, discord_message, false, iterationsVal>::run(discordData, "Discord Test (Prettified)");
		newerString += section05;
		newerString += testResults.markdownResults;
		benchmark_data.emplace_back(testResults);
		testResults = json_tests_helper<test_type::parse_and_serialize, discord_message, true, iterationsVal>::run(discordMinifiedData, "Discord Test (Minified)");
		newerString += section06;
		newerString += testResults.markdownResults;
		benchmark_data.emplace_back(testResults);
		testResults = json_tests_helper<test_type::parse_and_serialize, canada_message, false, iterationsVal>::run(canadaData, "Canada Test (Prettified)");
		newerString += section07;
		newerString += testResults.markdownResults;
		benchmark_data.emplace_back(testResults);
		testResults = json_tests_helper<test_type::parse_and_serialize, canada_message, true, iterationsVal>::run(canadaMinifiedData, "Canada Test (Minified)");
		newerString += section08;
		newerString += testResults.markdownResults;
		benchmark_data.emplace_back(testResults);
		testResults = json_tests_helper<test_type::parse_and_serialize, twitter_message, false, iterationsVal>::run(twitterData, "Twitter Test (Prettified)");
		newerString += section09;
		newerString += testResults.markdownResults;
		benchmark_data.emplace_back(testResults);
		testResults = json_tests_helper<test_type::parse_and_serialize, twitter_message, true, iterationsVal>::run(twitterMinifiedData, "Twitter Test (Minified)");
		newerString += section10;
		newerString += testResults.markdownResults;
		benchmark_data.emplace_back(testResults);
		testResults = json_tests_helper<test_type::minify, std::string, false, iterationsVal>::run(discordData, "Minify Test");
		newerString += section11;
		newerString += testResults.markdownResults;
		benchmark_data.emplace_back(testResults);
		testResults = json_tests_helper<test_type::prettify, std::string, false, iterationsVal>::run(jsonMinifiedData, "Prettify Test");
		newerString += section12;
		newerString += testResults.markdownResults;
		benchmark_data.emplace_back(testResults);
		testResults = json_tests_helper<test_type::validate, std::string, false, iterationsVal>::run(discordData, "Validate Test");
		newerString += section13;
		newerString += testResults.markdownResults;
		benchmark_data.emplace_back(testResults);
		std::string resultsStringJson{};
		test_results_final resultsData{};
		for (auto& value: benchmark_data) {
			test_elements_final testElement{};
			testElement.testName = value.testName;
			for (auto& valueNew: value.results) {
				test_element_final resultFinal{};
				if (valueNew.readResult.jsonSpeed.has_value()) {
					resultFinal.libraryName = valueNew.name;
					resultFinal.color		= valueNew.readResult.color;
					resultFinal.resultSpeed = valueNew.readResult.jsonSpeed.value();
					resultFinal.Mape		= valueNew.readResult.Mape.value();
					resultFinal.resultType	= "Read";
					testElement.results.emplace_back(resultFinal);
				}
				if (valueNew.writeResult.jsonSpeed.has_value()) {
					resultFinal.libraryName = valueNew.name;
					resultFinal.color		= valueNew.writeResult.color;
					resultFinal.resultSpeed = valueNew.writeResult.jsonSpeed.value();
					resultFinal.Mape		= valueNew.writeResult.Mape.value();
					resultFinal.resultType	= "Write";
					testElement.results.emplace_back(resultFinal);
				}
			}
			resultsData.emplace_back(testElement);
		}
		parser.serializeJson<jsonifier::serialize_options{ .prettify = true }>(resultsData, resultsStringJson);
		fileLoader04.saveFile(resultsStringJson);
		fileLoader01.saveFile(newerString);
	} catch (std::runtime_error& e) {
		std::cout << e.what() << std::endl;
	} catch (std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}