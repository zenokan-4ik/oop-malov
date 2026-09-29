#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "CVector3D.h"
#include <sstream>

// TODO: Separate: each test_case for each operator

TEST_CASE("Конструкторы и длина", "[CVector3D]")
{
    CVector3D v1;
    REQUIRE(v1.x == Approx(0.0));
    REQUIRE(v1.GetLength() == Approx(0.0));

    CVector3D v2(3.0, 4.0, 0.0);
    REQUIRE(v2.GetLength() == Approx(5.0));
}

TEST_CASE("Нормализация", "[CVector3D]")
{
    CVector3D v(3.0, 4.0, 0.0);
    v.Normalize();
    REQUIRE(v.GetLength() == Approx(1.0));
    REQUIRE(v.x == Approx(0.6));
    
    CVector3D v2(0, 3, 4);
    CVector3D v3 = Normalize(v2);
    REQUIRE(v3.GetLength() == Approx(1.0));
}

TEST_CASE("Унарные и бинарные + и -", "[CVector3D]")
{
    CVector3D v1(1, 2, 3);
    CVector3D v2(4, 5, 6);
    
    REQUIRE((-v1).x == Approx(-1.0));
    REQUIRE((+v1).x == Approx(1.0));
    REQUIRE((v1 + v2) == CVector3D(5, 7, 9));
    REQUIRE((v2 - v1) == CVector3D(3, 3, 3));
}

TEST_CASE("Операторы += и -=", "[CVector3D]")
{
    CVector3D v1(1, 1, 1);
    CVector3D v2(2, 2, 2);
    v1 += v2;
    REQUIRE(v1 == CVector3D(3, 3, 3));
    v1 -= v2;
    REQUIRE(v1 == CVector3D(1, 1, 1));
}

TEST_CASE("Умножение и деление на скаляр", "[CVector3D]")
{
    CVector3D v(2, 4, 6);
    REQUIRE((v * 2.0) == CVector3D(4, 8, 12));
    REQUIRE((2.0 * v) == CVector3D(4, 8, 12));
    REQUIRE((v / 2.0) == CVector3D(1, 2, 3));

    v *= 3.0;
    REQUIRE(v == CVector3D(6, 12, 18));
    v /= 6.0;
    REQUIRE(v == CVector3D(1, 2, 3));
}

TEST_CASE("Сравнение == и !=", "[CVector3D]")
{
    CVector3D v1(1.0, 2.0, 3.0);
    CVector3D v2(1.0 + 1e-10, 2.0, 3.0);
    REQUIRE(v1 == v2);
    
    CVector3D v3(1.0, 2.0, 4.0);
    REQUIRE(v1 != v3);
}

TEST_CASE("Ввод и вывод (<< и >>)", "[CVector3D]")
{
    CVector3D v(3.0, -2.5, 7.0);
    std::ostringstream oss;
    oss << v;
    REQUIRE(oss.str() == "3, -2.5, 7");

    std::istringstream iss("1.5, 2.5, 3.5");
    CVector3D v2;
    iss >> v2;
    REQUIRE(v2 == CVector3D(1.5, 2.5, 3.5));
}

TEST_CASE("Скалярное и векторное произведение", "[CVector3D]")
{
    CVector3D v1(1, 0, 0);
    CVector3D v2(0, 1, 0);
    
    REQUIRE(DotProduct(v1, v2) == Approx(0.0));
    
    CVector3D cross = CrossProduct(v1, v2);
    REQUIRE(cross == CVector3D(0, 0, 1));
}