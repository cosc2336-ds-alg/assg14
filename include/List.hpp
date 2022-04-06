/** @file List.hpp
 * @brief Declarations of List class for Assignment Searching and Sorting
 *
 * @author Jane Programmer
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Sorting and Searching
 * @date   June 1, 2021
 *
 * Definitions of a basic List of integers.  Sort of a preview
 * of some of the data structures and abstract data types we
 * will be learning to build and understand.
 */
#ifndef _LIST_HPP_
#define _LIST_HPP_
#include <iostream>
#include <string>
using namespace std;

/** @class List
 * @brief A basic List of integer values for the assignment.
 *
 * A simple class that allows us to define and pass around a list of
 * string values.  To get more practice with classes in C/C++
 * and stop passing around size and array for all of our functions.
 * Notice the overloaded operator[].  We will talk more about operator
 * overloading in the next unit or two.
 */
class List
{
public:
  // constructors and destructors
  List(int size = 0);              // default constructor
  List(int size, string values[]); // standard constructor
  List(const List& list);          // copy constructor
  ~List();                         // destructor

  // accessor methods declarations go here
  int getSize() const;
  string str() const;

  // overloaded operators
  string& operator[](int index);
  bool operator==(const List& rhs) const;
  friend ostream& operator<<(ostream& out, const List& rhs);

  // 
private:
  /// @brief the current size of the list of integer values
  int size;
  /// @brief the string values contained in the list.  This will
  ///   be a dynamically allocated array of integers.
  string* values;
};

/** @class ListMemoryBoundsException
 * @brief Memory Bounds Exception for the List class.
 *
 * Exception to be thrown by our List class if an illegal
 * memory bounds access is attempted.
 *
 */
class ListMemoryBoundsException : public exception
{
public:
  explicit ListMemoryBoundsException(const string& message);
  ~ListMemoryBoundsException();
  virtual const char* what() const throw();

private:
  /// Stores the particular message describing what caused the exception.
  string message;
};

#endif // define _LIST_HPP_
