#include "../headers/CLineSegment.hpp"

#include "../headers/CConst.hpp"
#include <format>

double CLineSegment::GetArea() const
{
    return 0;
}

double CLineSegment::GetPerimeter() const
{
    return this->m_startPoint.GetDistance(this->m_endPoint);
}

std::string CLineSegment::ToString() const
{
    return std::format(CConst::LINE_FORMAT, this->m_startPoint.ToString(), this->m_endPoint.ToString(), this->GetPerimeter(), this->GetOutlineColor());
}

CPoint CLineSegment::GetStartPoint() const
{
    return this->m_startPoint;
}

CPoint CLineSegment::GetEndPoint() const
{
    return this->m_endPoint;
}