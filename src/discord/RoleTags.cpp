#include <nlohmann/json.hpp>
#include <discord/RoleTags.h>
#include <string>
#include <variant>

namespace discord {
    RoleTags RoleTags::fromJSON(nlohmann::json const& _json) {
        auto roleTags = RoleTags{};

        if (_json.count("bot_id") != 0) {
            roleTags.botId_ = _json.at("bot_id").get<std::string>();
        }

        if (_json.count("integration_id") != 0) {
            roleTags.integrationId_ = _json.at("integration_id").get<std::string>();
        }

        if (_json.count("premium_subscriber") != 0) {
            roleTags.premiumSubscriber_ = true;
        }

        return roleTags;
    }

    template <>
    std::variant<std::string, bool> const RoleTags::get<RoleTagsField::BotID>() {
        return botId_.value_or("");
    }

    template <>
    std::variant<std::string, bool> const RoleTags::get<RoleTagsField::IntegrationID>() {
        return integrationId_.value_or("");
    }

    template <>
    std::variant<std::string, bool> const RoleTags::get<RoleTagsField::PremiumSubscriber>() {
        return premiumSubscriber_.value_or(false);
    }
}
