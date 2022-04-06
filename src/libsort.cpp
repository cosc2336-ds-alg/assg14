/** @file libsort.hpp
 * @brief Library functions to sort List items.
 *
 * @author Jane Programmer
 * @note   class: CSCI 520, Spring 2022
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Sorting and Searching
 * @date   April 6, 2022
 *
 * Library functions to sort lists of items for our
 * assignment.  This is the implementation file where the
 * implementations of the libray functions are
 * defined.
 */
#include "libsort.hpp"
#include "List.hpp"
#include <iostream>
#include <string>
using namespace std;


/** @brief exchange strrings
 *
 * Exchange the given string references, e.g. swap them.
 * 
 * @param itemA A reference to one of the strings to be
 *   swapped.
 * @param itemB A reference to the other string to be
 *   exchanged.
 */
void exchange(string& itemA, string& itemB)
{
  string temp = itemA;
  itemA = itemB;
  itemB = temp;
}

/** @brief compare and exchange strings
 *
 * Compare the ordering of the two indicated strings.  If they
 * are not in correct ascending order, exchange (swap) them.
 * As a result of calling this function, after it returns, the
 * smaller of the two values will be in itemA and the larger
 * in itemB.
 * 
 * @param itemA A reference to one of the strings to be
 *   compared and swapped if needed
 * @param itemB A reference to the other string to be
 *   compared and exchanged if needed.
 */
void compareAndExchange(string& itemA, string& itemB)
{
  if (itemB < itemA)
  {
    exchange(itemA, itemB);
  }
}

/** @brief generate random string
 * 
 * Genreate and return a new string of random
 * characters of the indicated length
 *
 * @param length The number of random characters to generate
 *   in the string.
 * 
 * @returns string Returns the randomly generated string of the given
 *   length
 */
string generateRandomString(const int length)
{
  static const char alphanum[] =
    "0123456789"
    "abcdefghijklmnopqrstuvwxyz";

  // create a new string to return, and make it big enough to hold
  // the characters we will randomly pick
  string randomString;
  randomString.reserve(length);

  // iterate length times, picking characters at random from the
  // allowed set of characters and appending them to the string
  // we are creating
  for (int i = 0; i < length; i++)
  {
    randomString += alphanum[rand() % (sizeof(alphanum) - 1)];
  }

  return randomString;
}


