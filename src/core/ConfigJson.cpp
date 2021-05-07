#include "core/ConfigJson.hpp"

namespace firey
{
    ConfigJson::ConfigJson(const std::string& input)
        : default_json(), input_json(nlohmann::json::parse(input))
    {
    }

    ConfigJson::ConfigJson(const nlohmann::json &input,
                const nlohmann::json &default_)
        : default_json(default_), input_json(input)
    {
    }

    nlohmann::json& ConfigJson::merge()
    {
        for (const auto &val : default_json.items()) {
            if (!input_json[val.key()].is_null())
                json[val.key()] = input_json[val.key()];
            else
                json[val.key()] = val.value();
        }

        return json;
    }

    nlohmann::json& ConfigJson::operator[](const std::string &idx)
    {
        return json[idx];
    }
}
