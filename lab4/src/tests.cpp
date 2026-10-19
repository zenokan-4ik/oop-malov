#define CATCH_CONFIG_MAIN
#include "../catch.hpp"

#include "../headers/CPoint.hpp"
#include "../headers/CCircle.hpp"
#include "../headers/CLineSegment.hpp"
#include "../headers/CRectangle.hpp"
#include "../headers/CTriangle.hpp"
#include "../headers/CParser.hpp"
#include "../headers/IShape.hpp"

#include <vector>
#include <memory>
#include <string>

TEST_CASE("CPoint: Расстояние между точками", "[CPoint]")
{
    CPoint p1(0.0, 0.0);
    CPoint p2(3.0, 4.0);
    
    REQUIRE(p1.GetDistance(p2) == Approx(5.0));
    REQUIRE(p2.GetDistance(p1) == Approx(5.0));
}

TEST_CASE("CPoint: ToString", "[CPoint]")
{
    CPoint p(1.5, -2.5);
    REQUIRE(p.ToString().find("1.5") != std::string::npos);
    REQUIRE(p.ToString().find("-2.5") != std::string::npos);
}

TEST_CASE("CCircle: Конструктор, геттеры и методы", "[CCircle]")
{
    CPoint center(1.0, 2.0);
    CCircle circle(0xFF0000, 0x00FF00, center, 5.0);
    
    REQUIRE(circle.GetRadius() == Approx(5.0));
    REQUIRE(circle.GetCenter().x == Approx(1.0));
    REQUIRE(circle.GetCenter().y == Approx(2.0));
    
    REQUIRE(circle.GetArea() == Approx(78.5));
    REQUIRE(circle.GetPerimeter() == Approx(31.4));
}

TEST_CASE("CLineSegment: Конструктор, геттеры и методы", "[CLineSegment]")
{
    CPoint start(0.0, 0.0);
    CPoint end(3.0, 4.0);
    
    CLineSegment segment(0xFF0000, start, end);
    
    REQUIRE(segment.GetStartPoint().x == Approx(0.0));
    REQUIRE(segment.GetEndPoint().y == Approx(4.0));
    
    REQUIRE(segment.GetArea() == Approx(0.0));
    REQUIRE(segment.GetPerimeter() == Approx(5.0));
}

TEST_CASE("CRectangle: Конструктор, геттеры и методы", "[CRectangle]")
{
    CPoint leftTop(0.0, 0.0);
    CPoint rightBottom(4.0, 3.0);
    
    CRectangle rect(0xFF0000, 0x00FF00, leftTop, rightBottom, 3.0, 4.0);
    
    REQUIRE(rect.GetWidth() == Approx(4.0));
    REQUIRE(rect.GetHeight() == Approx(3.0));
    REQUIRE(rect.GetLeftTop().x == Approx(0.0));
    REQUIRE(rect.GetRightBottom().y == Approx(3.0));
    
    REQUIRE(rect.GetArea() == Approx(12.0));
    REQUIRE(rect.GetPerimeter() == Approx(14.0));
}

TEST_CASE("CTriangle: Конструктор, геттеры и методы", "[CTriangle]")
{
    CPoint v1(0.0, 0.0);
    CPoint v2(4.0, 0.0);
    CPoint v3(0.0, 3.0);
    
    CTriangle triangle(0xFF0000, 0x00FF00, v1, v2, v3);
    
    REQUIRE(triangle.GetVertex1().x == Approx(0.0));
    REQUIRE(triangle.GetVertex2().x == Approx(4.0));
    REQUIRE(triangle.GetVertex3().y == Approx(3.0));
    
    REQUIRE(triangle.GetArea() == Approx(6.0));
    REQUIRE(triangle.GetPerimeter() == Approx(12.0));
}

TEST_CASE("CParser: Корректный парсинг фигур", "[CParser]")
{
    std::vector<std::unique_ptr<IShape>> shapes;
    CParser parser;
    
    parser.Parse("circle 0xff0000 0x00ff00 1.0 2.0 5.0", shapes);
    REQUIRE(shapes.size() == 1);
    
    CCircle* circle = dynamic_cast<CCircle*>(shapes[0].get());
    REQUIRE(circle != nullptr);
    REQUIRE(circle->GetRadius() == Approx(5.0));
    REQUIRE(circle->GetCenter().x == Approx(1.0));

    parser.Parse("rectangle 0x000000 0xffffff 0 0 4 3", shapes);
    REQUIRE(shapes.size() == 2);
    
    CRectangle* rect = dynamic_cast<CRectangle*>(shapes[1].get());
    REQUIRE(rect != nullptr);
    REQUIRE(rect->GetWidth() == Approx(4.0));
    REQUIRE(rect->GetHeight() == Approx(3.0));

    parser.Parse("triangle 0x123456 0x654321 0 0 4 0 0 3", shapes);
    REQUIRE(shapes.size() == 3);
    
    CTriangle* triangle = dynamic_cast<CTriangle*>(shapes[2].get());
    REQUIRE(triangle != nullptr);
    REQUIRE(triangle->GetArea() == Approx(6.0));

    parser.Parse("line_segment 0xff0000 0 0 3 4", shapes);
    REQUIRE(shapes.size() == 4);
    
    CLineSegment* segment = dynamic_cast<CLineSegment*>(shapes[3].get());
    REQUIRE(segment != nullptr);
    REQUIRE(segment->GetPerimeter() == Approx(5.0));
}

TEST_CASE("CParser: Игнорирование пустых или некорректных строк", "[CParser]")
{
    std::vector<std::unique_ptr<IShape>> shapes;
    CParser parser;
    
    parser.Parse("", shapes);
    parser.Parse("   ", shapes);
    parser.Parse("unknown_shape 1 2 3", shapes);
    
    REQUIRE(shapes.empty() == true);
}