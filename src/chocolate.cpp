#include "chocolate.h"

int splitChocolate(int n, int m) {
    if (n <= 0 || m <= 0) {
        return 0;
    }
    return n * m - 1;
}