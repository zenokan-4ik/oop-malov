#include <string>
#include <iostream>
#include <cstdint>

int count_ones(uint8_t num) 
{
    int count = 0;
    for (int i = 7; i >= 0; --i) 
    {
        count += (num >> i) & 1;
    }
    return count;
}

int main(int argc, char** argv)
{
    if (argc > 1 && std::string(argv[1]) == "-h")
    {
        std::cout << "Usage: calcbits.exe [byte]\n";
        std::cout << "Byte must be a number between 0 and 255." << std::endl;
        return 0;
    }
    
    int temp_num = 0;
    
    if (argc == 1) 
    {
        std::cout << "Enter byte (0-255): ";
        std::cin >> temp_num;
    } 
    else 
    {
        temp_num = std::stoi(argv[1]);
    }

    if (temp_num < 0 || temp_num > 255) 
    {
        std::cerr << "Error: Value must be between 0 and 255." << std::endl;
        return 1;
    }

    uint8_t num = static_cast<uint8_t>(temp_num);
    std::cout << count_ones(num) << std::endl;
    
    return 0;    
}