/**
 * CSC232 - Data Structures with C++
 * Missouri State University, Fall 2017
 *
 * @file   Main.cpp
 * @author Jim Daehn <jdaehn@missouristate.edu>
 */

#include <cstdlib>
#include <iostream>
#include <ctime>          // std::tm
#include <locale>         // std::locale, std::time_get, std::use_facet
#include <sstream>

enum WEEKDAY {MON = 1, TUE, WED, THU, FRI};
/**
 * @brief Entry point for this application.
 *
 * @return 0 is returned upon successful execution.
 */
int main() {
    std::string dayInput;
    std::cout << "What day is it? ";
    std::cin >> dayInput;

    std::locale locale; // classic "C" locale

    // get time_get facet:
    const std::time_get<char>& tmget = std::use_facet <std::time_get<char> > (locale);
    std::ios::iostate state;
    std::istringstream iss{dayInput};
    std::tm when;
    tmget.get_weekday (iss, std::time_get<char>::iter_type(), iss, state, &when);

    WEEKDAY day = static_cast<WEEKDAY >(when.tm_wday);
    std::string mood;
    switch(day) {
        case MON:
            mood = "awful";
            break;
        case TUE:
            mood = "ok";
            break;
        case WED:
            mood = "eh";
            break;
        case THU:
            mood = "better";
            break;
        case FRI:
            mood = "like screaming \"Hell Yeah!\"";
            break;
        default:
            mood = "invalid input";
            std::cout << mood << "\nProgram exiting with failure" << std::endl;
            return EXIT_FAILURE;
    }
    std::cout << "I guess you feel " << mood << " then..." << std::endl;
    return EXIT_SUCCESS;
} // end program
