#pragma once

#include "./IShape.hpp"
#include "./CPoint.hpp"

class CLineSegment : public IShape
{
public:
    CLineSegment(uint32_t outlineColor, CPoint startPoint, CPoint endPoint): 
        IShape(outlineColor), m_startPoint(startPoint), m_endPoint(endPoint) {};

    double GetArea() const override;
    double GetPerimeter() const override;
    std::string ToString() const override;
    CPoint GetStartPoint() const;
    CPoint GetEndPoint() const;
private:
    CPoint m_startPoint, m_endPoint;
};