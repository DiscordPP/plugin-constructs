#pragma once

#include "discordpp/constructs/message.hh"

namespace discordpp {
template <class X> using handleEventX = std::function<void(const X &res)>;

template <class BASE> class PluginConstructs : public BASE, virtual BotStruct {
  public:
#define defHandler(EVENT, RESULT)                                              \
    void handle##EVENT(const handleEventX<RESULT> &handler) {                  \
        handle##EVENT(std::make_shared<handleEventX<RESULT>>(handler));        \
    }                                                                          \
    void handle##EVENT(const sptr<handleEventX<RESULT>> &handler) {            \
        handlers.insert({#EVENT, [handler](const json &msg) {                  \
                             (*handler)(msg.get<RESULT>());                    \
                         }});                                                  \
    }

    // https://discord.com/developers/docs/topics/gateway#commands-and-events-gateway-events
    defHandler(HELLO, json);
    defHandler(READY, json);
    defHandler(RESUMED, json);
    defHandler(RECONNECT, json);
    defHandler(INVALID_SESSION, json);
    defHandler(CHANNEL_CREATE, Channel);
    defHandler(CHANNEL_UPDATE, Channel);
    defHandler(CHANNEL_DELETE, Channel);
    defHandler(CHANNEL_PINS_UPDATE, json);
    defHandler(GUILD_CREATE, Guild);
    defHandler(GUILD_UPDATE, Guild);
    defHandler(GUILD_DELETE, Guild);
    defHandler(GUILD_BAN_ADD, json);
    defHandler(GUILD_BAN_REMOVE, json);
    defHandler(GUILD_EMOJIS_UPDATE, json);
    defHandler(GUILD_INTEGRATIONS_UPDATE, json);
    defHandler(GUILD_MEMBER_ADD, GuildMember);
    defHandler(GUILD_MEMBER_REMOVE, json);
    defHandler(GUILD_MEMBER_UPDATE, json);
    defHandler(GUILD_MEMBERS_CHUNK, json);
    defHandler(GUILD_ROLE_CREATE, json);
    defHandler(GUILD_ROLE_UPDATE, json);
    defHandler(GUILD_ROLE_DELETE, json);
    defHandler(INVITE_CREATE, json);
    defHandler(INVITE_DELETE, json);
    defHandler(MESSAGE_CREATE, Message);
    defHandler(MESSAGE_UPDATE, Message);
    defHandler(MESSAGE_DELETE, json);
    defHandler(MESSAGE_DELETE_BULK, json);
    defHandler(MESSAGE_REACTION_ADD, json);
    defHandler(MESSAGE_REACTION_REMOVE, json);
    defHandler(MESSAGE_REACTION_REMOVE_ALL, json);
    defHandler(MESSAGE_REACTION_REMOVE_EMOJI, json);
    defHandler(PRESENCE_UPDATE, json);
    defHandler(TYPING_START, json);
    defHandler(USER_UPDATE, User);
    defHandler(VOICE_STATE_UPDATE, json);
    defHandler(VOICE_SERVER_UPDATE, json);
    defHandler(WEBHOOKS_UPDATE, json);
    defHandler(INTERACTION_CREATE, json);

    /*class CreateMessageCall
        : public FileCall,
          public std::enable_shared_from_this<CreateMessageCall> {
        friend PluginConstructs;

      protected:
        explicit CreateMessageCall(BotStruct *bot) : FileCall(bot) {}
        using FileCall::target;
        using FileCall::payload;

    };*/

    /*
      private:
        template <typename T> struct ConstructedCall : protected Call {
          public:
            ConstructedCall(BotStruct *bot) : Call(), bot_(bot) {}

    #define defSetter(TYPE, NAME) \
        ConstructedCall<T> NAME(const TYPE &NAME) { \
            ConstructedCall<T>::NAME(std::make_shared<const TYPE>(NAME)); \
        } \
        ConstructedCall<T> NAME(sptr<const TYPE> &NAME) { \
            assert(this->NAME##_ == nullptr && "This call already has a(n) "
    #NAME \
                                               "!"); \
            this->NAME##_ = NAME; \
        }

            defSetter(std::string, requestType);
            defSetter(std::string, targetURL);
            defSetter(json, body);
            defSetter(handleWrite, onWrite);
            ConstructedCall<T> onRead(const handleReadX<T> &onRead) {
                ConstructedCall<T>::onRead(
                    std::make_shared<const handleReadX<T>>(onRead));
            }
            ConstructedCall<T> onRead(sptr<const handleReadX<T>> &onRead) {
                assert(this->onRead_ == nullptr &&
                       "This call already has an onRead!");
                Call::onRead_ = std::make_shared<const handleRead>(
                    [this](bool error, const json &msg) {
                        (*onRead_)(error, msg["body"].get<T>());
                    });
            }

            void go() {
                bot_->call(std::make_shared<Call>(new
    ConstructedCall<T>(this)));
            }

          protected:
            sptr<const handleReadX<T>> onRead_ = nullptr;

          private:
            BotStruct *bot_;
        };
        */
};

} // namespace discordpp