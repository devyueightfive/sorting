//
// Created by yuri on 30.04.19.
//

#ifndef SORT_UTIL_H
#define SORT_UTIL_H

namespace ABC {
    /**
     * @brief String representation of %vector.
     * @tparam T - assume not be a string.
     * @return - string like "{T1. T2, ...}"
     */
    template<typename T>
    std::string toString(const std::vector<T> &vector);

    /**
     * @brief String representation %array of strings.
     * @tparam size - size of array.
     * @param array - array of strings.
     * @return - string like "{string1. string2, ...}"
     */
    template<std::size_t size>
    std::string toString(const std::array<std::string, size> &array);

    /**
     * String representation %array.
     * @tparam size - size of array.
     * @tparam T - type assumed not be a string.
     * @param array - array of T.
     * @return - string like "{T1. T2, ...}"
     */
    template<std::size_t size, typename T>
    std::string toString(const std::array<T, size> &array);

    /**
     * @brief Represents top n elements of %vector.
     * @tparam T
     * @param vector
     */
    template<class T>
    void top(const T &vector, int number = 10);
}

#include "util_impl.h"

#endif //SORT_UTIL_H
