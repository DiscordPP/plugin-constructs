//
// Created by Aidan on 1/9/2021.
//

//#include <fmt/format.h>

#include "message.hh"

namespace discordpp {
/*void Message::get(const sptr<const handleWrite> &onWrite,
                    const sptr<const handleReadX<MessageIn>> &onRead) {
    bot->call(std::make_shared<Call>(
        std::make_shared<const std::string>("GET"),
        std::make_shared<const std::string>(
            fmt::format("/channels/{}/messages/", *channel_id, *id)),
        std::make_shared<const json>(nullptr), onWrite,
        std::make_shared<const handleRead>(
            [onRead](bool error, const json &msg) {
                (*onRead)(error, msg["body"].get<MessageIn>());
            })));
}*/
/*void MessageIn::crosspost(sptr<const handleWrite> onWrite,
                          sptr<const handleReadX<Message>> onRead) {}
void MessageIn::createReaction(const std::string &emoji) {}
void MessageIn::createReaction(const std::string emoji,
                               sptr<const handleWrite> onWrite,
                               sptr<const handleReadEmpty> onRead) {}
void MessageIn::createReaction(const Emoji emoji) {}
void MessageIn::createReaction(const Emoji emoji,
                               sptr<const handleWrite> onWrite,
                               sptr<const handleReadEmpty> onRead) {}
void MessageIn::deleteReaction(const std::string &emoji) {}
void MessageIn::deleteReaction(const std::string &emoji,
                               sptr<const handleWrite> onWrite,
                               sptr<const handleReadEmpty> onRead) {}
void MessageIn::deleteReaction(const Emoji &emoji) {}
void MessageIn::deleteReaction(const Emoji &emoji,
                               sptr<const handleWrite> onWrite,
                               sptr<const handleReadEmpty> onRead) {}
void MessageIn::deleteReaction(const std::string &emoji,
                               const Snowflake &user) {}
void MessageIn::deleteReaction(const std::string &emoji, const Snowflake &user,
                               sptr<const handleWrite> onWrite,
                               sptr<const handleReadEmpty> onRead) {}
void MessageIn::deleteReaction(const std::string &emoji, const User &user) {}
void MessageIn::deleteReaction(const std::string &emoji, const User &user,
                               sptr<const handleWrite> onWrite,
                               sptr<const handleReadEmpty> onRead) {}
void MessageIn::deleteReaction(const Emoji &emoji, const Snowflake &user) {}
void MessageIn::deleteReaction(const Emoji &emoji, const Snowflake &user,
                               sptr<const handleWrite> onWrite,
                               sptr<const handleReadEmpty> onRead) {}
void MessageIn::deleteReaction(const Emoji &emoji, const User &user) {}
void MessageIn::deleteReaction(const Emoji &emoji, const User &user,
                               sptr<const handleWrite> onWrite,
                               sptr<const handleReadEmpty> onRead) {}
void MessageIn::getReactions(const std::string &emoji,
                             sptr<const handleWrite> onWrite,
                             sptr<const handleReadX<std::vector<User>>> onRead,
                             const int &limit) {}
void MessageIn::getReactions(const Emoji &emoji,
                             sptr<const handleWrite> onWrite,
                             sptr<const handleReadX<std::vector<User>>> onRead,
                             const int &limit) {}
void MessageIn::getReactionsBefore(
    const std::string &emoji, const User &before,
    sptr<const handleWrite> onWrite,
    sptr<const handleReadX<std::vector<User>>> onRead, const int &limit) {}
void MessageIn::getReactionsBefore(
    const std::string &emoji, const Snowflake &before,
    sptr<const handleWrite> onWrite,
    sptr<const handleReadX<std::vector<User>>> onRead, const int &limit) {}
void MessageIn::getReactionsBefore(
    const Emoji &emoji, const User &before, sptr<const handleWrite> onWrite,
    sptr<const handleReadX<std::vector<User>>> onRead, const int &limit) {}
void MessageIn::getReactionsBefore(
    const Emoji &emoji, const Snowflake &before,
    sptr<const handleWrite> onWrite,
    sptr<const handleReadX<std::vector<User>>> onRead, const int &limit) {}
void MessageIn::getReactionsAfter(
    const std::string &emoji, const User &after,
    sptr<const handleWrite> onWrite,
    sptr<const handleReadX<std::vector<User>>> onRead, const int &limit) {}
void MessageIn::getReactionsAfter(
    const std::string &emoji, const Snowflake &after,
    sptr<const handleWrite> onWrite,
    sptr<const handleReadX<std::vector<User>>> onRead, const int &limit) {}
void MessageIn::getReactionsAfter(
    const Emoji &emoji, const User &after, sptr<const handleWrite> onWrite,
    sptr<const handleReadX<std::vector<User>>> onRead, const int &limit) {}
void MessageIn::getReactionsAfter(
    const Emoji &emoji, const Snowflake &after, sptr<const handleWrite> onWrite,
    sptr<const handleReadX<std::vector<User>>> onRead, const int &limit) {}
void MessageIn::getReactions(const std::string &emoji, const User &before,
                             const User &after, sptr<const handleWrite> onWrite,
                             sptr<const handleReadX<std::vector<User>>> onRead,
                             const int &limit) {}
void MessageIn::getReactions(const std::string &emoji, const Snowflake &before,
                             const Snowflake &after,
                             sptr<const handleWrite> onWrite,
                             sptr<const handleReadX<std::vector<User>>> onRead,
                             const int &limit) {}
void MessageIn::getReactions(const Emoji &emoji, const User &before,
                             const User &after, sptr<const handleWrite> onWrite,
                             sptr<const handleReadX<std::vector<User>>> onRead,
                             const int &limit) {}
void MessageIn::getReactions(const Emoji &emoji, const Snowflake &before,
                             const Snowflake &after,
                             sptr<const handleWrite> onWrite,
                             sptr<const handleReadX<std::vector<User>>> onRead,
                             const int &limit) {}
void MessageIn::deleteReactions() {}
void MessageIn::deleteReactions(sptr<const handleWrite> onWrite,
                                sptr<const handleReadEmpty> onRead) {}
void MessageIn::deleteReactions(const Emoji &emoji) {}
void MessageIn::deleteReactions(const Emoji &emoji,
                                sptr<const handleWrite> onWrite,
                                sptr<const handleReadEmpty> onRead) {}
void MessageIn::deleteReactions(const std::string &emoji) {}
void MessageIn::deleteReactions(const std::string &emoji,
                                sptr<const handleWrite> onWrite,
                                sptr<const handleReadEmpty> onRead) {}
void MessageIn::edit(const MessageOut &message) {}
void MessageIn::edit(const MessageOut &message, sptr<const handleWrite> onWrite,
                     sptr<const handleReadX<Message>> onRead) {}
void MessageIn::deleteThis() {}
void MessageIn::deleteThis(sptr<const handleWrite> onWrite,
                           sptr<const handleReadEmpty> onRead) {}*/
} // namespace discordpp