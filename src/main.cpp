#include <iostream>
#include "binary.h"

int main() {
    try {
        // Создаем два двоичных числа
        Binary b1(8, 1);
        Binary b2(8, 0);

        // Выводим их на экран
        std::cout << "b1: " << b1 << std::endl;
        std::cout << "b2: " << b2 << std::endl;

        // Сложение двоичных чисел
        Binary b3 = b1 + b2;
        std::cout << "b1 + b2: " << b3 << std::endl;

        // Вычитание двоичных чисел
        Binary b4 = b1 - b2;
        std::cout << "b1 - b2: " << b4 << std::endl;

        // Сравнение двоичных чисел
        if (b1 == b2) {
            std::cout << "b1 == b2" << std::endl;
        } else {
            std::cout << "b1 != b2" << std::endl;
        }

        if (b1 > b2) {
            std::cout << "b1 > b2" << std::endl;
        } else {
            std::cout << "b1 <= b2" << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
