#include "hexagon.h"
#include <cmath>

template <typename T>
Hexagon<T>::Hexagon(T sideLength) : sideLength(sideLength) {}

template <typename T>
std::pair<T, T> Hexagon<T>::getGeometricCenter() const {
    return {0, 0}; // Геометрический центр шестиугольника - центр
}

template <typename T>
void Hexagon<T>::print(std::ostream& os) const {
    os << "Hexagon with side length: " << sideLength;
}

template <typename T>
void Hexagon<T>::read(std::istream& is) {
    is >> sideLength;
}

template <typename T>
Hexagon<T>::operator double() const {
    return (3 * std::sqrt(3) / 2) * std::pow(sideLength, 2);
}

template class Hexagon<int>;
template class Hexagon<double>;
