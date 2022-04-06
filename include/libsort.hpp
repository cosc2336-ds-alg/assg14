/** @file libsort.hpp
 * @brief Library functions to sort List items.
 *
 * @author Jane Programmer
 * @note   class: COSC 2336, Spring 2022
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Sorting and Searching
 * @date   April 6, 2022
 *
 * Library functions to sort lists of items for our
 * assignment.  This is the header file where function
 * prototypes for this library are declared.
 */
#ifndef _LIBSORT_HPP_
#define _LIBSORT_HPP_
#include <string>
#include "List.hpp"
using namespace std;

void exchange(string& itemA, string& itemB);
void compareAndExchange(string& itemA, string& itemB);
string generateRandomString(const int length);

// put your function prototype delcarations for the assignment here

#endif // define _LIBSORT_HPP_
