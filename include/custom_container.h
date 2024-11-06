#ifndef CUSTOM_CONTAINER_H
#define CUSTOM_CONTAINER_H

#include <memory>
#include <memory_resource>
#include <iterator>
#include <list>

template <typename T>
class CustomContainer {
public:
    using value_type = T;
    using allocator_type = std::pmr::polymorphic_allocator<T>;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = value_type*;
    using const_pointer = const value_type*;
    using iterator = typename std::list<T, allocator_type>::iterator;
    using const_iterator = typename std::list<T, allocator_type>::const_iterator;

    explicit CustomContainer(std::pmr::memory_resource* resource = std::pmr::get_default_resource());

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;

    void push_back(const T& value);
    void push_back(T&& value);
    void pop_back();

    size_type size() const;
    bool empty() const;

private:
    std::list<T, allocator_type> data;
};

#endif // CUSTOM_CONTAINER_H
