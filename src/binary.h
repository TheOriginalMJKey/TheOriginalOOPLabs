#ifndef BINARY_H
#define BINARY_H

#include <iostream>
#include <initializer_list>
#include <stdexcept>

class Binary {
public:
    // Конструктор, инициализирующий двоичное число заданной длины и значением
    Binary(const size_t & n, unsigned char t = 0);

    // Конструктор, инициализирующий двоичное число из initializer_list
    Binary(const std::initializer_list<unsigned char> &t);

    // Конструктор копирования
    Binary(const Binary& other);

    // Конструктор перемещения
    Binary(Binary&& other) noexcept;

    // Деструктор
    ~Binary() noexcept;

    // Оператор присваивания копированием
    Binary& operator=(const Binary& other);

    // Оператор присваивания перемещением
    Binary& operator=(Binary&& other) noexcept;

    // Оператор сложения
    Binary operator+(const Binary& other) const;

    // Оператор вычитания
    Binary operator-(const Binary& other) const;

    // Оператор сравнения на равенство
    bool operator==(const Binary& other) const;

    // Оператор сравнения на неравенство
    bool operator!=(const Binary& other) const;

    // Оператор сравнения на меньше
    bool operator<(const Binary& other) const;

    // Оператор сравнения на больше
    bool operator>(const Binary& other) const;

    // Оператор сравнения на меньше или равно
    bool operator<=(const Binary& other) const;

    // Оператор сравнения на больше или равно
    bool operator>=(const Binary& other) const;

    // Оператор вывода в поток
    friend std::ostream& operator<<(std::ostream& os, const Binary& b);

private:
    unsigned char* data; // Массив для хранения двоичного числа
    size_t size; // Размер массива

    // Вспомогательная функция для копирования данных
    void copy(const Binary& other);

    // Вспомогательная функция для перемещения данных
    void move(Binary&& other) noexcept;
};

#endif // BINARY_H
