#include <nlohmann/json.hpp>
#include <optional>
#include <string>

namespace discord {
    class RoleTags {
        public:
            std::optional<std::string> botId_ = std::nullopt;
            std::optional<std::string> integrationId_ = std::nullopt;
            std::optional<bool> premiumSubscriber_ = std::nullopt;

        public:
            RoleTags fromJSON(nlohmann::json const& _json);
    };

    class Role {
        public:
            std::optional<std::string> id_ = std::nullopt;
            std::optional<std::string> name_ = std::nullopt;

    };
}
