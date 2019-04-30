//
// Created by yuri on 30.04.19.
//

#ifndef SORT_TEST_H
#define SORT_TEST_H

#include <iostream>
#include <ctime>

#include "sort.h"
#include "util.h"

using namespace std;

void test_100K_vector();

void test_100K_array_with_internal_buffer();

void test_100K_array_with_external_buffer();

void test_array();

void test_vector();


template<typename Function, typename Parameters>
void test_function(const std::string &message, Function fun, Parameters params);

#include "test_impl.h"

#endif //SORT_TEST_H
