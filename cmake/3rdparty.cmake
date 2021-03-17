find_package(Boost)

set(WEBSOCKETPP_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/websocketpp/
    CACHE PATH "websocketpp include directory")

  install(DIRECTORY ${WEBSOCKETPP_INCLUDE_DIR}/websocketpp DESTINATION include)

  # Setup a target

  add_library(websocketpp INTERFACE)
  target_include_directories(websocketpp INTERFACE
    $<BUILD_INTERFACE:${WEBSOCKETPP_INCLUDE_DIR}>
    $<INSTALL_INTERFACE:include>
    ${Boost_INCLUDE_DIRS})

  install(TARGETS websocketpp EXPORT websocketpp DESTINATION include)
  install(EXPORT websocketpp DESTINATION share/websocketpp/cmake)
