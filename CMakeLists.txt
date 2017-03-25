cmake_minimum_required (VERSION 3.5)

project (lua_sol2_test)

set(CMAKE_CXX_STANDARD 14)

if(WIN32)
    ADD_DEFINITIONS(-DUNICODE)
    ADD_DEFINITIONS(-D_UNICODE)
endif(WIN32)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ext/lua)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ext/sol2)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/ext/lua)

# sample01
add_executable(sample01 sample01.cpp)
target_link_libraries(sample01 lua)

# sample02
add_executable(sample02 sample02.cpp)
target_link_libraries(sample02 lua)
add_custom_command(TARGET sample02 POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_CURRENT_SOURCE_DIR}/sample02.lua
    ${CMAKE_CURRENT_BINARY_DIR}/sample02.lua
)
