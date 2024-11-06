#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figure.h"

template <typename T>
class Triangle : public Figure<T> {
public:
    Triangle(T sideLength);

    std::pair<T, T> getGeometricCenter() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    operator double() const override;

private:
    T sideLength;
};

#endif // TRIANGLE_H
