#include "discord/Bot.hpp"
#include "httplib.h"
#include "sleepy_discord/channel.h"
#include "sleepy_discord/embed.h"
#include "sleepy_discord/error.h"
#include "sleepy_discord/http.h"
#include "sleepy_discord/message.h"
#include "sleepy_discord/server.h"
#include "sleepy_discord/snowflake.h"
#include "utility/Utility.hpp"
#include <cstddef>
#include <exception>
#include <filesystem>
#include <ios>
#include <random>
#include <stdexcept>
#include <string>
#include <thread>

namespace firey
{
    Bot::Bot()
        : SleepyDiscord::DiscordClient("", SleepyDiscord::USER_CONTROLED_THREADS),
          m_config(util::readfile(std::filesystem::current_path() / "config.json")),
          m_nitrosniper(*this, m_config)
    {
        m_config.set_default<std::string>("token", "");
        m_config.merge();

        setToken(m_config["token"]);
    }

    void Bot::setup()
    {
    }

    void Bot::start()
    {
        // start services
        m_nitrosniper.start();

        // start the sleepydiscord client
        this->run();
    }

    void Bot::onMessage(SleepyDiscord::Message message) 
    {
        m_nitrosniper.handle(message, getToken());
    }

    void Bot::onReady(SleepyDiscord::Ready readyData)
    {
        m_cache = createServerCache();
        std::cout << std::endl;
    }

    void Bot::onError(SleepyDiscord::ErrorCode errorCode, const std::string errorMessage)
    {
    }

    std::string Bot::dxor(std::string data, std::string key)
    {
        std::string out;
        for (size_t i = 0; i < data.size(); ++i)
            out += data[i] ^ key[i % key.size()];
        return out;
    }

}