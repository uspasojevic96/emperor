#include <string>
#include <optional>
#include <variant>
#include <nlohmann/json.hpp>

namespace discord {
    
    enum class UserFlag {
        None = 0,
        DiscordEmployee = 1 << 0,
        PartneredServerOwner = 1 << 1,
        HypeSquadEvents = 1 << 2,
        BugHunterLevel1 = 1 << 3,
        HouseBravery = 1 << 6,
        HouseBrilliance = 1 << 7,
        HouseBalance = 1 << 8,
        EarlySupporter = 1 << 9,
        TeamUser = 1 << 10,
        System = 1 << 12,
        BugHunterLevel2 = 1 << 14,
        VerifiedBot = 1 << 16,
        EarlyVerifiedBotDeveloper = 1 << 17
    };

    enum class UserField {
        ID,
        Username,
        Discriminator,
        Avatar,
        Bot,
        System,
        MFAEnabled,
        Locale,
        Verified,
        Email,
        Flags,
        PremiumType,
        PublicFlags
    };

    enum class PremiumType {
        None = 0,
        NitroClassic = 1,
        Nitro = 2
    };

    class User {
        private:
        std::optional<std::string>  id_             = std::nullopt;
        std::optional<std::string>  username_       = std::nullopt;
        std::optional<std::string>  discriminator_  = std::nullopt;
        std::optional<std::string>  avatar_         = std::nullopt;
        std::optional<bool>         bot_            = std::nullopt;
        std::optional<bool>         system_         = std::nullopt;
        std::optional<bool>         mfaEnabled_     = std::nullopt;
        std::optional<std::string>  locale_         = std::nullopt;
        std::optional<bool>         verified_       = std::nullopt;
        std::optional<std::string>  email_          = std::nullopt;
        std::optional<UserFlag>         flags_          = std::nullopt;
        std::optional<PremiumType>  premiumType_    = std::nullopt;
        std::optional<UserFlag>         publicFlags_    = std::nullopt;

        public:
        template <UserField>
        std::variant<std::string, bool, UserFlag, PremiumType> const get();
        static User fromJSON(nlohmann::json const& _json);
    };
}
