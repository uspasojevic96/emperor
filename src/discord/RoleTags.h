#include <string>
#include <variant>
#include <optional>
#include <nlohmann/json.hpp>

namespace discord {
    enum class RoleTagsField {
        BotID,
        IntegrationID,
        PremiumSubscriber
    };

    class RoleTags {
        private:
            std::optional<std::string>  botId_                  = std::nullopt;
            std::optional<std::string>  integrationId_          = std::nullopt;
            std::optional<bool>         premiumSubscriber_      = std::nullopt;

        public:
            static RoleTags fromJSON(nlohmann::json const& _json);
            template <RoleTagsField>
            std::variant<std::string, bool> const get();
    };
}
