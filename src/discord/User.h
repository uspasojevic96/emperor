#include <string>
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

    enum class PremiumType {
        None = 0,
        NitroClassic = 1,
        Nitro = 2
    };

    class User {
        std::string id_;

        public:
        User(std::string const& _id) : id_{_id} {}
    };
}
