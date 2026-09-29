#pragma once

#include <string>

class TVSet 
{
public:
    TVSet();
    
    void TurnOn();
    void TurnOff();
    bool SelectChannel(int channel);
    
    bool IsOn() const;
    int GetChannel() const;

private:
    bool isOn;
    int channel;
    int savedChannel;
};
