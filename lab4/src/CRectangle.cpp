#include "../headers/CRectangle.hpp"

#include "../headers/CConst.hpp"
#include <cmath>
#include <format>

double CRectangle::GetArea() const
{
    return this->m_height * this->m_width;
}

double CRectangle::GetPerimeter() const
{
    return 2*this->m_height + 2*this->m_width;
}

std::string CRectangle::ToString() const
{
    return std::format(CConst::RECTANGLE_FORMAT, this->m_height, this->m_width, this->GetArea(), this->GetPerimeter());
}

CPoint CRectangle::GetLeftTop() const
{
    return this->m_leftTop;
}

CPoint CRectangle::GetRightBottom() const
{
    return this->m_rightBottom;
}

double CRectangle::GetHeight() const
{
    return this->m_height;
}

double CRectangle::GetWidth() const
{
    return this->m_width;
}