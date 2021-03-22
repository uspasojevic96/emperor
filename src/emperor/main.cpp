#include "nlohmann/json.hpp"
#include <discord/User.h>
#include <iostream>
#include <variant>
int main() {
    auto j = R"(
    {
  "id": "80351110224678912",
  "username": "Nelly",
  "discriminator": "1337",
  "avatar": "8342729096ea3675442027381ff50dfe",
  "verified": true,
  "email": "nelly@discord.com",
  "flags": 64,
  "premium_type": 1,
  "public_flags": 64
}
)"_json;

    discord::User u = discord::User::fromJSON(j);

    std::cout << std::get<std::string>(u.get<discord::UserField::Username>()) << std::endl;
    return 0;
}
