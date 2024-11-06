#include "octagon.h"
#include <cmath>

// Конструктор восьмиугольника
Octagon::Octagon(double sideLength) : sideLength(sideLength) {}

// Вычисление геометрического центра восьмиугольника
std::pair<double, double> Octagon::getGeometricCenter() const {
    return {0.0, 0.0}; // Геометрический центр восьмиугольника - центр
}

// Вывод информации о восьмиугольнике
void Octagon::print(std::ostream& os) const {
    os << "Octagon with side length: " << sideLength;
}

// Чтение данных восьмиугольника из потока
void Octagon::read(std::istream& is) {
    is >> sideLength;
}

// Вычисление площади восьмиугольника
Octagon::operator double() const {
    return 2 * (1 + std::sqrt(2)) * std::pow(sideLength, 2);
}
