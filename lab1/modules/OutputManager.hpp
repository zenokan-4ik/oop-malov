#pragma once

#include <iostream>
#include <fstream>
#include <string>

class OutputManager
{
public:
    static void print(std::ostream& out, std::string s);
    static void print(std::ofstream& out, std::string s);
};