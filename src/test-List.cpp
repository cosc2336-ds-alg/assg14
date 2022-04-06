/** @file test-List.cpp
 *
 * @brief Unit tests for Assignment Sorting and Searching:
 *   Recursive Sorting and Searching with Merge Sort and Binary Search.
 *
 * @author Derek Harter
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Sorting and Searching
 * @date   June 1, 2021
 *
 * Implement recursive sorting and searching algorithms in a
 * class ADT.
 *
 * This file contains test cases and individual unit tests for the
 * Assignment Sorting and Searching implementation.  This file uses
 * the catch2 unit test framework to define the test cases and test
 * assertions.
 */
#include "List.hpp"
#include "catch.hpp"
#include <iostream>
using namespace std;

/** Tests of the List type you have been given to use for
 * this assignment.
 */
TEST_CASE("<List> test of List user defined type for this assignment", "[task0]")
{
  // construct an empty list
  List l1;
  CHECK(l1.getSize() == 0);
  CHECK(l1.str() == "<list> size: 0 [ ]");

  // construct with a static array
  string values2[] = {"neo", "morpheus", "trinity", "cypher", "oracle"};
  List l2(5, values2);
  CHECK(l2.getSize() == 5);

  // check the overloaded [] indexing operator
  CHECK(l2[0] == "neo");
  CHECK(l2[1] == "morpheus");
  CHECK(l2[2] == "trinity");
  CHECK(l2[3] == "cypher");
  CHECK(l2[4] == "oracle");
  CHECK(l2.str() == "<list> size: 5 [ neo, morpheus, trinity, cypher, oracle ]");

  // check we are getting a valid reference back, allows us to modify
  // the list
  l2[0] = "smith";
  CHECK(l2[0] == "smith");

  l2[4] = "switch";
  CHECK(l2[4] == "switch");

  l2[2] = "agent " + l2[0];
  CHECK(l2[2] == "agent smith");

  CHECK(l2.str() == "<list> size: 5 [ smith, morpheus, agent smith, cypher, switch ]");

  // check that the values were copied into a new block of memory
  CHECK(values2[0] == "neo");
  CHECK(values2[4] == "oracle");
  CHECK(values2[2] == "trinity");

  // test bounds checking for operator[]
  CHECK_THROWS_AS(l2[5], ListMemoryBoundsException);
  CHECK_THROWS_AS(l2[-1], ListMemoryBoundsException);

  // test copy constructor works.
  List l3 = l2;
  CHECK(l3[0] == "smith");
  CHECK(l3[1] == "morpheus");
  CHECK(l3[2] == "agent smith");
  CHECK(l3[3] == "cypher");
  CHECK(l3[4] == "switch");
  CHECK(l3.str() == "<list> size: 5 [ smith, morpheus, agent smith, cypher, switch ]");

  // make sure l3 is truly a copy of l2
  l3[0] = "mouse";
  l3[2] = "tank";
  l3[4] = "dozer";
  CHECK(l3[0] == "mouse");
  CHECK(l3[1] == "morpheus");
  CHECK(l3[2] == "tank");
  CHECK(l3[3] == "cypher");
  CHECK(l3[4] == "dozer");
  CHECK(l3.str() == "<list> size: 5 [ mouse, morpheus, tank, cypher, dozer ]");

  // was l2 modified when we changed l3?
  CHECK(l2[0] == "smith");
  CHECK(l2[1] == "morpheus");
  CHECK(l2[2] == "agent smith");
  CHECK(l2[3] == "cypher");
  CHECK(l2[4] == "switch");
  CHECK(l2.str() == "<list> size: 5 [ smith, morpheus, agent smith, cypher, switch ]");

  // is l3 modified by changing l2?
  l2[1] = "merovingian";
  l2[3] += " white rabbit";
  CHECK(l2[0] == "smith");
  CHECK(l2[1] == "merovingian");
  CHECK(l2[2] == "agent smith");
  CHECK(l2[3] == "cypher white rabbit");
  CHECK(l2[4] == "switch");
  CHECK(l2.str() == "<list> size: 5 [ smith, merovingian, agent smith, cypher white rabbit, switch ]");

  CHECK(l3[0] == "mouse");
  CHECK(l3[1] == "morpheus");
  CHECK(l3[2] == "tank");
  CHECK(l3[3] == "cypher");
  CHECK(l3[4] == "dozer");
  CHECK(l3.str() == "<list> size: 5 [ mouse, morpheus, tank, cypher, dozer ]");

  // a bit more bounds checking on l3 for operator[]
  CHECK_THROWS_AS(l3[100], ListMemoryBoundsException);
  CHECK_THROWS_AS(l3[-100], ListMemoryBoundsException);

  // test overloaded boolean operator==
  // a list should be equal to itself
  CHECK(l2 == l2);
  CHECK(l3 == l3);

  // test unequal lists are not equal
  CHECK_FALSE(l2 == l3);
  CHECK_FALSE(l3 == l2);

  // test empty lists are equal
  List l4; // another empty list, like l1
  CHECK(l1 == l4);
  CHECK(l4 == l1);

  // test that different lists can be equal and not equal again
  // l5 should be a copy of l3, so initially equal
  List l5 = l3;
  CHECK(l5 == l3);
  CHECK(l3 == l5);

  // modify 1 value of l5, now lists are not equal
  l5[3] = "architect";
  CHECK_FALSE(l5 == l3);
  CHECK_FALSE(l3 == l5);

  // make equal again, and change values on both ends of both lists, just to
  // make sure about ending index manipulations
  l3[3] = "architect";
  l5[0] = "keymaker";
  l5[4] = "link";
  l3[0] = "keymaker";
  l3[4] = "link";
  CHECK(l5 == l3);
  CHECK(l3 == l5);

  // actually haven't checked if lists of unequal size are false yet
  string values6[] = {"persophne", "seraph", "niobe"};
  List l6(3, values6);
  string values7[] = {"persophne", "seraph", "niobe", "ghost"};
  List l7(4, values7);
  CHECK_FALSE(l6 == l7);
  CHECK_FALSE(l7 == l6);
}

