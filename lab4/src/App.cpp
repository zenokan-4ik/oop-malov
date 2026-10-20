#include "../headers/App.hpp"

#include "../headers/IShape.hpp"
#include "../headers/CParser.hpp"
#include <vector>
#include <memory>
#include <string>
#include <iostream>

void App::Run()
{
    std::cout << "=== Shape Parser ===" << std::endl;
    std::cout << "circle <outline_color> <fill_color> <center_x> <center_y> <radius>" << std::endl;
    std::cout << "line_segment <outline_color> <start_x> <start_y> <end_x> <end_y>" << std::endl;
    std::cout << "rectangle <outline_color> <fill_color> <left> <top> <right> <bottom>" << std::endl;
    std::cout << "triangle <outline_color> <fill_color> <x1> <y1> <x2> <y2> <x3> <y3>" << std::endl;
    std::cout << "Type 'exit' to finish input.\n" << std::endl;

    std::vector<std::unique_ptr<IShape>> shapes;
    CParser parser;
    std::string line;

    while (std::getline(std::cin, line))
    {
        if (line == "exit")
        {
            break;
        }
        if (line.empty())
        {
            continue;
        }
        parser.Parse(line, shapes);
    }

    if (shapes.empty())
    {
        std::cout << "No shapes were parsed." << std::endl;
        return;
    }

    IShape* maxAreaShape = GetMaxArea(shapes);
    IShape* minPerimeterShape = GetMaxPerimeter(shapes);

    std::cout << "\n=== Shape with the maximum area ===" << std::endl;
    std::cout << maxAreaShape->ToString() << std::endl;

    std::cout << "\n=== Shape with the minimum perimeter ===" << std::endl;
    std::cout << minPerimeterShape->ToString() << std::endl;
}

IShape* App::GetMaxArea(std::vector<std::unique_ptr<IShape>>& shapes)
{
    IShape* maxAreaShape = nullptr;
    for(const auto& shape : shapes)
    {
        if(!maxAreaShape || shape->GetArea() > maxAreaShape->GetArea())
        {
            maxAreaShape = shape.get();
        }
    }
    return maxAreaShape;
}

IShape* App::GetMaxPerimeter(std::vector<std::unique_ptr<IShape>>& shapes)
{
    IShape* maxPerimeterShape = nullptr;
    for(const auto& shape : shapes)
    {
        if(!maxPerimeterShape || shape->GetArea() > maxPerimeterShape->GetArea())
        {
            maxPerimeterShape = shape.get();
        }
    }
    return maxPerimeterShape;
}