#include "TVSet.h"

TVSet::TVSet() : isOn(false), channel(0), savedChannel(1) {}

void TVSet::TurnOn()
{
    if (!isOn) {
        isOn = true;
        channel = savedChannel;
    }
}

void TVSet::TurnOff()
{
    if (isOn) {
        isOn = false;
        savedChannel = channel;
        channel = 0;
    }
}

bool TVSet::SelectChannel(int channel)
{
    if (!isOn)
    {
        return false;
    }
    
    if (channel < 1 || channel > 99)
    {
        return false;
    }
    
    this->channel = channel;
    return true;
}

bool TVSet::IsOn() const
{
    return isOn;
}

int TVSet::GetChannel() const
{
    return channel;
}