#include "utility/Utility.hpp"

namespace firey
{
    namespace util
    {
        std::string readfile(const std::string &path)
        {
            std::ifstream file(path);
            return std::string((std::istreambuf_iterator<char>(file)),
                                std::istreambuf_iterator<char>());
        }
    }
}