#include "FileManager.hpp"

#include <fstream>

std::ifstream FileManager::GetInputStream(std::string filename)
{
    std::ifstream in;
    in.open(filename, std::ios::in);
    if (in.is_open())
    {
        return in;
    }
    throw std::runtime_error("Invalid file name");
}

std::ofstream FileManager::GetOutputStream(std::string filename)
{
    std::ofstream out;
    out.open(filename, std::ios::out);
    if (out.is_open())
    {
        return out;
    }
    throw std::runtime_error("Invalid file name");
}