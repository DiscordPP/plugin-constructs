//
// Created by Aidan on 1/9/2021.
//

#pragma once

#include <string>

#include <nlohmann/json.hpp>

#include <discordpp/bot.hh>

#include "../types/nonce.hh"
#include "sticker.hh"
#include "../util/construct.hh"
#include "todo.hh"

namespace discordpp {

enum MessageActivityType : int{
    JOIN [[maybe_unused]] = 1,
    SPECTATE [[maybe_unused]] = 2,
    LISTEN [[maybe_unused]] = 3,
    JOIN_REQUEST [[maybe_unused]] = 5
};

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


enum MessageType : int{
    DEFAULT [[maybe_unused]] = 0,
    RECIPIENT_ADD [[maybe_unused]] = 1,
    RECIPIENT_REMOVE [[maybe_unused]] = 2,
    CALL [[maybe_unused]] = 3,
    CHANNEL_NAME_CHANGE [[maybe_unused]] = 4,
    CHANNEL_ICON_CHANGE [[maybe_unused]] = 5,
    CHANNEL_PINNED_MESSAGE  [[maybe_unused]] = 6,
    GUILD_MEMBER_JOIN  [[maybe_unused]] = 7,
    USER_PREMIUM_GUILD_SUBSCRIPTION  [[maybe_unused]] = 8,
    USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_1  [[maybe_unused]] = 9,
    USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_2  [[maybe_unused]] = 10,
    USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_3  [[maybe_unused]] = 11,
    CHANNEL_FOLLOW_ADD  [[maybe_unused]] = 12,
    GUILD_DISCOVERY_DISQUALIFIED  [[maybe_unused]] = 14,
    GUILD_DISCOVERY_REQUALIFIED  [[maybe_unused]] = 15,
    REPLY  [[maybe_unused]] = 19,
    APPLICATION_COMMAND  [[maybe_unused]] = 20
};

enum MessageFlag : int{
    CROSSPOSTED  [[maybe_unused]] = 1 << 0,
    IS_CROSSPOST  [[maybe_unused]] = 1 << 1,
    SUPPRESS_EMBEDS  [[maybe_unused]] = 1 << 2,
    SOURCE_MESSAGE_DELETED  [[maybe_unused]] = 1 << 3,
    URGENT  [[maybe_unused]] = 1 << 4
};

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
