#include "octagon.h"
#include <cmath>

template <typename T>
Octagon<T>::Octagon(T sideLength) : sideLength(sideLength) {}

template <typename T>
std::pair<T, T> Octagon<T>::getGeometricCenter() const {
    return {0, 0}; // Геометрический центр восьмиугольника - центр
}

template <typename T>
void Octagon<T>::print(std::ostream& os) const {
    os << "Octagon with side length: " << sideLength;
}

template <typename T>
void Octagon<T>::read(std::istream& is) {
    is >> sideLength;
}

template <typename T>
Octagon<T>::operator double() const {
    return 2 * (1 + std::sqrt(2)) * std::pow(sideLength, 2);
}

template class Octagon<int>;
template class Octagon<double>;
