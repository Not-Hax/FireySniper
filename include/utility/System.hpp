#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdio>
#include <memory>
#include <array>
#include <filesystem>
#include <cctype>

#include "utility/Utility.hpp"

#ifdef _WIN32
    #define OS_WINDOWS
#elif _WIN64
    #define OS_WINDOWS
#else
    #define OS_LINUX
#endif

namespace firey
{
    namespace system
    {
    }
}

#endif