#include <iostream>
#include <string>
#include "TVSet.h"

void ProcessCommand(TVSet& tv, const std::string& command) 
{
    if (command == "TurnOn") 
    {
        tv.TurnOn();
        std::cout << "TV is turned on" << std::endl;
    }
    else if (command == "TurnOff") 
    {
        tv.TurnOff();
        std::cout << "TV is turned off" << std::endl;
    }
    else if (command == "Info") 
    {
        if (tv.IsOn()) 
        {
            std::cout << "TV is turned on" << std::endl;
            std::cout << "Channel is: " << tv.GetChannel() << std::endl;
        } else 
        {
            std::cout << "TV is turned off" << std::endl;
        }
    }
    else if (command.substr(0, 14) == "SelectChannel ") 
    {
        int channel = std::stoi(command.substr(14));
        if (tv.SelectChannel(channel)) 
        {
            std::cout << "Channel switched to: " << channel << std::endl;
        } else 
        {
            std::cout << "ERROR" << std::endl;
        }
    }
    else 
    {
        std::cout << "ERROR" << std::endl;
    }
}

int main() 
{
    TVSet tv;
    std::string line;
    
    while (std::getline(std::cin, line)) 
    {
        if (line.empty()) 
        {
            continue;
        }
        ProcessCommand(tv, line);
    }
    
    return 0;
}