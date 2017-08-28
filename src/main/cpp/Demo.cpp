/**
 * CSC232 - Data Structures with C++
 * Missouri State University, Fall 2017
 *
 * @file    Demo.cpp
 * @authors Jim Daehn <jdaehn@missouristate.edu>
 *          Frank M. Carrano <carrano@acm.org>
 *          Timothy M. Henry <thenry@neit.edu>
 */

#include <cstdlib>
#include <iostream>

using length_unit = double;
using volumne_unit = double;

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

    std::cout << "Enter the radius of the sphere: ";
    std::cin >> radius;

    // Similarly here, instead of using typedef we use the
    // using statement from above to declare volume_unit as
    // a "new" type that is equivalent to double
    volumne_unit volume{4 * PI * radius * radius * radius / 3};
    std::cout << "The volume of a sphere of radius "
              << radius << " inches is " << volume
              << " cubic inches.\n";

    return EXIT_SUCCESS;
} // end program
