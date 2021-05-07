#include "discord/Service.hpp"
#include "core/ConfigJson.hpp"
#include "sleepy_discord/channel.h"
#include "sleepy_discord/websocketpp_websocket.h"
#include "utility/System.hpp"
#include <chrono>
#include <future>
#include <ios>
#include <thread>
#include <discord/Bot.hpp>
#include <termcolor/termcolor.hpp>

namespace firey
{

    Service::Service(SleepyDiscord::DiscordClient &client,
                     ConfigJson& json)
        : client(client),
          json(json)
    {
    }

    bool Service::start() 
    {
        if (running)
            return false;

        running = true;
        return true;
    }

    bool Service::stop() 
    {
        if (!running)
            return false;

        running = false;
        return true;
    }

    void Service::handle(SleepyDiscord::Message &msg, const std::string &token)
    {
        if (!running)
            return;
    }

    void NitroSniper::handle(SleepyDiscord::Message &msg, const std::string &token) {
        if (!running)
            return;

        std::regex code_regex("(discord.com/gifts/|discordapp.com/gifts/|discord.gift/)([a-zA-Z0-9]+)");
        std::smatch match;
        const std::string content = msg.content;

        if (std::regex_search(content.begin(), content.end(), match, code_regex))
        {
            httplib::SSLClient client("discordapp.com");
            // auto start = std::chrono::high_resolution_clock::now();
            std::string code = match[2].str();

            if (code.size() < 16)
                return;
            
            std::string path = "/api/v8/entitlements/gift-codes/" + code + "/redeem";
            httplib::Headers headers = {
                { "Authorization", token}
            };
            std::string response = client.Post(path.c_str(), headers, "{\"channel_id\": 0}", "application/json")->body;

            if (response.find("nitro") != std::string::npos)
                std::cout << termcolor::green << ("Nitro code found by @") << msg.author.username << std::endl;
            else
                std::cout << termcolor::red << ("Invalid nitro code found by @") << msg.author.username << std::endl;

            // auto finish = std::chrono::high_resolution_clock::now();
            // auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
            // std::cout << "[#] " << duration.count() << "ms [#]\n";
        }
    }

}