#pragma once

#include "../headers/CCircle.hpp"
#include "../headers/CLineSegment.hpp"
#include "../headers/CRectangle.hpp"
#include "../headers/CTriangle.hpp"
#include "../headers/IShape.hpp"
#include <vector>
#include <memory>
#include <sstream>

class CParser
{
public:
    CParser() {};
    void Parse(std::string line, std::vector<std::unique_ptr<IShape>>& shapes);
private:
    CCircle ParseCircle(std::stringstream& ss);
    CLineSegment ParseLineSegment(std::stringstream& ss);
    CRectangle ParseRectangle(std::stringstream& ss);
    CTriangle ParseTriangle(std::stringstream& ss);
};