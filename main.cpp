
#include "test.h"


int main() {
//    std::cout << "Test array: " << std::endl;
//    test_array();
//    std::cout << "Test vector: " << std::endl;
//    test_vector();
//    std::cout << "Test 100K vector: " << std::endl;
//    test_100K_vector();
    std::cout << "Test 100K array with internal buffer: " << std::endl;
    test_100K_array_with_internal_buffer();
    std::cout << "Test 100K array with external buffer: " << std::endl;
    test_100K_array_with_external_buffer();
    return 0;
}



