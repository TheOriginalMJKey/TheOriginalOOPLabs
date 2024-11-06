#ifndef ARRAY_H
#define ARRAY_H

#include <memory>
#include <stdexcept>
#include <iostream>

template <typename T>
class Array {
public:
    Array(size_t size) : size(size), data(new T[size]) {}

    ~Array() {
        delete[] data;
    }

    Array(const Array& other) : size(other.size), data(new T[other.size]) {
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    Array(Array&& other) noexcept : size(other.size), data(other.data) {
        other.size = 0;
        other.data = nullptr;
    }

    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new T[size];
            for (size_t i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    Array& operator=(Array&& other) noexcept {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = other.data;
            other.size = 0;
            other.data = nullptr;
        }
        return *this;
    }

    T& operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    const T& operator[](size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    size_t getSize() const {
        return size;
    }

    void resize(size_t newSize) {
        T* newData = new T[newSize];
        size_t copySize = std::min(size, newSize);
        for (size_t i = 0; i < copySize; ++i) {
            newData[i] = std::move(data[i]);
        }
        delete[] data;
        data = newData;
        size = newSize;
    }

private:
    size_t size;
    T* data;
};

#endif // ARRAY_H
