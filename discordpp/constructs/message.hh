//
// Created by Aidan on 1/9/2021.
//

#pragma once

#include <string>

#define JSON_USE_IMPLICIT_CONVERSIONS 0
#include <nlohmann/json.hpp>

#include <discordpp/bot.hh>

#include "sticker.hh"
#include "../util/construct.hh"
#include "todo.hh"

namespace discordpp {

// clang-format off
#define CONSTRUCTNAME MessageActivity
#define CONSTRUCTKEYS \
    key(DEF(MessageActivityType), type) \
    key(OPT(DEF(std::string)), party_id)
// clang-format on

class CONSTRUCTNAME : public util::ConstructIn {
#include "../CONSTRUCTIN/POPULATEVARS.hh"
};

#include "../CONSTRUCTIN/FROMJSON.hh"

#undef CONSTRUCTKEYS
#undef CONSTRUCTNAME

// clang-format off
#define CONSTRUCTNAME MessageApplication
#define CONSTRUCTKEYS \
    key(SNOWFLAKE, id) \
    key(OPT(SNOWFLAKE), cover_image) \
    key(SNOWFLAKE, description) \
    key(DEF(std::string), icon) \
    key(DEF(std::string), name)
// clang-format on

class CONSTRUCTNAME : public util::ConstructIn {
#include "../CONSTRUCTIN/POPULATEVARS.hh"
};

#include "../CONSTRUCTIN/FROMJSON.hh"

#undef CONSTRUCTKEYS
#undef CONSTRUCTNAME

// clang-format off
#define CONSTRUCTNAME MessageReference
#define CONSTRUCTKEYS \
    key(OPT(SNOWFLAKE), message_id) \
    key(OPT(SNOWFLAKE), channel_id) \
    key(OPT(SNOWFLAKE), guild_id)
// clang-format on

class CONSTRUCTNAME : public util::ConstructIn {
#include "../CONSTRUCTIN/POPULATEVARS.hh"
};

#include "../CONSTRUCTIN/FROMJSON.hh"

#undef CONSTRUCTKEYS
#undef CONSTRUCTNAME

// clang-format off
#define CONSTRUCTNAME Message
#define CONSTRUCTKEYS \
    key(SNOWFLAKE, id) \
    key(SNOWFLAKE, channel_id) \
    key(OPT(SNOWFLAKE), guild_id) \
    key(DEF(User), author) \
    key(OPT(DEF(GuildMember)), member) \
    key(DEF(std::string), content) \
    key(TIME, timestamp) \
    key(TIME, edited_timestamp) \
    key(DEF(bool), tts) \
    key(DEF(bool), mention_everyone) \
    key(DEF(std::vector<User>), mentions) \
    key(SNOWFLAKE_ARR, mention_roles) \
    key(OPT(DEF(std::vector<ChannelMention>)), mention_channels) \
    key(DEF(std::vector<Attachment>), attachments) \
    key(DEF(std::vector<Embed>), embeds) \
    key(OPT(DEF(std::vector<json>)), reactions) \
    key(OPT(DEF(Nonce)), nonce) \
    key(DEF(bool), pinned) \
    key(OPT(SNOWFLAKE), webhook_id) \
    key(DEF(MessageType), type) \
    key(OPT(DEF(MessageActivity)), activity) \
    key(OPT(DEF(MessageApplication)), application) \
    key(OPT(DEF(MessageReference)), message_reference) \
    key(OPT(DEF(int)), flags) \
    key(OPT(DEF(std::vector<Sticker>)), stickers) \
    key(OPT(DEF(Message)), referenced_message)
// clang-format on

class CONSTRUCTNAME : public util::ConstructIn {
#include "../CONSTRUCTIN/POPULATEVARS.hh"
    /*void get(const sptr<const handleWrite> &onWrite,
             const sptr<const handleReadX<Message>> &onRead);*/

