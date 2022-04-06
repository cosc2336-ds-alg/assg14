---
name: 'Task 1: Implement Generation of Random Strings'
about: Task 1 for Students
title: 'Task 1: Implement Generation of Random Strings'
labels: enhancement, good first issue
assignees: ''

---

**Description**

Implement the random string generation function as described.


**Suggested Solution**

1. Create a new `List` of the indicated size so it can hold the indicated
   `numItems`.  Use the `List` constructor to do this, specifiying the
   list size on creation.
2. Seed the random number generator with the indicated seed parameters.
   The `srand()` function from the c standard library is used to set the
   random number generator seed value.
3. Use a loop to create the indicated numItems random strings.  You will call
   the `generateRandomString()` function you are given in this loop to
   do the actual work of generating random strings of the indicated
   `itemSize`.  The `List` data type has the `operator[]` overloaded, so
   you can use it to assign strings to your `List` in the loop.
4. Return your `List` that you just initialized with the randomly 
   generated strings.

**Additional Requirements**

