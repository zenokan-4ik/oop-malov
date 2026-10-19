#pragma once

#include "./CPoint.hpp"
#include "./ISolidShape.hpp"

class CCircle : public ISolidShape
{
public:
    CCircle(uint32_t outlineColor, uint32_t fillColor, CPoint center, double radius):
        ISolidShape(outlineColor, fillColor), m_center(center), m_radius(radius) {};
    
    double GetArea() const override;
    double GetPerimeter() const override;
    std::string ToString() const override;
    CPoint GetCenter() const;
    double GetRadius() const;
private:
    CPoint m_center;
    double m_radius;
};