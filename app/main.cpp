#include "discord/Bot.hpp"
#include <termcolor/termcolor.hpp>
#include <thread>

int main()
{
    std::string str = "___________.__                       _________      .__                     \n\\_   _____/|__|______   ____ ___.__./   _____/ ____ |__|_____   ___________ \n |    __)  |  \\_  __ \\_/ __ <   |  |\\_____  \\ /    \\|  \\____ \\_/ __ \\_  __ \\\n |     \\   |  ||  | \\/\\  ___/\\___  |/        \\   |  \\  |  |_> >  ___/|  | \\/\n \\___  /   |__||__|    \\___  > ____/_______  /___|  /__|   __/ \\___  >__|   \n     \\/                    \\/\\/            \\/     \\/   |__|        \\/      ";
    std::cout << termcolor::magenta << str << std::endl << std::endl;

    std::ifstream file("config.json");
    if (!file.is_open())
    {
        using namespace std::chrono_literals;
        std::cout << termcolor::red << "Error: please create a config.json with your discord token..." << std::endl;
        char d;
        std::cin >> d;
        exit(-1);
    }

    firey::Bot bot;
    bot.setup();
    bot.start();

    return 0;
}