#pragma once

#include <format>

class CPoint
{
public:
    CPoint(double x, double y): x(x), y(y) {};
    CPoint() = default;

    double GetDistance(const CPoint& other) const;
    std::string ToString() const;

    double x, y;
};