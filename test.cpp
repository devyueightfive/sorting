//
// Created by yuri on 30.04.19.
//

#include "test.h"
#include <algorithm>

void test_100K_vector() {
    //create and fill vector
    unsigned int N = 1024 * 128;
    std::vector<int> V(N);
    for (int i = 0; i < N; i++) {
        V[i] = i;
    }
    ABC::top(V); //print top of vector

    //timer
    std::clock_t start;
    double duration;

    //sort in decrease direction
    auto *decrease = new Decrease<int>();
    start = std::clock();
    ABC::sort(V, 1, N, decrease);
    duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
    std::cout << "\nTime of sorting  = " << duration << '\n';
    ABC::top(V);

    //sort in increase direction
    auto *increase = new Increase<int>();
    start = std::clock();
    ABC::sort(V, 1, N, increase);
    duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
    std::cout << "\nTime of sorting  = " << duration << '\n';
    ABC::top(V);

    delete decrease;
    delete increase;
}

void test_100K_array_with_internal_buffer() {
    //create and fill vector
    const unsigned int N = 1024 * 128;
    std::array<int, N> V{};
    for (int i = 0; i < N; i++) {
        V[i] = i;
    }
    std::cout << "Created array with " << std::to_string(N) << " elements.\n";
    //sort in decrease direction
    auto decrease = [](std::array<int, N> &V) {
        std::cout << "Sorting ..." << std::endl;
        auto *decrease = new Decrease<int>();
        ABC::sort(V, 1, N, decrease);
        delete decrease;
        ABC::top(V);
    };

    //sort in increase direction
    auto increase = [](std::array<int, N> &V) {
        std::cout << "Sorting ..." << std::endl;
        auto *increase = new Increase<int>();
        ABC::sort(V, 1, N, increase);
        delete increase;
        ABC::top(V);
    };
    test_function("Array: decrease sorting: ", decrease, V);
    test_function("Array: increase sorting: ", increase, V);
}

void test_100K_array_with_external_buffer() {
    //create and fill vector
    const unsigned int N = 1024 * 128;
    std::array<int, N> V{};
    for (int i = 0; i < N; i++) {
        V[i] = i;
    }
    std::cout << "Created vector with " << std::to_string(N) << " elements.\n";
    //sort in decrease direction
    auto decrease = [](std::array<int, N> &V) {
        std::cout << "Sorting ..." << std::endl;
        //external buffer
        std::array<int, N> Buffer{};
        auto *decrease = new Decrease<int>();
        ABC::sort(V, Buffer, 1, N, decrease);
        delete decrease;
        ABC::top(V);
    };

    //sort in increase direction
    auto increase = [](std::array<int, N> &V) {
        std::cout << "Sorting ..." << std::endl;
        //external buffer
        std::array<int, N> Buffer{};
        auto *increase = new Increase<int>();
        ABC::sort(V, Buffer, 1, N, increase);
        delete increase;
        ABC::top(V);
    };

    test_function("Decrease sorting:", decrease, V);
    test_function("Increase sorting:", increase, V);
}


void test_array() {
    std::array<int, 7> A{3, 2, -2, -3, 4, 0, 1};
    std::cout << "array = " << ABC::toString(A) << endl;
    ABC::sort(A, 1, A.size());
    std::cout << endl << ABC::toString(A) << endl;

    auto *decrease = new Decrease<int>();
    ABC::sort(A, 1, A.size(), decrease);
    std::cout << endl << ABC::toString(A) << endl;
    std::cout << endl;

    std::array<std::string, 7> S{"?", "1", "a", "b", "A", "Z", " "};
    std::cout << "array = " << ABC::toString(S) << endl;
    ABC::sort(S, 1, S.size());
    std::cout << endl << ABC::toString(S) << endl;

    auto *decreaseS = new Decrease<std::string>();
    ABC::sort(S, 1, S.size(), decreaseS);
    std::cout << endl << ABC::toString(S) << endl;

    auto *increaseS = new Increase<std::string>();
    ABC::sort(S, 1, S.size(), increaseS);
    std::cout << endl << ABC::toString(S) << endl;

    delete decrease;
    delete decreaseS;
    delete increaseS;
}


void test_vector() {
    std::vector<int> V{3, 2, -2, -3, 4, 0, 1};
    std::cout << "array = " << ABC::toString(V) << endl;
    auto *decrease = new Increase<int>();
    auto *increase = new Decrease<int>();
    ABC::sort(V, 1, V.size(), decrease);
    std::cout << endl << ABC::toString(V) << endl;
    delete decrease;
    delete increase;
}




