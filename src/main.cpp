#include <iostream>
#include <vector>
#include "figure.h"
#include "hexagon.h"
#include "octagon.h"
#include "triangle.h"

int main() {
    std::vector<Figure*> figures;

    // Пример ввода фигур
    figures.push_back(new Hexagon(1.0));
    figures.push_back(new Octagon(1.0));
    figures.push_back(new Triangle(1.0));

    // Вывод геометрического центра и площади для каждой фигуры
    for (const auto& figure : figures) {
        std::cout << "Geometric center: " << figure->getGeometricCenter().first << ", " << figure->getGeometricCenter().second << std::endl;
        std::cout << "Area: " << static_cast<double>(*figure) << std::endl;
    }

    // Вычисление общей площади фигур
    double totalArea = 0.0;
    for (const auto& figure : figures) {
        totalArea += static_cast<double>(*figure);
    }
    std::cout << "Total area: " << totalArea << std::endl;

    // Очистка памяти
    for (auto& figure : figures) {
        delete figure;
    }

    return 0;
}
