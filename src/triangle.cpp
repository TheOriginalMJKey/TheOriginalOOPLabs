#include "triangle.h"
#include <cmath>

// Конструктор треугольника
Triangle::Triangle(double sideLength) : sideLength(sideLength) {}

// Вычисление геометрического центра треугольника
std::pair<double, double> Triangle::getGeometricCenter() const {
    return {0.0, sideLength / 3}; // Геометрический центр треугольника - центр высоты
}

// Вывод информации о треугольнике
void Triangle::print(std::ostream& os) const {
    os << "Triangle with side length: " << sideLength;
}

// Чтение данных треугольника из потока
void Triangle::read(std::istream& is) {
    is >> sideLength;
}

// Вычисление площади треугольника
Triangle::operator double() const {
    return (std::sqrt(3) / 4) * std::pow(sideLength, 2);
}
