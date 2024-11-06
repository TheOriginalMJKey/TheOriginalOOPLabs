#include "binary.h"

// Конструктор, инициализирующий двоичное число заданной длины и значением
Binary::Binary(const size_t & n, unsigned char t) : size(n) {
    if (n == 0) {
        throw std::invalid_argument("Size must be greater than 0");
    }
    data = new unsigned char[n];
    for (size_t i = 0; i < n; ++i) {
        data[i] = t;
    }
}

// Конструктор, инициализирующий двоичное число из initializer_list
Binary::Binary(const std::initializer_list<unsigned char> &t) : size(t.size()) {
    data = new unsigned char[size];
    size_t i = 0;
    for (auto it = t.begin(); it != t.end(); ++it, ++i) {
        if (*it != 0 && *it != 1) {
            throw std::invalid_argument("Binary digits must be 0 or 1");
        }
        data[i] = *it;
    }
}

// Конструктор копирования
Binary::Binary(const Binary& other) {
    copy(other);
}

// Конструктор перемещения
Binary::Binary(Binary&& other) noexcept {
    move(std::move(other));
}

// Деструктор
Binary::~Binary() noexcept {
    delete[] data;
}

// Оператор присваивания копированием
Binary& Binary::operator=(const Binary& other) {
    if (this != &other) {
        delete[] data;
        copy(other);
    }
    return *this;
}

// Оператор присваивания перемещением
Binary& Binary::operator=(Binary&& other) noexcept {
    if (this != &other) {
        delete[] data;
        move(std::move(other));
    }
    return *this;
}

// Оператор сложения
Binary Binary::operator+(const Binary& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Binary numbers must have the same size");
    }
    Binary result(size);
    unsigned char carry = 0;
    for (size_t i = 0; i < size; ++i) {
        unsigned char sum = data[i] + other.data[i] + carry;
        result.data[i] = sum % 2;
        carry = sum / 2;
    }
    return result;
}

// Оператор вычитания
Binary Binary::operator-(const Binary& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Binary numbers must have the same size");
    }
    Binary result(size);
    unsigned char borrow = 0;
    for (size_t i = 0; i < size; ++i) {
        int diff = data[i] - other.data[i] - borrow;
        if (diff < 0) {
            diff += 2;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.data[i] = diff;
    }
    return result;
}

// Оператор сравнения на равенство
bool Binary::operator==(const Binary& other) const {
    if (size != other.size) {
        return false;
    }
    for (size_t i = 0; i < size; ++i) {
        if (data[i] != other.data[i]) {
            return false;
        }
    }
    return true;
}

// Оператор сравнения на неравенство
bool Binary::operator!=(const Binary& other) const {
    return !(*this == other);
}

// Оператор сравнения на меньше
bool Binary::operator<(const Binary& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Binary numbers must have the same size");
    }
    for (size_t i = size; i > 0; --i) {
        if (data[i - 1] < other.data[i - 1]) {
            return true;
        } else if (data[i - 1] > other.data[i - 1]) {
            return false;
        }
    }
    return false;
}

// Оператор сравнения на больше
bool Binary::operator>(const Binary& other) const {
    return other < *this;
}

// Оператор сравнения на меньше или равно
bool Binary::operator<=(const Binary& other) const {
    return !(*this > other);
}

// Оператор сравнения на больше или равно
bool Binary::operator>=(const Binary& other) const {
    return !(*this < other);
}

// Оператор вывода в поток
std::ostream& operator<<(std::ostream& os, const Binary& b) {
    for (size_t i = b.size; i > 0; --i) {
        os << static_cast<int>(b.data[i - 1]);
    }
    return os;
}

// Вспомогательная функция для копирования данных
void Binary::copy(const Binary& other) {
    size = other.size;
    data = new unsigned char[size];
    for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

// Вспомогательная функция для перемещения данных
void Binary::move(Binary&& other) noexcept {
    size = other.size;
    data = other.data;
    other.size = 0;
    other.data = nullptr;
}
