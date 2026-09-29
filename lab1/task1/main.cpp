#include "../modules/FileManager.hpp"
#include <string>
#include <fstream>
#include <iostream>

int main(int argc, char** argv)
{
    if (argc != 3)
    {
        throw std::runtime_error("Use: copyfile.exe <input file name> <output file name>");
    }
    
    std::ifstream from = FileManager::GetInputStream((std::string)argv[1]);
    std::ofstream to = FileManager::GetOutputStream((std::string)argv[2]);
    
    while (!from.eof())
    {
        std::string line = "";
        from >> line;
        to << line << std::endl;
    }

    return 0;    
}