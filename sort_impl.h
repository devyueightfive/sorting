//
// Created by yuri on 26.04.19.
//

#ifndef UNTITLED_SORT_CPP
#define UNTITLED_SORT_CPP

#include <iterator>
#include <cstddef>
#include <cmath>

namespace ABC {

/**
 * Merges two sorted pieces ([start..middle] and [middle+1..end]) to one sorted piece of array.
 * Uses internal buffer for sorting.
 *
 * @tparam size - size of sorted array
 * @tparam T - type
 * @param a - array to sort
 * @param p - the start of sorting
 * @param q - the middle of sorting
 * @param r - the end of sorting
 */
    template<size_t size, typename T>
    void merge(std::array<T, size> &a, std::size_t p, std::size_t q, std::size_t r) {
        //internal buffer for sorting (start..begin)
        std::array<T, size> buffer{};
        std::size_t left_begin, left_end, right_begin, right_end;
        left_begin = p - 1;
        left_end = q - 1;
        right_begin = left_end + 1;
        right_end = r - 1;
        std::size_t i = left_begin, j = right_begin, k = 0;
        //sort to buffer
        while (k < (right_end - left_begin + 1)) {
            if (i <= left_end and j <= right_end) {
                buffer[k] = (a[i] < a[j]) ? a[i++] : a[j++];
            } else if (i > left_end) { buffer[k] = a[j++]; } else if (j > right_end) { buffer[k] = a[i++]; }
            ++k;
        }
        //copy back to a (begin..end)
        for (i = left_begin, k = 0; k < (right_end - left_begin + 1); ++i, ++k) {
            a[i] = buffer[k];
        }
    }

/**
 * Merges two sorted pieces ([start..middle] and [middle+1..end]) to one sorted piece of array.
 * Uses external buffer for sorting.
 *
 * @tparam size - size of sorted array
 * @tparam T - type
 * @param a - array to sort
 * @param p - start
 * @param q - middle
 * @param r - end
 */
    template<std::size_t size, typename T>
    void
    merge(std::array<T, size> &a, std::array<T, size> &buffer, std::size_t p, std::size_t q, std::size_t r) {
        std::size_t left_begin, left_end, right_begin, right_end;
        left_begin = p - 1;
        left_end = q - 1;
        right_begin = left_end + 1;
        right_end = r - 1;
        std::size_t i = left_begin, j = right_begin;
        std::size_t k = left_begin;
        //sort to buffer
        while (k < (right_end - left_begin + 1)) {
            if (i <= left_end and j <= right_end) {
                buffer[k] = (a[i] < a[j]) ? a[i++] : a[j++];
            } else if (i > left_end) { buffer[k] = a[j++]; } else if (j > right_end) { buffer[k] = a[i++]; }
            ++k;
        }

        //copy back to a (begin..end)
        for (i = left_begin, k = left_begin; k < right_end; ++i, ++k) {
            a[i] = buffer[k];
        }
    }

/**
 *  Merges two sorted pieces ([start..middle] and [middle+1..end]) to one sorted piece of array.
 *  Uses internal buffer.
 *  Sorting is performed by comparator.compare() function.
 *
 * @tparam size
 * @tparam T - type
 * @param a - array to sort
 * @param p - start
 * @param q - middle
 * @param r - end
 * @param comparator - compare elements of the array
 */
    template<
            std::size_t size,
            typename T
    >
    void merge(std::array<T, size> &a, std::size_t p, std::size_t q, std::size_t r, Comparable<T> *comparator) {
        //internal buffer for sorting (start..begin)
        std::array<T, size> buffer{};
        //edges of merging
        std::size_t left_begin, left_end, right_begin, right_end;
        left_begin = p - 1;
        left_end = q - 1;
        right_begin = left_end + 1;
        right_end = r - 1;
        int i = left_begin, j = right_begin, k = 0;
        //merge two pieces to buffer
        while (k < (right_end - left_begin + 1)) {
            //merging by sorting
            if (i <= left_end and j <= right_end) {
                //sorting by comparator
                buffer[k] = comparator->compare(a[i], a[j]) ? a[i++] : a[j++];
            } else if (i > left_end) { buffer[k] = a[j++]; } else if (j > right_end) { buffer[k] = a[i++]; }
            ++k;
        }
        //copy merged and sorted values back to the given array (begin..end)
        for (i = left_begin, k = 0; k < (right_end - left_begin + 1); ++i, ++k) {
            a[i] = buffer[k];
        }
    }


