#include <iostream>
#include <vector>
#include "figure.h"
#include "hexagon.h"
#include "octagon.h"
#include "triangle.h"

int main() {
    std::vector<Figure*> figures;

    // Пример ввода фигур
    Hexagon hexagon(1.0);
    Octagon octagon(1.0);
    Triangle triangle(1.0);

    figures.push_back(new Hexagon(hexagon));
    figures.push_back(new Octagon(octagon));
    figures.push_back(new Triangle(triangle));

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

    // Удаление фигуры по индексу
    delete figures[1];
    figures.erase(figures.begin() + 1);

    // Очистка памяти
    for (auto& figure : figures) {
        delete figure;
    }

    return 0;
}
