#pragma once

#include "message.hh"

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
    defHandler(MESSAGE_CREATE, MessageIn)
};
} // namespace discordpp