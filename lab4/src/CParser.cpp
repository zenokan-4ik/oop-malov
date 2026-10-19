#include "../headers/CParser.hpp"

#include "../headers/CCircle.hpp"
#include "../headers/CLineSegment.hpp"
#include "../headers/CRectangle.hpp"
#include "../headers/CTriangle.hpp"

#include "../headers/IShape.hpp"
#include <vector>
#include <sstream>
#include <memory>
#include <iostream>
#include <cmath>
#include <string>

void CParser::Parse(std::string line, std::vector<std::unique_ptr<IShape>>& shapes)
{
    std::stringstream ss(line);
    std::string shapeType;
    
    if (!(ss >> shapeType))
    {
        return;
    }
    
    if (shapeType == "circle")
    {
        shapes.push_back(std::make_unique<CCircle>(ParseCircle(ss)));
    }
    else if (shapeType == "line_segment")
    {
        shapes.push_back(std::make_unique<CLineSegment>(ParseLineSegment(ss)));
    }
    else if (shapeType == "rectangle")
    {
        shapes.push_back(std::make_unique<CRectangle>(ParseRectangle(ss)));
    }
    else if (shapeType == "triangle")
    {
        shapes.push_back(std::make_unique<CTriangle>(ParseTriangle(ss)));
    }
}

CCircle CParser::ParseCircle(std::stringstream& ss)
{
    uint32_t outlineColor, fillColor;
    double cx, cy, radius;
    
    ss >> std::hex >> outlineColor >> fillColor >> std::dec >> cx >> cy >> radius;
    
    return CCircle(outlineColor, fillColor, CPoint(cx, cy), radius);
}

CLineSegment CParser::ParseLineSegment(std::stringstream& ss)
{
    uint32_t outlineColor;
    double x1, y1, x2, y2;
    
    ss >> std::hex >> outlineColor >> std::dec >> x1 >> y1 >> x2 >> y2;
    return CLineSegment(outlineColor, CPoint(x1, y1), CPoint(x2, y2));
}

CRectangle CParser::ParseRectangle(std::stringstream& ss)
{
    uint32_t outlineColor, fillColor;
    double left, top, right, bottom;
    
    ss >> std::hex >> outlineColor >> fillColor >> std::dec >> left >> top >> right >> bottom;
    
    CPoint leftTop(left, top);
    CPoint rightBottom(right, bottom);
    
    double width = std::abs(right - left);
    double height = std::abs(bottom - top);
    
    return CRectangle(outlineColor, fillColor, leftTop, rightBottom, height, width);
}

CTriangle CParser::ParseTriangle(std::stringstream& ss)
{
    uint32_t outlineColor, fillColor;
    double x1, y1, x2, y2, x3, y3;
    
    ss >> std::hex >> outlineColor >> fillColor >> std::dec >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    
    return CTriangle(outlineColor, fillColor, CPoint(x1, y1), CPoint(x2, y2), CPoint(x3, y3));
}