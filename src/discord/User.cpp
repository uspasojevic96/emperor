#include <discord/User.h>
#include <string>
#include <variant>

namespace discord {
    User User::fromJSON(nlohmann::json const& _json) {
        auto user = User{};

        if (_json.count("id") != 0) {
            user.id_ = _json.at("id").get<std::string>();
        }

        if (_json.count("username") != 0) {
            user.username_ = _json.at("username").get<std::string>();
        }

        if (_json.count("discriminator") != 0) {
            user.discriminator_ = _json.at("discriminator").get<std::string>();
        }

        if (_json.count("avatar") != 0) {
            user.avatar_ = _json.at("avatar").get<std::string>();
        }

        if (_json.count("bot") != 0) {
            user.bot_ = _json.at("bot").get<bool>();
        }

        if (_json.count("system") != 0) {
            user.system_ = _json.at("system").get<bool>();
        }

        if (_json.count("mfa_enabled") != 0) {
            user.mfaEnabled_ = _json.at("mfa_enabled").get<bool>();
        }

        if (_json.count("locale") != 0) {
            user.locale_ = _json.at("locale").get<std::string>();
        }

        if (_json.count("verified") != 0) {
            user.verified_ = _json.at("verified").get<bool>();
        }

        if (_json.count("email") != 0) {
            user.email_ = _json.at("email").get<std::string>();
        }

        if (_json.count("flags") != 0) {
            user.flags_ = _json.at("flags").get<UserFlag>();
        }

        if (_json.count("premium_type") != 0) {
            user.premiumType_ = _json.at("premium_type").get<PremiumType>();
        }

        if (_json.count("public_flags") != 0) {
            user.publicFlags_ = _json.at("public_flags").get<UserFlag>();
        }

        return user;
    }

    template <>
    std::variant<std::string, bool, UserFlag, PremiumType> const User::get<UserField::ID>() {
        return id_.value_or("");
    }

    template <>
    std::variant<std::string, bool, UserFlag, PremiumType> const User::get<UserField::Flags>() {
        return flags_.value_or(UserFlag::None);
    }

    template <>
    std::variant<std::string, bool, UserFlag, PremiumType> const User::get<UserField::PublicFlags>() {
        return publicFlags_.value_or(UserFlag::None);
    }

    template <>
    std::variant<std::string, bool, UserFlag, PremiumType> const User::get<UserField::PremiumType>() {
        return premiumType_.value_or(PremiumType::None);
    }

    template <>
    std::variant<std::string, bool, UserFlag, PremiumType> const User::get<UserField::Username>() {
        return username_.value_or("");
    }

    template <>
    std::variant<std::string, bool, UserFlag, PremiumType> const User::get<UserField::Avatar>() {
        return avatar_.value_or("");
    }

    template <>
    std::variant<std::string, bool, UserFlag, PremiumType> const User::get<UserField::Bot>() {
        return bot_.value_or(false);
    }

    template <>
    std::variant<std::string, bool, UserFlag, PremiumType> const User::get<UserField::Discriminator>() {
        return discriminator_.value_or("");
    }

    template <>
    std::variant<std::string, bool, UserFlag, PremiumType> const User::get<UserField::Email>() {
        return email_.value_or("");
    }

    template <>
    std::variant<std::string, bool, UserFlag, PremiumType> const User::get<UserField::Locale>() {
        return locale_.value_or("");
    }

    template <>
    std::variant<std::string, bool, UserFlag, PremiumType> const User::get<UserField::MFAEnabled>() {
        return mfaEnabled_.value_or(false);
    }

    template <>
    std::variant<std::string, bool, UserFlag, PremiumType> const User::get<UserField::System>() {
        return system_.value_or(false);
    }

    template <>
    std::variant<std::string, bool, UserFlag, PremiumType> const User::get<UserField::Verified>() {
        return verified_.value_or(false);
    }
}
