#include "CVector3D.h"

const double EPSILON = 1e-9;

CVector3D::CVector3D() : x(0.0), y(0.0), z(0.0) {}

CVector3D::CVector3D(double x0, double y0, double z0) : x(x0), y(y0), z(z0) {}

double CVector3D::GetLength() const
{
    return std::sqrt(x * x + y * y + z * z);
}

void CVector3D::Normalize()
{
    double len = GetLength();
    if (len > EPSILON)
    {
        x /= len;
        y /= len;
        z /= len;
    }
}

// 1. Унарные
CVector3D CVector3D::operator+() const
{
    return *this;
}

CVector3D CVector3D::operator-() const
{
    return CVector3D(-x, -y, -z);
}

// 2, 3. Бинарные
CVector3D CVector3D::operator+(const CVector3D& other) const
{
    return CVector3D(x + other.x, y + other.y, z + other.z);
}

CVector3D CVector3D::operator-(const CVector3D& other) const
{
    return CVector3D(x - other.x, y - other.y, z - other.z);
}

// 4, 5. С присваиванием
CVector3D& CVector3D::operator+=(const CVector3D& other)
{
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

CVector3D& CVector3D::operator-=(const CVector3D& other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

// 6, 7. Умножение и деление на скаляр
CVector3D CVector3D::operator*(double scalar) const
{
    return CVector3D(x * scalar, y * scalar, z * scalar);
}

CVector3D CVector3D::operator/(double scalar) const
{
    return CVector3D(x / scalar, y / scalar, z / scalar);
}

// 8, 9. С присваиванием
CVector3D& CVector3D::operator*=(double scalar)
{
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
}

CVector3D& CVector3D::operator/=(double scalar)
{
    x /= scalar;
    y /= scalar;
    z /= scalar;
    return *this;
}

// 10. Сравнение
bool CVector3D::operator==(const CVector3D& other) const
{
    return std::abs(x - other.x) <= EPSILON &&
           std::abs(y - other.y) <= EPSILON &&
           std::abs(z - other.z) <= EPSILON;
}

bool CVector3D::operator!=(const CVector3D& other) const
{
    return !(*this == other);
}

// 11. Вывод в формате: x, y, z
std::ostream& operator<<(std::ostream& os, const CVector3D& v)
{
    os << v.x << ", " << v.y << ", " << v.z;
    return os;
}

// 12. Ввод в формате: x, y, z
std::istream& operator>>(std::istream& is, CVector3D& v)
{
    char comma1, comma2;
    is >> v.x >> comma1 >> v.y >> comma2 >> v.z;
    return is;
}

// 13, 14, 15. Свободные функции
double DotProduct(const CVector3D& v1, const CVector3D& v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

CVector3D CrossProduct(const CVector3D& v1, const CVector3D& v2)
{
    return CVector3D(
        v1.y * v2.z - v1.z * v2.y,
        v1.z * v2.x - v1.x * v2.z,
        v1.x * v2.y - v1.y * v2.x
    );
}

CVector3D Normalize(const CVector3D& v)
{
    CVector3D result = v;
    result.Normalize();
    return result;
}

// 6 (доп). Умножение скаляра на вектор
CVector3D operator*(double scalar, const CVector3D& v)
{
    return v * scalar;
}