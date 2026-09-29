#include <string>
#include <fstream>
#include <iostream>
#include <cstdint>

int count_ones(int16_t num) 
{
    uint16_t unum = num; 
    std::string binary_str = "";
    int count = 0;

    for (int i = 15; i >= 0; --i) 
    {
        int bit = (unum >> i) & 1;
        
        binary_str += (bit ? '1' : '0');
        
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
    
    int16_t num{};
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