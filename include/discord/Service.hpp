#ifndef SERVICE_HPP
#define SERVICE_HPP

#include "core/ConfigJson.hpp"
#include "sleepy_discord/websocketpp_websocket.h"
#define CPPHTTPLIB_OPENSSL_SUPPORT
#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <chrono>
#include <future>

#include <sleepy_discord/sleepy_discord.h>
#include <sleepy_discord/message.h>
#include <httplib.h>

#include "utility/Utility.hpp"

namespace firey
{
    class Service
    {
    public:
        Service(SleepyDiscord::DiscordClient& client,
                ConfigJson& json);

        virtual bool start();
        virtual bool stop();

        virtual void handle(SleepyDiscord::Message &msg, const std::string &token);
        inline bool is_running() {return running;}

    protected:
        bool running = false;
        SleepyDiscord::DiscordClient &client;
        ConfigJson& json;
    };

    class NitroSniper : public Service
    {
    public:
        using Service::Service;
        virtual void handle(SleepyDiscord::Message &msg, const std::string &token) override;

    };
}


#endif
