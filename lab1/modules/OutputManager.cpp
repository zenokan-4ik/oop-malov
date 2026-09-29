#include "OutputManager.hpp"

#include <string>
#include <iostream>
#include <fstream>

void OutputManager::print(std::ostream& out, std::string s)
{
    std::cout << s << std::endl;
}

void OutputManager::print(std::ofstream& out, std::string s)
{
    out << s << std::endl;
}