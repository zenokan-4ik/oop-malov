#pragma once

#include <iostream>
#include <cmath>

class CVector3D
{
public:
    double x, y, z;

    // Конструкторы
    CVector3D();
    CVector3D(double x0, double y0, double z0);

    // Методы
    double GetLength() const;
    void Normalize();

    // 1. Унарные операторы
    CVector3D operator+() const;
    CVector3D operator-() const;

    // 2, 3. Бинарные операторы
    CVector3D operator+(const CVector3D& other) const;
    CVector3D operator-(const CVector3D& other) const;

    // 4, 5. Операторы с присваиванием
    CVector3D& operator+=(const CVector3D& other);
    CVector3D& operator-=(const CVector3D& other);

    // 6, 7. Умножение и деление на число (скаляр)
    CVector3D operator*(double scalar) const;
    CVector3D operator/(double scalar) const;

    // 8, 9. Умножение и деление с присваиванием
    CVector3D& operator*=(double scalar);
    CVector3D& operator/=(double scalar);

    // 10. Сравнение
    bool operator==(const CVector3D& other) const;
    bool operator!=(const CVector3D& other) const;

    // 11, 12. Ввод и вывод
    friend std::ostream& operator<<(std::ostream& os, const CVector3D& v);
    friend std::istream& operator>>(std::istream& is, CVector3D& v);
};

// 13, 14, 15. Свободные функции
double DotProduct(const CVector3D& v1, const CVector3D& v2);
CVector3D CrossProduct(const CVector3D& v1, const CVector3D& v2);
CVector3D Normalize(const CVector3D& v);

// 6 (доп). Умножение числа на вектор
CVector3D operator*(double scalar, const CVector3D& v);