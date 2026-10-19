#pragma once

#include "./CPoint.hpp"
#include "./ISolidShape.hpp"

class CTriangle : public ISolidShape
{
public:
    CTriangle(uint32_t outlineColor, uint32_t fillColor, CPoint vertex1, CPoint vertex2, CPoint vertex3):
        ISolidShape(outlineColor, fillColor), m_vertex1(vertex1), m_vertex2(vertex2), m_vertex3(vertex3) {};

    double GetArea() const override;
    double GetPerimeter() const override;
    std::string ToString() const override;
    CPoint GetVertex1() const;
    CPoint GetVertex2() const;
    CPoint GetVertex3() const;
private:
    CPoint m_vertex1, m_vertex2, m_vertex3;
};