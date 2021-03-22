set(discord_SOURCE
    Client.cpp      Client.h
    Emoji.cpp       Emoji.h
    Role.cpp        Role.h
    RoleTags.cpp    RoleTags.h
    User.cpp        User.h
)

add_library(discord ${discord_SOURCE})
add_library(discord::discord ALIAS discord)

target_link_libraries(discord PUBLIC nlohmann_json::nlohmann_json)
target_compile_features(discord PUBLIC cxx_std_17)
target_include_directories(discord PUBLIC
    $<BUILD_INTERFACE:${${PROJECT_NAME}_SOURCE_DIR}/src>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/include>
)
