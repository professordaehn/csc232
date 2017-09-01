/**
 * CSC232 - Data Structures with C++
 * Missouri State University, Fall 2017
 *
 * @file    Demo.cpp
 * @authors Jim Daehn <jdaehn@missouristate.edu>
 *          Frank M. Carrano <carrano@acm.org>
 *          Timothy M. Henry <thenry@neit.edu>
 */

#include <array>
#include <cstdlib>
#include <iostream>

int main(int argc, char* argv[]) {
    std::array<int, 3> arrayOfThreeInts{1, 2, 3};
    std::array<std::string, 4> menuItems{"Enter radius", "Enter units", "Quit"};

    // As a container *object* it provides another style of the for loop...
    std::cout << "\n-------------------------------------" << std::endl;
    std::cout << "Iterating through array of 3 integers" << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    for (const auto& element : arrayOfThreeInts) {
        std::cout << element << std::endl;
    }

    std::cout << "\n---------------------------------------" << std::endl;
    std::cout << "Iterating through an array of 4 strings" << std::endl;
    std::cout << "---------------------------------------" << std::endl;

    for (const auto& element : menuItems) {
        std::cout << (element.size() == 0 ? "Empty string" : element) << std::endl;
    }

    // Element access methods:
    std::cout << "\n------------------------------------------" << std::endl;
    std::cout << "Demonstrating array element access methods" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "menuItems.at(1)      = " << menuItems.at(1) << std::endl;
    std::cout << "menuItems[1]         = " << menuItems[1] << std::endl;
    std::cout << "menuItems.front()    = " << menuItems.front() << std::endl;
    std::cout << "menuItems.back()     = " << menuItems.back() << std::endl;
    // gain direct access to the underlying data...
    std::string *strings = menuItems.data();
    std::cout << "strings[0]           = " << strings[0] << std::endl;
    strings[0] = "changed!";
    std::cout << "menuItems.at(0)      = " << menuItems.at(0) << std::endl;

    // Capacity-related methods:
    std::cout << "menuItems.empty()    = " << menuItems.empty() << std::endl;
    std::cout << "menuItems.size()     = " << menuItems.size() << std::endl;
    std::cout << "menuItems.max_size() = " << menuItems.max_size() << std::endl;

    return EXIT_SUCCESS;
}