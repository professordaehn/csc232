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
#include <iomanip>
#include <iostream>

using length_unit = double;
using volume_unit = double;
using menu_choice = char;

/**
 * An enumeration of menu choices.
 */
enum class MenuItem : menu_choice {ENTER_RADIUS = '1', ENTER_UNITS, DISPLAY_DATA, QUIT};

/**
 * Read the radius from the user with the given prompt.
 * @param prompt the prompt used to solicit the radius from the end user
 * @return The radius read from standard input is returned.
 */
length_unit getRadius(const std::string& prompt);

/**
 * Read the units of measure associated with the radius with the given prompt.
 * @param prompt the prompt used to solicit the radius from the end user
 * @return The units of measure read from standard input is returned.
 */
std::string getUnits(const std::string& prompt);

/**
 * Calculate the volume of a sphere with given radius.
 * @param radius the radius of the sphere
 * @return The volume for a sphere of the given radius is returned.
 */
volume_unit calculateVolume(const length_unit& radius);

/**
 * Display a menu header that includes a welcome message and instructions.
 */
void displayHeader();

/**
 * Display a set of menu items and return the menu item selected by the end user.
 * @return The menu choice selected by the end user is returned.
 */
MenuItem displayMenu();

/**
 * Display the calculated data.
 *
 * @param radius the radius of the sphere, passed by value
 * @param volume the volume of the sphere, passed by value
 * @param units the units of measure for the other parameters, passed by value
 */
void displayData(length_unit radius, volume_unit volume, const std::string& units);

// Static, global variables
static const std::string RADIUS_PROMPT = "Enter radius: ";
static const std::string UNITS_PROMPT = "What units were used for this measurement? ";
static const length_unit UNIT_RADIUS {1.0};
static const std::string DEFAULT_UNITS {"cm"};
static const double PI {3.14159};
static const size_t NUM_MENU_ITEMS {4};
static const std::string menuItems[NUM_MENU_ITEMS] {
        "Enter/Change radius",
        "Enter/Change units",
        "Display data",
        "Quit"
};

/**
 * @brief Entry point for this application.
 *
 * @return 0 is returned upon successful execution.
 */
int main() {
        // Compute the volume of a sphere of a given radius
        length_unit radius {UNIT_RADIUS};
        std::string units {DEFAULT_UNITS};

        displayHeader();
        MenuItem selection {MenuItem::QUIT};
        do {
                selection = displayMenu();
                switch(selection) {
                case MenuItem::ENTER_RADIUS:
                        radius = getRadius(RADIUS_PROMPT);
                        break;
                case MenuItem::ENTER_UNITS:
                        units = getUnits(UNITS_PROMPT);
                        break;
                case MenuItem::DISPLAY_DATA:
                        displayData(radius, calculateVolume(radius), units);
                        break;
                case MenuItem::QUIT:
                        std::cout << "Thanks for playing!" << std::endl;
                        break;
                default:
                        std::cout << "I don't know what to do.." << std::endl;
                        std::cout << "Please try again." << std::endl;
                }
        } while (selection != MenuItem::QUIT);

        return EXIT_SUCCESS;
} // end program

length_unit getRadius(const std::string& prompt) {
        length_unit radius {UNIT_RADIUS};
        std::cout << prompt;
        std::cin >> radius;
        return radius;
}

std::string getUnits(const std::string& prompt) {
        std::string units {DEFAULT_UNITS};
        std::cout << prompt;
        std::cin >> units;
        return units;
}

volume_unit calculateVolume(const length_unit& radius) {
        return 4 * PI * radius * radius * radius / 3;
}


void displayHeader() {
        std::cout << "Welcome to the voluminator!\nPlease select a menu item by typing the "
                  << "number of the menu item followed by the [ENTER] key...\n"
                  << std::endl;
}

MenuItem displayMenu() {
        char input;
        for (size_t index{0}; index < NUM_MENU_ITEMS; ++index) {
            std::cout << "[" << index + 1 << "] " << menuItems[index] << ".\n";
        }
        std::cout << std::endl;
        std::cout << "Your selection: ";
        std::cin >> input;
        return static_cast<MenuItem>(input);
}

void displayData(length_unit radius, volume_unit volume, const std::string& units) {
        std::cout << std::endl;
        std::cout << std::showpoint;
        std::cout << "The volume of a sphere of radius "
                  << std::setprecision(2) << radius << " " << units << " is "
                  << std::setprecision(4) << volume
                  << " cubic " << units << ".\n";
        std::cout << std::endl;
}