    /**
    *  Merges two sorted pieces ([start..middle] and [middle+1..end]) to one sorted piece of array.
    *  Uses external buffer.
    *  Sorting is performed by comparator.compare() function.
    *
    * @tparam size
    * @tparam T - type
    * @param a - array to sort
    * @param p - start
    * @param q - middle
    * @param r - end
    * @param comparator - compare elements of the array
    */
    template<std::size_t size, typename T>
    void merge(std::array<T, size> &a, std::array<T, size> &buffer, std::size_t p, std::size_t q, std::size_t r,
               Comparable<T> *comparator) {
        //edges of merging
        std::size_t left_begin, left_end, right_begin, right_end;
        left_begin = p - 1;
        left_end = q - 1;
        right_begin = left_end + 1;
        right_end = r - 1;
        int i = left_begin, j = right_begin, k = 0;
        //merge two pieces to buffer
        while (k < (right_end - left_begin + 1)) {
            //merging by sorting
            if (i <= left_end and j <= right_end) {
                //sorting by comparator
                buffer[k] = comparator->compare(a[i], a[j]) ? a[i++] : a[j++];
            } else if (i > left_end) { buffer[k] = a[j++]; } else if (j > right_end) { buffer[k] = a[i++]; }
            ++k;
        }
        //copy merged and sorted values back to the given array (begin..end)
        for (i = left_begin, k = 0; k < (right_end - left_begin + 1); ++i, ++k) {
            a[i] = buffer[k];
        }
    }


/**
 * Merges two sorted parts of the vector to one sorted vector.
 *
 * @tparam T - type of values
 * @param vector - vector to sort
 * @param p - start pos of first part (begin of sorting)
 * @param q - end pos of first part (middle of sorting)
 * @param r - end pos of second part (end of sorting)
 * @param comparator
 */
    template<typename T>
    void merge(std::vector<T, std::allocator<T>> &vector, std::size_t p, std::size_t q, std::size_t r,
               Comparable<T> *comparator) {
        //edges
        std::size_t left_begin, left_end, right_begin, right_end;
        left_begin = p - 1;
        left_end = q - 1;
        right_begin = left_end + 1;
        right_end = r - 1;
        std::size_t j = right_begin, k = left_begin;

        //sort to buffer
        while ((k < right_begin)
               and
               (j <= right_end)) {
            if (comparator->compare(vector[j], vector[k])) {
                auto it_begin = vector.begin() + left_begin;
                it_begin = vector.insert(it_begin + (k - left_begin), vector[j]);//new iterator points to k-th element
                vector.erase(it_begin - k + (j + 1));
                j++;
                right_begin++;
            }
            k++;
        }
    }

/**
 * Merges two sorted parts of the vector to one sorted vector.
 * Direction of sorting : increase.
 *
 * @tparam T
 * @param vector
 * @param p
 * @param q
 * @param r
 */
    template<typename T>
    void merge(std::vector<T, std::allocator<T>> &vector, std::size_t p, std::size_t q, std::size_t r) {
        //edges
        std::size_t left_begin, left_end, right_begin, right_end;
        left_begin = p - 1;
        left_end = q - 1;
        right_begin = left_end + 1;
        right_end = r - 1;
        std::size_t j = right_begin, k = left_begin;

        //sort to buffer
        while ((k < right_begin)
               and
               (j <= right_end)) {
            if (vector[j] > vector[k]) {
                auto it_begin = vector.begin() + left_begin;
                it_begin = vector.insert(it_begin + (k - left_begin), vector[j]);//new iterator points to k-th element
                vector.erase(it_begin - k + (j + 1));
                j++;
                right_begin++;
            }
            k++;
        }
    }
}


#endif




