#ifndef OCTAGON_H
#define OCTAGON_H

#include "figure.h"

template <typename T>
class Octagon : public Figure<T> {
public:
    Octagon(T sideLength);

    std::pair<T, T> getGeometricCenter() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    operator double() const override;

private:
    T sideLength;
};

#endif // OCTAGON_H
