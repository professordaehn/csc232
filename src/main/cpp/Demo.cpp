/**
 * CSC232 - Data Structures with C++
 * Missouri State University, Fall 2017
 *
 * @file    Demo.cpp
 * @authors Jim Daehn <jdaehn@missouristate.edu>
 *          Frank M. Carrano <carrano@acm.org>
 *          Timothy M. Henry <thenry@neit.edu>
 */

#define FALSE 0
#define TRUE 1
#define PRODUCTION TRUE

#include <cstdlib>
#include <iomanip>
#include <iostream>

using length_unit = double;
using volume_unit = double;

/**
 * @brief Entry point for this application.
 *
 * @return 0 is returned upon successful execution.
 */
int main() {
    // Compute the volume of a sphere of a given radius
    const double PI{3.14159};

    // Instead of using a typedef statement like:
    //
    // typedef double length_unit;
    //
    // we'll use the modern equivalent with using statements
    // (See above, following the #include)
    length_unit radius;

// Demonstrate the use of preprocessor directives
#if PRODUCTION
    std::cout << "Enter the radius of the sphere: ";
    std::cin >> radius;
#else
    radius = 5;
#endif

    // Similarly here, instead of using typedef we use the
    // using statement from above to declare volume_unit as
    // a "new" type that is equivalent to double
    volume_unit volume{4 * PI * radius * radius * radius / 3};
    std::cout << std::showpoint;
    std::cout << "The volume of a sphere of radius "
              // Notice that precision has to do with the number of
              // significant digits, and not the number of decimals
              // after the decimal point.
              << std::setprecision(2) << radius << " inches is "
              << std::setprecision(4) << volume
              << " cubic inches.\n";

    return EXIT_SUCCESS;
} // end program
