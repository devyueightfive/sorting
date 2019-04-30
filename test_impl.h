//
// Created by yuri on 01.05.19.
//

#ifndef SORT_TEST_IMPL_H
#define SORT_TEST_IMPL_H


template<typename Function, typename Parameters>
void test_function(const std::string &message, Function fun, Parameters params) {
    std::cout << message << std::endl;
    //timer vars
    std::clock_t start;
    double duration;
    start = std::clock();
    //run function
    fun(params);
    duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
    std::cout << "Time of running = " << duration << "\n\n";
}

#endif //SORT_TEST_IMPL_H
