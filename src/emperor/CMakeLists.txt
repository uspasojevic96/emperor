set(emperor_SOURCE
    Config.cpp Config.h
    main.cpp)

add_executable(emperor ${emperor_SOURCE})
target_include_directories(emperor PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")


target_link_libraries(emperor websocketpp)
