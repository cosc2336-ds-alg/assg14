/** @file test-libsort.cpp
 *
 * @brief Unit tests for Assignment Basic Sorting
 *
 * @author Derek Harter
 * @note   class: CSCI 520, Summer 2022
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Sorting and Searching
 * @date   April 6, 2022
 *
 * Implement basic sorting methods.
 *
 * This file contains test cases and individual unit tests for the
 * Assignment Basic Sorting using the catch2 unit test framework to
 * define the test cases and test assertions.
 */
#include "libsort.hpp"
#include "List.hpp"
#include "catch.hpp"
#include <iostream>
#include <string>
using namespace std;


/** Test random string generation.
 */
TEST_CASE("<libsort> test random string genreation", "[task0]")
{
  // although string is random, by setting the seed beforw we generate it
  // we should always get back the same randomly generated string
  srand(42);
  string s1 = generateRandomString(5);
  CHECK(s1 == "6oh9s");

  string s2 = generateRandomString(8);
  CHECK(s2 == "a1obn6z9");
  
  string s3 = generateRandomString(10);
  CHECK(s3 == "0oqg06r3oh");
}


/** Test task 1, randm generate of a list of string values.
 */
/*
TEST_CASE("<libsort> test random list genreation", "[task1]")
{
  // test default item size is 5 and random seed is 42
  List l1 = generateRandomListOfStrings(3);

  CHECK(l1.getSize() == 3);
  CHECK(l1.str() == "<list> size: 3 [ 6oh9s, a1obn, 6z90o ]");

  // generate list of strings of 3 characters each
  List l2 = generateRandomListOfStrings(4, 3);
  CHECK(l2.getSize() == 4);
  CHECK(l2.str() == "<list> size: 4 [ 6oh, 9sa, 1ob, n6z ]");

  // test random number seed is being set
  List l3 = generateRandomListOfStrings(5, 3, 99);
  CHECK(l3.getSize() == 5);
  CHECK(l3.str() == "<list> size: 5 [ o8d, 1lo, dny, pzg, kh5 ]");

  List l4 = generateRandomListOfStrings(5, 3, 99);
  CHECK(l4.getSize() == 5);
  CHECK(l4.str() == "<list> size: 5 [ o8d, 1lo, dny, pzg, kh5 ]");
  CHECK(l3 == l4);

  // one final bigger test
  List l5 = generateRandomListOfStrings(20, 8, 33);
  CHECK(l5.getSize() == 20);
  CHECK(l5.str() == "<list> size: 20 [ jxoppu99, 8waqsxwr, 3cgkfr9a, iqdhzycj, bgo1aeqi, a182ylti, xqishr3z, xwxxupwm, 5knfetdp, u179mh70, 7psowb3t, 80625i4a, jr5x1i2b, kakmr7my, wv28652e, moxr71iq, 9n3am6lm, gm8ntb16, m3esownq, lky81gea ]");
}
*/


/** Test task 2, implementation of insretion sort
 */
