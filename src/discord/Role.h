#include <nlohmann/json.hpp>
#include <optional>
#include <string>
#include <variant>
#include <discord/RoleTags.h>

namespace discord {

    enum class RoleField {
        ID,
        Name,
        Color,
        Hoist,
        Position,
        Permissions,
        Managed,
        Mentionable,
        Tags
    };

    class Role {
        private:
            std::optional<std::string>  id_             = std::nullopt;
            std::optional<std::string>  name_           = std::nullopt;
            std::optional<int>          color_          = std::nullopt;
            std::optional<bool>         hoist_          = std::nullopt;
            std::optional<int>          position_       = std::nullopt;
            std::optional<std::string>  permissions_    = std::nullopt;
            std::optional<bool>         managed_        = std::nullopt;
            std::optional<bool>         mentionable_    = std::nullopt;
            std::optional<RoleTags>     tags_           = std::nullopt;

        public:
            static Role fromJSON(nlohmann::json const& _json);
            template <RoleField _field>
            std::variant<std::string, int, bool, RoleTags> const get();
    };
}
