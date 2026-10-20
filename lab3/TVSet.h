#pragma once

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
    bool m_isOn;
    int m_channel;
    int m_savedChannel;
};
