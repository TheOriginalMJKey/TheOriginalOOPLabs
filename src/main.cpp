#include <iostream>
#include "fixed_block_memory_resource.h"
#include "custom_container.h"

struct ComplexType {
    int a;
    double b;
};

int main() {
    FixedBlockMemoryResource memoryResource(1024);
    CustomContainer<int> intContainer(&memoryResource);
    CustomContainer<ComplexType> complexContainer(&memoryResource);

    intContainer.push_back(1);
    intContainer.push_back(2);
    intContainer.push_back(3);

    complexContainer.push_back({1, 2.0});
    complexContainer.push_back({2, 3.0});
    complexContainer.push_back({3, 4.0});

    std::cout << "Int Container: ";
    for (const auto& value : intContainer) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    std::cout << "Complex Container: ";
    for (const auto& value : complexContainer) {
        std::cout << "{" << value.a << ", " << value.b << "} ";
    }
    std::cout << std::endl;

    return 0;
}
