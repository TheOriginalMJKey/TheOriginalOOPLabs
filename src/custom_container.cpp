#include "custom_container.h"
#include "complex_type.h" 

template <typename T>
CustomContainer<T>::CustomContainer(std::pmr::memory_resource* resource)
    : data(allocator_type(resource)) {}

template <typename T>
typename CustomContainer<T>::iterator CustomContainer<T>::begin() {
    return data.begin();
}

template <typename T>
typename CustomContainer<T>::iterator CustomContainer<T>::end() {
    return data.end();
}

template <typename T>
typename CustomContainer<T>::const_iterator CustomContainer<T>::begin() const {
    return data.begin();
}

template <typename T>
typename CustomContainer<T>::const_iterator CustomContainer<T>::end() const {
    return data.end();
}

template <typename T>
void CustomContainer<T>::push_back(const T& value) {
    data.push_back(value);
}

template <typename T>
void CustomContainer<T>::push_back(T&& value) {
    data.push_back(std::move(value));
}

template <typename T>
void CustomContainer<T>::pop_back() {
    data.pop_back();
}

template <typename T>
typename CustomContainer<T>::size_type CustomContainer<T>::size() const {
    return data.size();
}

template <typename T>
bool CustomContainer<T>::empty() const {
    return data.empty();
}

template class CustomContainer<int>;
template class CustomContainer<double>;
template class CustomContainer<ComplexType>;
