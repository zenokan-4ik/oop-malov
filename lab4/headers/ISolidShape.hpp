#pragma once

#include "./IShape.hpp"

class ISolidShape : public IShape 
{
public:
    ISolidShape(uint32_t outlineColor, uint32_t fillColor):
        IShape(outlineColor), m_fillColor(fillColor) {};
    virtual ~ISolidShape() = default;

    virtual uint32_t GetFillColor() const
    {
        return this->m_fillColor;
    };

private:
    uint32_t m_fillColor;
};