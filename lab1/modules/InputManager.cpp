#include "InputManager.hpp"

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

std::string InputManager::GetLine(std::istream& in)
{
    std::string s;
    in >> s;
    return s;
}

std::string InputManager::GetLine(std::ifstream& in)
{
    std::string s;
    in >> s;
    return s;
}

bool InputManager::IsEmpty(const std::string s)
{
    bool result = s.empty();
    for(char ch : s)
    {
        result &= std::isspace(ch);
    }
    return result;
}