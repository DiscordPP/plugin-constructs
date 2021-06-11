//
// Created by Aidan on 1/10/2021.
//

#pragma once

#include <nlohmann/json.hpp>

namespace discordpp {
using json = nlohmann::json;

// using AllowedMentions = json;
using Attachment = json;
using Channel = json;
using ChannelMention = json;
using Embed = json;
// using Emoji = json;
using Guild = json;
// https://discord.com/developers/docs/topics/gateway#guild-member-add
/* w/ extra `guild_id` key */ using GuildMember = json;
// using Overwrite = json;
using User = json;
} // namespace discordpp
