//
// Created by Aidan on 1/15/2021.
//

#pragma once

#include <string>

#include <nlohmann/json.hpp>

#include <discordpp/bot.hh>

#include "discordpp/types/nonce.hh"
#include "discordpp/util/construct.hh"
#include "todo.hh"

namespace discordpp {
// clang-format off
#define CONSTRUCTNAME Channel
#define CONSTRUCTKEYS \
    key(SNOWFLAKE, id) \
    key(DEF(ChannelType), type) \
    key(OPT(SNOWFLAKE), guild_id) \
    key(OPT(DEF(int)), position) \
    key(OPT(DEF(std::vector<Overwrite>)), permission_overwrites) \
    key(OPT(DEF(std::string)), name) \
    key(OPT(DEF(std::string)), topic) \
    key(OPT(DEF(bool)), nsfw) \
    key(OPT(SNOWFLAKE), last_message_id) \
    key(OPT(DEF(int)), bitrate) \
    key(OPT(DEF(int)), user_limit) \
    key(OPT(DEF(int)), rate_limit_per_user) \
    key(OPT(DEF(std::vector<User>)), recipients) \
    key(OPT(DEF(std::string)), icon) \
    key(OPT(SNOWFLAKE), owner_id) \
    key(OPT(SNOWFLAKE), application_id) \
    key(OPT(SNOWFLAKE), parent_id) \
    key(OPT(TIMESTAMP), last_pin_timestamp)
// clang-format on

class CONSTRUCTNAME : public util::ConstructIn {
  public:
#include "discordpp/CONSTRUCTIN/POPULATEVARS.hh"
};

#include "discordpp/CONSTRUCTIN/FROMJSON.hh"

#undef CONSTRUCTKEYS
#undef CONSTRUCTNAME
} // namespace discordpp
