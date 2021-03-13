cmake_minimum_required(VERSION 3.6)
project(discordpp-plugin-constructs)

set(CMAKE_CXX_STANDARD 17)

###################

add_library(${PROJECT_NAME} discordpp/constructs/message.cc)

INCLUDE_DIRECTORIES(${discordpp_SOURCE_DIR} ${json_SOURCE_DIR})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} INTERFACE)
