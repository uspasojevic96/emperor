#include <discord/User.h>
#include <string>

namespace discord {
    User User::fromJSON(nlohmann::json const& _json) {
        auto user = User{};

        user.id_ = _json.at("id").get<std::string>();
        user.username_ = _json.at("username").get<std::string>();
        user.discriminator_ = _json.at("discriminator").get<std::string>();
        user.avatar_ = _json.at("avatar").get<std::string>();

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
}
