//
// Created by yuri on 29.04.19.
//

#ifndef SORT_SORT_INNER_H
#define SORT_SORT_INNER_H

#include <array>
#include <vector>


#include "Comparable.h"

namespace ABC {
/* Declarations: */
    template<std::size_t size, typename T>
    void merge(std::array<T, size> &a, std::size_t p, std::size_t q, std::size_t r);

    template<std::size_t size, typename T>
    void
    merge(std::array<T, size> &a, std::array<T, size> &buffer, std::size_t p, std::size_t q, std::size_t r);

    template<
            std::size_t size,
            typename T
    >
    void merge(std::array<T, size> &a, std::size_t p, std::size_t q, std::size_t r, Comparable<T> *comparator);

    template<typename T>
    void merge(std::vector<T, std::allocator<T>> &vector, std::size_t p, std::size_t q, std::size_t r,
               Comparable<T> *comparator);

    template<typename T>
    void merge(std::vector<T, std::allocator<T>> &vector, std::size_t p, std::size_t q, std::size_t r);
}

#endif //SORT_SORT_INNER_H
