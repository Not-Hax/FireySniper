#ifndef CONFIG_JSON_HPP
#define CONFIG_JSON_HPP

#include <stdexcept>
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>
#include <stdexcept>

namespace firey 
{
    // ConfigJson
    // Configurations of applications are often set via Config.json files
    // This lets you change settings without needing to recompile your app
    // The problem is, that most settings have default values
    // while this is no problem in languages like python (dict has a set_default value function)
    // this is a problem in c++ because you can't set default values in maps or nlohmann::json
    // so this small struct lets you fix it

    struct ConfigJson
    {
        ConfigJson() = default;
        ConfigJson(const std::string& input);
        ConfigJson(const nlohmann::json &input,
                   const nlohmann::json &default_);

        nlohmann::json& merge();
        nlohmann::json& operator[](const std::string &idx);

        template <typename T>
        void set_default(const std::string &idx,
                         const T &value)
        {
            default_json[idx] = value;
        }


        inline nlohmann::json& get_default() { return default_json; }
        inline nlohmann::json& get_input() { return input_json; }
        inline nlohmann::json& get() {return json;}

    private:
        nlohmann::json default_json;
        nlohmann::json input_json;

        nlohmann::json json;
    };

}

#endif