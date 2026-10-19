#pragma once

#include <string>
#include <cstdint>

class IShape
{
public:
    IShape(uint32_t outlineColor):
        m_outlineColor(outlineColor) {};
    virtual ~IShape() = default;

    virtual double GetArea() const = 0;
    virtual double GetPerimeter() const = 0;
    virtual std::string ToString() const = 0;
    virtual uint32_t GetOutlineColor() const 
    {
        return this->m_outlineColor;
    };
private:
    uint32_t m_outlineColor;
};