    /*void crosspost(sptr<const handleWrite> onWrite, sptr<const
    handleReadX<Message>> onRead);

    void createReaction(const std::string& emoji);
    void createReaction(const std::string emoji, sptr<const handleWrite>
    onWrite, sptr<const handleReadEmpty> onRead); void createReaction(const
    Emoji emoji); void createReaction(const Emoji emoji, sptr<const handleWrite>
    onWrite, sptr<const handleReadEmpty> onRead);

    void deleteReaction(const std::string& emoji);
    void deleteReaction(const std::string& emoji, sptr<const handleWrite>
    onWrite, sptr<const handleReadEmpty> onRead); void deleteReaction(const
    Emoji& emoji); void deleteReaction(const Emoji& emoji, sptr<const
    handleWrite> onWrite, sptr<const handleReadEmpty> onRead); void
    deleteReaction(const std::string& emoji, const Snowflake& user); void
    deleteReaction(const std::string& emoji, const Snowflake& user, sptr<const
    handleWrite> onWrite, sptr<const handleReadEmpty> onRead); void
    deleteReaction(const std::string& emoji, const User& user); void
    deleteReaction(const std::string& emoji, const User& user, sptr<const
    handleWrite> onWrite, sptr<const handleReadEmpty> onRead); void
    deleteReaction(const Emoji& emoji, const Snowflake& user); void
    deleteReaction(const Emoji& emoji, const Snowflake& user, sptr<const
    handleWrite> onWrite, sptr<const handleReadEmpty> onRead); void
    deleteReaction(const Emoji& emoji, const User& user); void
    deleteReaction(const Emoji& emoji, const User& user, sptr<const handleWrite>
    onWrite, sptr<const handleReadEmpty> onRead);

    void getReactions(const std::string& emoji, sptr<const handleWrite> onWrite,
    sptr<const handleReadX<std::vector<User>>> onRead, const int& limit = 0);
    void getReactions(const Emoji& emoji, sptr<const handleWrite> onWrite,
    sptr<const handleReadX<std::vector<User>>> onRead, const int& limit = 0);

    void getReactionsBefore(const std::string& emoji, const User& before,
    sptr<const handleWrite> onWrite, sptr<const handleReadX<std::vector<User>>>
    onRead, const int& limit = 0); void getReactionsBefore(const std::string&
    emoji, const Snowflake& before, sptr<const handleWrite> onWrite, sptr<const
    handleReadX<std::vector<User>>> onRead, const int& limit = 0); void
    getReactionsBefore(const Emoji& emoji, const User& before, sptr<const
    handleWrite> onWrite, sptr<const handleReadX<std::vector<User>>> onRead,
    const int& limit = 0); void getReactionsBefore(const Emoji& emoji, const
    Snowflake& before, sptr<const handleWrite> onWrite, sptr<const
    handleReadX<std::vector<User>>> onRead, const int& limit = 0);

    void getReactionsAfter(const std::string& emoji, const User& after,
    sptr<const handleWrite> onWrite, sptr<const handleReadX<std::vector<User>>>
    onRead, const int& limit = 0); void getReactionsAfter(const std::string&
    emoji, const Snowflake& after, sptr<const handleWrite> onWrite, sptr<const
    handleReadX<std::vector<User>>> onRead, const int& limit = 0); void
    getReactionsAfter(const Emoji& emoji, const User& after, sptr<const
    handleWrite> onWrite, sptr<const handleReadX<std::vector<User>>> onRead,
    const int& limit = 0); void getReactionsAfter(const Emoji& emoji, const
    Snowflake& after, sptr<const handleWrite> onWrite, sptr<const
    handleReadX<std::vector<User>>> onRead, const int& limit = 0);

    void getReactions(const std::string& emoji, const User& before, const User&
    after, sptr<const handleWrite> onWrite, sptr<const
    handleReadX<std::vector<User>>> onRead, const int& limit = 0); void
    getReactions(const std::string& emoji, const Snowflake& before, const
    Snowflake& after, sptr<const handleWrite> onWrite, sptr<const
    handleReadX<std::vector<User>>> onRead, const int& limit = 0); void
    getReactions(const Emoji& emoji, const User& before, const User& after,
    sptr<const handleWrite> onWrite, sptr<const handleReadX<std::vector<User>>>
    onRead, const int& limit = 0); void getReactions(const Emoji& emoji, const
    Snowflake& before, const Snowflake& after, sptr<const handleWrite> onWrite,
    sptr<const handleReadX<std::vector<User>>> onRead, const int& limit = 0);

    void deleteReactions();
    void deleteReactions(sptr<const handleWrite> onWrite, sptr<const
    handleReadEmpty> onRead); void deleteReactions(const Emoji& emoji); void
    deleteReactions(const Emoji& emoji, sptr<const handleWrite> onWrite,
    sptr<const handleReadEmpty> onRead); void deleteReactions(const std::string&
    emoji); void deleteReactions(const std::string& emoji, sptr<const
    handleWrite> onWrite, sptr<const handleReadEmpty> onRead);

    void edit(const MessageOut& message);
    void edit(const MessageOut& message, sptr<const handleWrite> onWrite,
    sptr<const handleReadX<Message>> onRead);

    void deleteThis();
    void deleteThis(sptr<const handleWrite> onWrite, sptr<const handleReadEmpty>
    onRead);*/
};

#include "../CONSTRUCTIN/FROMJSON.hh"

#undef CONSTRUCTKEYS
#undef CONSTRUCTNAME

/*class MessageOut : public Message {
  public:
    std::string content; // the message contents (up to 2000 characters)
    Nonce nonce;         // a nonce that can be used for optimistic message
                         // sending
    bool tts;            // true if this is a TTS message
    // FileContents file;  // the contents of the file being sent
    Embed embed;                        // embedded rich content
    std::string payload_json;           // JSON encoded body of any additional
                                        // request fields.
    AllowedMentions allowed_mentions;   // allowed mentions for a message
    MessageReference message_reference; // include to make your message a reply
};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(MessageOut, content, nonce, tts, embed,
                                   payload_json, allowed_mentions,
                                   message_reference);*/
} // namespace discordpp
