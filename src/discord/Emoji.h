#include <nlohmann/json.hpp>
#include <optional>
#include <string>
#include <variant>
#include <vector>
#include <discord/User.h>

namespace discord {
    enum class EmojiField {
        ID,
        Name,
        Roles,
        User,
        RequireColons,
        Managed,
        Animated,
        Available
    };

    class Emoji {
        private:
            std::optional<std::string>                  id_ = std::nullopt;
            std::optional<std::string>                  name_ = std::nullopt;
            std::optional<std::vector<std::string>>     roles_ = std::nullopt;
            std::optional<User>                         user_ = std::nullopt;
            std::optional<bool>                         requireColons_ = std::nullopt;
            std::optional<bool>                         managed_ = std::nullopt;
            std::optional<bool>                         animated_ = std::nullopt;
            std::optional<bool>                         available_ = std::nullopt;

        public:
            static Emoji const fromJSON(nlohmann::json const& _json);
            template <EmojiField _field>
            std::variant<std::string, std::vector<std::string>, User, bool> const get();
    };
}
