#include <iostream>
#include <string>

std::string TrimBlanks(std::string const& str);

int main() 
{
    std::string line;
    while (std::getline(std::cin, line)) 
    {
        std::cout << TrimBlanks(line) << std::endl;
    }
    return 0;
}