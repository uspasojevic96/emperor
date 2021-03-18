set(discord_SOURCE
    Client.cpp Client.h
)

add_library(discord ${discord_SOURCE})
find_package(Boost REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(Threads REQUIRED)

set(discord_LIBS websocketpp)

target_link_libraries(discord PUBLIC ${discord_LIBS} ${Boost_LIBRARIES} ${OPENSSL_LIBRARIES}
    Threads::Threads)
target_compile_features(discord PUBLIC cxx_std_17)
target_include_directories(discord PUBLIC
    $<BUILD_INTERFACE:${${PROJECT_NAME}_SOURCE_DIR}/src>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/include>
    ${Boost_INCLUDE_DIRS}
    ${OPENSSL_INCLUDE_DIR}
)
