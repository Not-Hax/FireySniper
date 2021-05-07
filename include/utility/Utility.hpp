#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <vector>
#include <cctype>
#include <functional>
#include <fstream>
#include <random>
#include <map>
#include <string>
#include <filesystem>
#include <iostream>
#include <sstream>
#include <nlohmann/json.hpp>
#include <string.h>

namespace firey
{
    namespace util
    {
        std::string readfile(const std::string &path);
    }
}

#endif