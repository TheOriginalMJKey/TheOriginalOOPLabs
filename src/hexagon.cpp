#include "hexagon.h"
#include <cmath>

// Конструктор шестиугольника
Hexagon::Hexagon(double sideLength) : sideLength(sideLength) {}

// Вычисление геометрического центра шестиугольника
std::pair<double, double> Hexagon::getGeometricCenter() const {
    return {0.0, 0.0}; // Геометрический центр шестиугольника - центр
}

// Вывод информации о шестиугольнике
void Hexagon::print(std::ostream& os) const {
    os << "Hexagon with side length: " << sideLength;
}

// Чтение данных шестиугольника из потока
void Hexagon::read(std::istream& is) {
    is >> sideLength;
}

// Вычисление площади шестиугольника
Hexagon::operator double() const {
    return (3 * std::sqrt(3) / 2) * std::pow(sideLength, 2);
}
