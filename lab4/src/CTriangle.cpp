#include "../headers/CTriangle.hpp"

#include "../headers/CConst.hpp"
#include <string>
#include <format>
#include <cmath>

double CTriangle::GetArea() const
{
    double a, b, c, p;
    a = this->m_vertex1.GetDistance(this->m_vertex2);
    b = this->m_vertex2.GetDistance(this->m_vertex3);
    c = this->m_vertex3.GetDistance(this->m_vertex1);
    p = (a + b + c)/2;

    return std::sqrt(p*(p-a)*(p-b)*(p-c));
}

double CTriangle::GetPerimeter() const
{
    double a, b, c;
    a = this->m_vertex1.GetDistance(this->m_vertex2);
    b = this->m_vertex2.GetDistance(this->m_vertex3);
    c = this->m_vertex3.GetDistance(this->m_vertex1);

    return a+b+c;
}

std::string CTriangle::ToString() const
{
    return std::format(CConst::TRIANGLE_FORMAT, this->m_vertex1.ToString(), this->m_vertex2.ToString(), this->m_vertex3.ToString(), this->GetArea(), this->GetPerimeter(), this->GetOutlineColor(), this->GetFillColor());
}

CPoint CTriangle::GetVertex1() const
{
    return this->m_vertex1;
}

CPoint CTriangle::GetVertex2() const
{
    return this->m_vertex2;
}

CPoint CTriangle::GetVertex3() const
{
    return this->m_vertex3;
}