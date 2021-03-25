cmake_minimum_required(VERSION 3.6)
project(discordpp-plugin-constructs)

set(CMAKE_CXX_STANDARD 17)

###################

add_library(${PROJECT_NAME} discordpp/constructs/message.cc)

target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE discordpp)
