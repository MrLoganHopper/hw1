#include <iostream>
#include <string>
#include <cassert>
#include "ulliststr.h"

int main() {
    ULListStr list;

    // Test 1: Initial state
    std::cout << "Test 1: New list is empty... ";
    assert(list.size() == 0);
    assert(list.empty() == true);
    std::cout << "PASSED\n";

    // Test 2: Push back single element
    std::cout << "Test 2: push_back single element... ";
    list.push_back("hello");
    assert(list.size() == 1);
    assert(list.front() == "hello");
    assert(list.back() == "hello");
    assert(list.get(0) == "hello");
    std::cout << "PASSED\n";

    // Test 3: Push front
    std::cout << "Test 3: push_front element... ";
    list.push_front("world");
    assert(list.size() == 2);
    assert(list.front() == "world");
    assert(list.back() == "hello");
    assert(list.get(0) == "world");
    assert(list.get(1) == "hello");
    std::cout << "PASSED\n";

    // Test 4: Fill node boundary via push_back
    std::cout << "Test 4: Exceed single node size (push_back)... ";
    for (int i = 0; i < 12; i++) {
        list.push_back("back_" + std::to_string(i));
    }
    assert(list.size() == 14);
    assert(list.front() == "world");
    assert(list.back() == "back_11");
    std::cout << "PASSED\n";

    // Test 5: Fill node boundary via push_front
    std::cout << "Test 5: Exceed single node size (push_front)... ";
    for (int i = 0; i < 12; i++) {
        list.push_front("front_" + std::to_string(i));
    }
    assert(list.size() == 26);
    assert(list.front() == "front_11");
    assert(list.get(12) == "world");
    std::cout << "PASSED\n";

    // Test 6: Pop front
    std::cout << "Test 6: pop_front... ";
    list.pop_front();
    assert(list.size() == 25);
    assert(list.front() == "front_10");
    std::cout << "PASSED\n";

    // Test 7: Pop back
    std::cout << "Test 7: pop_back... ";
    list.pop_back();
    assert(list.size() == 24);
    assert(list.back() == "back_10");
    std::cout << "PASSED\n";

    // Test 8: Empty list completely using pop_front
    std::cout << "Test 8: Empty list using pop_front... ";
    size_t current_size = list.size();
    for (size_t i = 0; i < current_size; i++) {
        list.pop_front();
    }
    assert(list.size() == 0);
    assert(list.empty() == true);
    std::cout << "PASSED\n";

    // Test 9: Verify list works normally after being cleared
    std::cout << "Test 9: Reuse cleared list... ";
    list.push_back("reset_1");
    list.push_front("reset_0");
    assert(list.size() == 2);
    assert(list.front() == "reset_0");
    assert(list.back() == "reset_1");
    list.pop_back();
    list.pop_back();
    assert(list.size() == 0);
    std::cout << "PASSED\n";

    std::cout << "\nAll ULListStr unit tests passed successfully!\n";
    return 0;
}