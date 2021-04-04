//
// Created by Aidan on 1/15/2021.
//

#pragma once

#include <string>

#include <nlohmann/json.hpp>

#include <discordpp/bot.hh>

#include "../util/construct.hh"
#include "todo.hh"

namespace discordpp {
enum StickerFormat : int{
    PNG = 1,
    APNG = 2,
    LOTTIE = 3
};

// clang-format off
#define CONSTRUCTNAME Sticker
#define CONSTRUCTKEYS \
    key(SNOWFLAKE, id) \
    key(SNOWFLAKE, pack_id) \
    key(DEF(std::string), name) \
    key(DEF(std::string), description) \
    key(OPT(DEF(std::string)), tags) \
    key(DEF(std::string), asset) \
    key(DEF(std::string), preview_asset) \
    key(DEF(int), format_type)
// clang-format on

class CONSTRUCTNAME : public util::ConstructIn {
  public:
#include "../CONSTRUCTIN/POPULATEVARS.hh"
};

#include "../CONSTRUCTIN/FROMJSON.hh"

#undef CONSTRUCTKEYS
#undef CONSTRUCTNAME
}
