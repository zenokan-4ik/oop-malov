#pragma once

#include <fstream>

class FileManager
{
public:
    static std::ifstream GetInputStream(std::string filename);
    static std::ofstream GetOutputStream(std::string filename);
};