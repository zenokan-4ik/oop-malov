#include "../headers/CPoint.hpp"

#include <string>
#include <cmath>

std::string CPoint::ToString() const
{
    return std::format("({}, {})", this->x, this->y);
};

double CPoint::GetDistance(const CPoint& other) const
{
    return std::sqrt(std::pow(other.x - this->x, 2) + std::pow(other.y - this->y, 2));
}
