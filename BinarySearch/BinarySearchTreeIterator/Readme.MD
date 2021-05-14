Implement a binary search tree iterator with the following methods:

next returns the next smallest element in the tree
hasnext returns whether there is a next element in the iterator
For example, given the following tree

   4
  / \
 2   7
    / \
   5   9
It should return the values in this order 2, 4, 5, 7, 9.

Example 1
Input
methods = ["constructor", "hasnext", "hasnext", "next", "hasnext", "hasnext", "hasnext", "next", "hasnext", "hasnext", "hasnext", "next", "hasnext", "next", "hasnext"]
arguments = [[[2, [1, [0, null, null], null], [3, null, null]]], [], [], [], [], [], [], [], [], [], [], [], [], [], []]`
Output
[null, true, true, 0, true, true, true, 1, true, true, true, 2, true, 3, false]
