//
// Created by yuri on 26.04.19.
//

#ifndef UNTITLED_SORT_H
#define UNTITLED_SORT_H

#include <array>
#include <vector>

#include <cmath>

#include "Comparable.h"
#include "sort_impl.h"


namespace ABC {
    /**
     * @brief Sort %vector in direction defined by %comparator.
     * @tparam T  - type.
     * @param vector - vector to sort.
     * @param begin  - begin of sorting
     * @param end  - end of sorting.
     * @param comparator  - defines direction of sorting.
     */
    template<typename T>
    void sort(std::vector<T> &vector, std::size_t begin, std::size_t end, Comparable<T> *comparator) {
        if (begin < end) {
            auto q = (std::size_t) trunc((begin + end) / 2.0);
            sort(vector, begin, q, comparator);
            sort(vector, q + 1, end, comparator);
            merge(vector, begin, q, end, comparator);
        }
    }

    /**
     * @brief Sort %vector in increased direction.
     *
     * @tparam T  type.
     * @param vector vector to sort.
     * @param begin  begin of sorting
     * @param end  nd of sorting.
     */
    template<typename T>
    void sort(std::vector<T> &vector, std::size_t begin, std::size_t end) {
        if (begin < end) {
            auto q = (std::size_t) trunc((begin + end) / 2.0);
            sort(vector, begin, q);
            sort(vector, q + 1, end);
            merge(vector, begin, q, end);
        }
    }

    /**
 * @brief Sort array<T> in increase direction.
 *
 * @tparam size - size of array
 * @tparam T - typename
 * @param a - array<T>.
 * @param p  - start position of sorting. [1..length(a)].
 * @param r - end position of sorting. [1..length(a)].
 *
 * Uses internal buffer.
 */
    template<std::size_t size, typename T>
    void sort(std::array<T, size> &a, std::size_t p, std::size_t r) {
        if (p < r) {
            int q = (int) trunc((p + r) / 2.0);
            sort(a, p, q);
            sort(a, q + 1, r);
            merge(a, p, q, r);
        }
    }

/**
 * Sort array<T> in increase direction.
 * uses external buffer.
 *
 * @tparam size - size of array
 * @tparam T - typename
 * @param a - array<T>.
 * @param p  - start position of sorting. [1..length(a)].
 * @param r - end position of sorting. [1..length(a)].
 */
    template<std::size_t size, typename T>
    void sort(std::array<T, size> &a, std::array<T, size> &buffer, std::size_t p, std::size_t r) {
        if (p < r) {
            int q = (int) trunc((p + r) / 2.0);
            sort(a, buffer, p, q);
            sort(a, buffer, q + 1, r);
            merge(a, buffer, p, q, r);
        }
    }

/**
 * Sort array<T> in direction according <b>comparator</b>.
 * Use internal buffer.
 *
 * @tparam size - size of array
 * @tparam T - typename
 * @param a - array<T>.
 * @param p  - start position of sorting. [1..length(a)].
 * @param r - end position of sorting. [1..length(a)].
 * @param comparator - compare elements of the array
 */
    template<
            std::size_t size,
            typename T
    >
    void sort(std::array<T, size> &a, std::size_t p, std::size_t r, Comparable<T> *comparator) {
        if (p < r) {
            auto q = (std::size_t) trunc((p + r) / 2.0);
            sort(a, p, q, comparator);
            sort(a, q + 1, r, comparator);
            merge(a, p, q, r, comparator);
        }
    }


/**
 * Sort array<T> in increase direction.
 * uses external buffer.
 *
 * @tparam size - size of array
 * @tparam T - typename
 * @param a - array<T>.
 * @param p  - start position of sorting. [1..length(a)].
 * @param r - end position of sorting. [1..length(a)].
 */
    template<std::size_t size, typename T>
    void
    sort(std::array<T, size> &a, std::array<T, size> &buffer, std::size_t p, std::size_t r, Comparable<T> *comparator) {
        if (p < r) {
            int q = (int) trunc((p + r) / 2.0);
            sort(a, buffer, p, q, comparator);
            sort(a, buffer, q + 1, r, comparator);
            merge(a, buffer, p, q, r, comparator);
        }
    }
}

#endif //UNTITLED_SORT_H
