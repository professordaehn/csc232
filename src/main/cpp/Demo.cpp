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

/* Forward function declarations */

/**
 * Obtain a radius measurement from the user, along with the units of measure.
 *
 * @param prompt the prompt to provide the user for the radius, passed by const reference
 * @param units the units of measure associated with the returned radius, passed by reference
 * @return The radius as entered by the user is explicitly returned as well as the units
 *         of measure that are implicitly returned by reference.
 */
length_unit getRadius(const std::string& prompt, std::string& units);

/**
 * Display the calculated data.
 *
 * @param radius the radius of the sphere, passed by value
 * @param volume the volume of the sphere, passed by value
 * @param units the units of measure for the other parameters, passed by value
 */
void displayData(length_unit radius, volume_unit volume, std::string units);

// An example of a global variable
const std::string UNITS_PROMPT = "What units were used for this measurement? ";

/**
 * @brief Entry point for this application.
 *
 * @return 0 is returned upon successful execution.
 */
int main() {
    // Compute the volume of a sphere of a given radius
    const double PI{3.14159};
    const std::string RADIUS_PROMPT = "Enter the radius of the sphere: ";

    // Instead of using a typedef statement like:
    //
    // typedef double length_unit;
    //
    // we'll use the modern equivalent with using statements
    // (See above, following the #include)
    length_unit radius;
    std::string units;

// Demonstrate the use of preprocessor directives
#if PRODUCTION
    // radius is returned explicitly; units is returned implicitly via a reference parameter
    radius = getRadius(RADIUS_PROMPT, units);
#else
    // Since here we are not prompting for the values obtained
    // by getRadius(), we must explicitly set the variables obtained
    // by that function here:
    radius = 5;
    units = "inches";
#endif

    // Similarly here, instead of using typedef we use the
    // using statement from above to declare volume_unit as
    // a "new" type that is equivalent to double
    volume_unit volume{4 * PI * radius * radius * radius / 3};
    std::cout << std::showpoint;
    displayData(radius, volume, units);

    return EXIT_SUCCESS;
} // end program

length_unit getRadius(const std::string& prompt, std::string& units) {
    length_unit radius;
    std::cout << prompt;
    std::cin >> radius;
    std::cout << UNITS_PROMPT;
    std::cin >> units;
    return radius;
}

void displayData(length_unit radius, volume_unit volume, std::string units) {
    std::cout << std::showpoint;
    std::cout << "The volume of a sphere of radius "
              // Notice that precision has to do with the number of
              // significant digits, and not the number of decimals
              // after the decimal point.
              << std::setprecision(2) << radius << " " << units << " is "
              << std::setprecision(4) << volume
              << " cubic " << units << ".\n";
}