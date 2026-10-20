#pragma once

class CConst
{
public:
    static constexpr double PI = 3.14;
    static constexpr auto CIRCLE_FORMAT = "Circle (center - {}, radius - {}, area - {}, perimeter - {}, outline - {:X}, fill - {:X})";
    static constexpr auto LINE_FORMAT = "Line (start - {}, end - {}, length - {}, outline - {:X}";
    static constexpr auto RECTANGLE_FORMAT = "Rectangle (heigth - {}, width - {}, area - {}, perimeter - {}, outline - {:X}, fill - {:X})";
    static constexpr auto TRIANGLE_FORMAT = "Triangle (vertex1 - {}, vertex2 - {}, vertex3 - {}, area - {}, perimeter - {}, outline - {:X}, fill - {:X})";
    static constexpr auto POINT_FORMAT = "({}, {})";
};