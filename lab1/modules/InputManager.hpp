#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

class InputManager
{
public:
    static std::string GetLine(std::istream& in);
    static std::string GetLine(std::ifstream& in);
    // static std::vector<std::string> GetParsedLine(std::istream& in);
    // static std::vector<std::string> GetParsedLine(std::ifstream& in);
    static bool IsEmpty(const std::string s);
};