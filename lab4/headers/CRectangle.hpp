#pragma once

#include "./ISolidShape.hpp"
#include "./CPoint.hpp"

class CRectangle : public ISolidShape
{
public:
    CRectangle(uint32_t outlineColor, uint32_t fillColor, CPoint leftTop, CPoint rightBottom, double height, double width):
        ISolidShape(outlineColor, fillColor), m_leftTop(leftTop), m_rightBottom(rightBottom), m_height(height), m_width(width) {};

    double GetArea() const override;
    double GetPerimeter() const override;
    std::string ToString() const override;
    CPoint GetLeftTop() const;
    CPoint GetRightBottom() const;
    double GetHeight() const;
    double GetWidth() const;
private:
    CPoint m_leftTop, m_rightBottom;
    double m_height, m_width;
};