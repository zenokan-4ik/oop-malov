#include <string>
#include <fstream>
#include <iostream>
#include <cstdint>

// TODO: Fix this, incorrect work
int count_ones(uint8_t num) 
{
    int count = 0;

    for (int i = 7; i >= 0; --i) 
    {
        int bit = (num >> i) & 1;
        
        count += bit;
    }
    return count;
}

int main(int argc, char** argv)
{
    if (argc > 1 && std::string(argv[1]) == "-h")
    {
        std::cout << "Use via cmd: calcbits.exe <byte>" << std::endl << "Use via stdin: calcbits.exe. Next line is <byte>";
    }
    else if (argc > 2)
    {
        throw std::runtime_error("Use 'copyfile.exe -h' to get help");
    }
    
    uint8_t num{};
    if (argc == 1) 
    {
        std::cout << "Enter byte : ";
        std::cin >> num;
    } else
    {
        num = std::stoi(argv[1]);
    }
    std::cout << count_ones(num);
    return 0;    
}