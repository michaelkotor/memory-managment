add_executable(runTests main_test.cpp main.cpp)

target_link_directories(runTests PRIVATE ${CMAKE_BINARY_DIR}/lib)
target_include_directories(runTests PRIVATE ${CMAKE_BINARY_DIR}/include/)
target_link_libraries(runTests gtest)

add_dependencies(runTests googletest)
