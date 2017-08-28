/**
 * CSC232 - Data Structures with C++
 * Missouri State University, Fall 2017
 *
 * @file    Demo.cpp
 * @authors Jim Daehn <jdaehn@missouristate.edu>
 *          Frank M. Carrano <carrano@acm.org>
 *          Timothy M. Henry <thenry@neit.edu>
 */

#include <iostream>

/**
 * @brief Entry point for this application.
 *
 * @return 0 is returned upon successful execution.
 */
int main() {
    // Compute the volume of a sphere of a given radius
    const double PI = 3.14159;
    double radius;

    std::cout << "Enter the radius of the sphere: ";
    std::cin >> radius;

    double volume = 4 * PI * radius * radius * radius / 3;
    std::cout << "The volume of a sphere of radius "
              << radius << " inches is " << volume
              << " cubic inches.\n";

    return 0;
} // end program
