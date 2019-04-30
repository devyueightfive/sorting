//
// Created by yuri on 30.04.19.
//

#include "test.h"

void test_100K_vector() {
    unsigned int N = 1024 * 128;
    std::vector<int> V(N);

    for (int i = 0; i < N; i++) {
        V[i] = i;
    }
    ABC::top(V);


    auto *decrease = new Decrease<int>();
    std::clock_t start;
    double duration;

    start = std::clock();

    ABC::sort(V, 1, N, decrease);

    duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
    std::cout << "printf: " << duration << '\n';

    ABC::top(V);

    auto *increase = new Increase<int>();
    start = std::clock();
    ABC::sort(V, 1, N, increase);
    duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
    std::cout << "printf: " << duration << '\n';
    ABC::top(V);

    delete decrease;
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