/*
TEST_CASE("<libsort> test insretion sort", "[task2]")
{
  // test edge cases.  Sort of an empty list should not crash or do anything
  List l0(0);
  insertionSort(l0);
  CHECK(l0.getSize() == 0);
  CHECK(l0.str() == "<list> size: 0 [ ]");

  // sort a list of size 1
  List l1(1);
  l1[0] = "hello";
  insertionSort(l1);
  CHECK(l1.getSize() == 1);
  CHECK(l1.str() == "<list> size: 1 [ hello ]");

  // generate a list of 5 items, and test it sorts ok
  List l2 = generateRandomListOfStrings(5, 3, 99);
  CHECK(l2.getSize() == 5);
  CHECK(l2.str() == "<list> size: 5 [ o8d, 1lo, dny, pzg, kh5 ]");  
  insertionSort(l2);
  CHECK(l2.getSize() == 5);
  CHECK(l2.str() == "<list> size: 5 [ 1lo, dny, kh5, o8d, pzg ]");

  // test bigger list sorts
  List l3 = generateRandomListOfStrings(20, 8, 33);
  CHECK(l3.getSize() == 20);
  CHECK(l3.str() == "<list> size: 20 [ jxoppu99, 8waqsxwr, 3cgkfr9a, iqdhzycj, bgo1aeqi, a182ylti, xqishr3z, xwxxupwm, 5knfetdp, u179mh70, 7psowb3t, 80625i4a, jr5x1i2b, kakmr7my, wv28652e, moxr71iq, 9n3am6lm, gm8ntb16, m3esownq, lky81gea ]");
  insertionSort(l3);
  CHECK(l3.getSize() == 20);
  CHECK(l3.str() == "<list> size: 20 [ 3cgkfr9a, 5knfetdp, 7psowb3t, 80625i4a, 8waqsxwr, 9n3am6lm, a182ylti, bgo1aeqi, gm8ntb16, iqdhzycj, jr5x1i2b, jxoppu99, kakmr7my, lky81gea, m3esownq, moxr71iq, u179mh70, wv28652e, xqishr3z, xwxxupwm ]");
  
}
*/

/** Test task 3, calculate h steps
 */
/*
TEST_CASE("<libsort> test calculate h steps", "[task3]")
{
  int h;

  // test for size 5 file
  h = calculateInitialH(5);
  CHECK(h == 1);

  // test for size 10 file
  h = calculateInitialH(10);
  CHECK(h == 4);

  // test for size 100 file
  h = calculateInitialH(100);
  CHECK(h == 13);

  // test for size 1000 file
  h = calculateInitialH(1000);
  CHECK(h == 121);
}
*/


/** Test task 4, implementation of shell sort
 */
/*
TEST_CASE("<libsort> test shell sort", "[task4]")
{
  // test edge cases.  Sort of an empty list should not crash or do anything
  List l0(0);
  shellSort(l0);
  CHECK(l0.getSize() == 0);
  CHECK(l0.str() == "<list> size: 0 [ ]");

  // sort a list of size 1
  List l1(1);
  l1[0] = "hello";
  shellSort(l1);
  CHECK(l1.getSize() == 1);
  CHECK(l1.str() == "<list> size: 1 [ hello ]");

  // generate a list of 5 items, and test it sorts ok
  List l2 = generateRandomListOfStrings(5, 3, 99);
  CHECK(l2.getSize() == 5);
  CHECK(l2.str() == "<list> size: 5 [ o8d, 1lo, dny, pzg, kh5 ]");  
  shellSort(l2);
  CHECK(l2.getSize() == 5);
  CHECK(l2.str() == "<list> size: 5 [ 1lo, dny, kh5, o8d, pzg ]");

  // test bigger list sorts
  List l3 = generateRandomListOfStrings(20, 8, 33);
  CHECK(l3.getSize() == 20);
  CHECK(l3.str() == "<list> size: 20 [ jxoppu99, 8waqsxwr, 3cgkfr9a, iqdhzycj, bgo1aeqi, a182ylti, xqishr3z, xwxxupwm, 5knfetdp, u179mh70, 7psowb3t, 80625i4a, jr5x1i2b, kakmr7my, wv28652e, moxr71iq, 9n3am6lm, gm8ntb16, m3esownq, lky81gea ]");
  shellSort(l3);
  CHECK(l3.getSize() == 20);
  CHECK(l3.str() == "<list> size: 20 [ 3cgkfr9a, 5knfetdp, 7psowb3t, 80625i4a, 8waqsxwr, 9n3am6lm, a182ylti, bgo1aeqi, gm8ntb16, iqdhzycj, jr5x1i2b, jxoppu99, kakmr7my, lky81gea, m3esownq, moxr71iq, u179mh70, wv28652e, xqishr3z, xwxxupwm ]");
  
}
*/
