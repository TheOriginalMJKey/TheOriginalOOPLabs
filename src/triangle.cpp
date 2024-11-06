#include "triangle.h"
#include <cmath>

template <typename T>
Triangle<T>::Triangle(T sideLength) : sideLength(sideLength) {}

template <typename T>
std::pair<T, T> Triangle<T>::getGeometricCenter() const {
    return {0, sideLength / 3}; // Геометрический центр треугольника - центр высоты
}

template <typename T>
void Triangle<T>::print(std::ostream& os) const {
    os << "Triangle with side length: " << sideLength;
}

template <typename T>
void Triangle<T>::read(std::istream& is) {
    is >> sideLength;
}

template <typename T>
Triangle<T>::operator double() const {
    return (std::sqrt(3) / 4) * std::pow(sideLength, 2);
}

template class Triangle<int>;
template class Triangle<double>;
