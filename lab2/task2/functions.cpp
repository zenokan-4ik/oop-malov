#include <string>

std::string TrimBlanks(std::string const& str) 
{
    if (str.empty()) 
    {
        return "";
    }

    size_t start{};
    size_t end{};

    start = str.find_first_not_of(" ");
    end = str.find_last_not_of(" ");

    if(start == std::string::npos || end == std::string::npos)
    {
        return "";
    }
    
    return str.substr(start, end - start + 1);
}