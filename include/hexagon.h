#ifndef HEXAGON_H
#define HEXAGON_H

#include "figure.h"

template <typename T>
class Hexagon : public Figure<T> {
public:
    Hexagon(T sideLength);

    std::pair<T, T> getGeometricCenter() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    operator double() const override;

private:
    T sideLength;
};

#endif // HEXAGON_H
