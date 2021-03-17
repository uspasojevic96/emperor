set(emperor_HEADERS
    main.cpp)
set(emperor_SOURCE
    Config.h
    )
set(emperor_LIBRARIES sleepy-discord)
add_executable(emperor emperor_SOURCE)
target_include_directories(emperor PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")


target_link_libraries(emperor emperor_LIBRARIES)
