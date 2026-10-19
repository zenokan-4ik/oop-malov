#include "../headers/CCircle.hpp"
#include "../headers/CConst.hpp"
#include <cmath>
#include <format>

double CCircle::GetArea() const
{
    return CConst::PI * std::pow(this->m_radius, 2);
}

double CCircle::GetPerimeter() const 
{
    return 2 * CConst::PI * this->m_radius;
}

std::string CCircle::ToString() const
{
    return std::format(CConst::CIRCLE_FORMAT, this->m_center.ToString(), this->m_radius, this->GetArea(), this->GetPerimeter());
}

CPoint CCircle::GetCenter() const
{
    return m_center;
}

double CCircle::GetRadius() const
{
    return m_radius;
}