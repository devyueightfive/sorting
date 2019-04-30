//
// Created by yuri on 30.04.19.
//
#ifndef SORT_UTIL_IMPL_H
#define SORT_UTIL_IMPL_H

#include <array>
#include <vector>
#include <string>

namespace ABC {
    template<typename T>
    std::string toString(const std::vector<T> &vector) {
        std::string result{"{"};
        for (auto element : vector) {
            result.append(std::to_string(element)).append(",");
        }
        result.append("}");
        return result;
    }

    template<std::size_t size>
    std::string toString(const std::array<std::string, size> &a) {
        std::string result{"{"};
        for (int i = 0; i < size; ++i) {
            result.append(a[i]).append(",");
        }
        result.append("}");
        return result;
    }

    template<std::size_t size, typename T>
    std::string toString(const std::array<T, size> &a) {
        std::string result{"{"};
        for (int i = 0; i < size; ++i) {
            result.append(std::to_string(a[i])).append(",");
        }
        result.append("}");
        return result;
    }

    template<typename T>
    void top(const std::vector<T> &vector, int number) {
        int n = (number < vector.size()) ? number : vector.size();
        std::cout << "Top " << std::to_string(n) << " of " << std::to_string(vector.size()) << " : " << std::endl;
        for (int i = 0; i < n; i++) {
            std::cout << "[" << std::to_string(i) << "] : " << std::to_string(vector[i]) << std::endl;
        }
        std::cout << "-----" << std::endl << std::endl;
    }
}

#endif //SORT_UTIL_IMPL_H