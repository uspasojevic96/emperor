#include <nlohmann/json.hpp>
#include <discord/Emoji.h>
#include <string>
#include <vector>

namespace discord {
    Emoji const Emoji::fromJSON(nlohmann::json const& _json) {
        auto emoji = Emoji{};

        if (_json.count("id") != 0) {
            emoji.id_ = _json.at("id").get<std::string>();
        }

        if (_json.count("name") != 0) {
            emoji.name_ = _json.at("name").get<std::string>();
        }

        if (_json.count("roles") != 0) {
            emoji.roles_ = _json.at("roles").get<std::vector<std::string>>();
        }

        if (_json.count("user") != 0) {
            emoji.user_ = User::fromJSON(_json.at("user").get<nlohmann::json>());
        }

        if (_json.count("require_colons") != 0) {
            emoji.requireColons_ = _json.at("require_colons").get<bool>();
        }

        if (_json.count("managed") != 0) {
            emoji.managed_ = _json.at("managed").get<bool>();
        }

        if (_json.count("animated") != 0) {
            emoji.animated_ = _json.at("animated").get<bool>();
        }

        if (_json.count("available") != 0) {
            emoji.available_ = _json.at("available").get<bool>();
        }

        return emoji;
    }

    template <>
    std::variant<std::string, std::vector<std::string>, User, bool> const Emoji::get<EmojiField::ID>() {
        return id_.value_or("");
    };

    template <>
    std::variant<std::string, std::vector<std::string>, User, bool> const Emoji::get<EmojiField::User>() {
        return user_.value_or(User{});
    };

    template <>
    std::variant<std::string, std::vector<std::string>, User, bool> const Emoji::get<EmojiField::Animated>() {
        return animated_.value_or(false);
    };

    template <>
    std::variant<std::string, std::vector<std::string>, User, bool> const Emoji::get<EmojiField::Available>() {
        return available_.value_or(false);
    };

    template <>
    std::variant<std::string, std::vector<std::string>, User, bool> const Emoji::get<EmojiField::Managed>() {
        return managed_.value_or(false);
    };

    template <>
    std::variant<std::string, std::vector<std::string>, User, bool> const Emoji::get<EmojiField::Name>() {
        return name_.value_or("");
    };

    template <>
    std::variant<std::string, std::vector<std::string>, User, bool> const Emoji::get<EmojiField::RequireColons>() {
        return requireColons_.value_or(false);
    };

    template <>
    std::variant<std::string, std::vector<std::string>, User, bool> const Emoji::get<EmojiField::Roles>() {
        return roles_.value_or(std::vector<std::string>{});
    };
}
