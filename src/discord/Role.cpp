#include <discord/Role.h>
#include <variant>
namespace discord {
    Role Role::fromJSON(nlohmann::json const& _json) {
        auto role = Role{};

        if (_json.count("id") != 0) {
            role.id_ = _json.at("id").get<std::string>();
        }

        if (_json.count("name") != 0) {
            role.name_ = _json.at("name").get<std::string>();
        }

        if (_json.count("color") != 0) {
            role.color_ = _json.at("color").get<int>();
        }

        if (_json.count("hoist") != 0) {
            role.hoist_ = _json.at("hoist").get<bool>();
        }

        if (_json.count("position") != 0) {
            role.position_ = _json.at("position").get<int>();
        }

        if (_json.count("permissions") != 0) {
            role.permissions_ = _json.at("permissions").get<std::string>();
        }

        if (_json.count("managed") != 0) {
            role.managed_ = _json.at("managed").get<bool>();
        }

        if (_json.count("mentionable") != 0) {
            role.mentionable_ = _json.at("mentionable").get<bool>();
        }

        if (_json.count("tags") != 0) {
            role.tags_ = RoleTags::fromJSON(_json.at("tags").get<nlohmann::json>());
        }

        return role;
    }

    template <>
    std::variant<std::string, int, bool, RoleTags> const Role::get<RoleField::ID>() {
        return id_.value_or("");
    }

    template <>
    std::variant<std::string, int, bool, RoleTags> const Role::get<RoleField::Tags>() {
        return tags_.value_or(RoleTags{});
    }

    template <>
    std::variant<std::string, int, bool, RoleTags> const Role::get<RoleField::Color>() {
        return color_.value_or(0);
    }

    template <>
    std::variant<std::string, int, bool, RoleTags> const Role::get<RoleField::Hoist>() {
        return hoist_.value_or(false);
    }

    template <>
    std::variant<std::string, int, bool, RoleTags> const Role::get<RoleField::Managed>() {
        return managed_.value_or(false);
    }

    template <>
    std::variant<std::string, int, bool, RoleTags> const Role::get<RoleField::Mentionable>() {
        return mentionable_.value_or(false);
    }

    template <>
    std::variant<std::string, int, bool, RoleTags> const Role::get<RoleField::Name>() {
        return name_.value_or("");
    }

    template <>
    std::variant<std::string, int, bool, RoleTags> const Role::get<RoleField::Permissions>() {
        return permissions_.value_or("");
    }

    template <>
    std::variant<std::string, int, bool, RoleTags> const Role::get<RoleField::Position>() {
        return position_.value_or(0);
    }
}
