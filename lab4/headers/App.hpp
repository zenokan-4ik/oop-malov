#pragma once

#include <vector>
#include <memory>
#include "./IShape.hpp"

class App
{
public:
    static void Run();
    static IShape* GetMaxArea(std::vector<std::unique_ptr<IShape>>& shapes);
    static IShape* GetMaxPerimeter(std::vector<std::unique_ptr<IShape>>& shapes);
};