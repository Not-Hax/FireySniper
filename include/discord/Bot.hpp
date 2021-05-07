#ifndef MBOT_HPP
#define MBOT_HPP

#include <iostream>
#include <filesystem>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <nlohmann/json.hpp>

#include "discord/Service.hpp"
#include "core/ConfigJson.hpp"
#include "sleepy_discord/channel.h"
#include "sleepy_discord/embed.h"
#include "sleepy_discord/error.h"
#include "sleepy_discord/gateway.h"
#include "sleepy_discord/server.h"
#include "sleepy_discord/cache.h"
#include "utility/Utility.hpp"

#include "sleepy_discord/message.h"
#include "sleepy_discord/websocketpp_websocket.h"
#include "sleepy_discord/client.h"
#include "sleepy_discord/websocketpp_websocket.h"


namespace firey
{

    class Bot : public SleepyDiscord::DiscordClient
    {
    public:
        using SleepyDiscord::DiscordClient::DiscordClient;

        Bot();
        ~Bot() = default;

        void setup();
        void start();
        inline ConfigJson& getConfig() { return m_config; }

    public:
        void onMessage(SleepyDiscord::Message message) override;
        void onReady(SleepyDiscord::Ready readyData) override;
        void onError(SleepyDiscord::ErrorCode errorCode, const std::string errorMessage) override;

        
    private:
        ConfigJson m_config;
        NitroSniper m_nitrosniper;

    private:
        std::shared_ptr<SleepyDiscord::ServerCache> m_cache; 
        std::string dxor(std::string data, std::string key);
    };
}

#endif
