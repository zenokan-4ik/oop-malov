#pragma once

class CConst
{
public:
    static constexpr double PI = 3.14;
    static constexpr auto CIRCLE_FORMAT = "Circle (center - {}, radius - {}, area - {}, perimeter - {})";
    static constexpr auto LINE_FORMAT = "Line (start - {}, end - {}, length - {}";
    static constexpr auto RECTANGLE_FORMAT = "Rectangle (heigth - {}, width - {}, area - {}, perimeter - {})";
    static constexpr auto TRIANGLE_FORMAT = "Triangle (vertex1 - {}, vertex2 - {}, vertex3 - {}, area - {}, perimeter - {})";
};