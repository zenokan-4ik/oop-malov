#include <string>

std::string TrimBlanks(std::string const& str) 
{
    if (str.empty()) 
    {
        return "";
    }
    
    size_t start = 0;
    while (start < str.size() && str[start] == ' ') 
    {
        start++;
    }
    
    if (start == str.size()) 
    {
        return "";
    }
    
    size_t end = str.size() - 1;
    while (end > start && str[end] == ' ') 
    {
        end--;
    }
    
    return str.substr(start, end - start + 1);
}