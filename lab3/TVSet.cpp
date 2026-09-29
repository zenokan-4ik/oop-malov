#include "TVSet.h"

TVSet::TVSet() : m_isOn(false), m_channel(0), m_savedChannel(1) {}

void TVSet::TurnOn()
{
    if (!m_isOn) 
    {
        m_isOn = true;
        m_channel = m_savedChannel;
    }
}

void TVSet::TurnOff()
{
    if (m_isOn) 
    {
        m_isOn = false;
        m_savedChannel = m_channel;
        m_channel = 0;
    }
}

bool TVSet::SelectChannel(int channel)
{
    if (!m_isOn)
    {
        return false;
    }
    
    if (channel < 1 || channel > 99)
    {
        return false;
    }
    
    this->m_channel = channel;
    return true;
}

bool TVSet::IsOn() const
{
    return m_isOn;
}

int TVSet::GetChannel() const
{
    return m_channel;
}