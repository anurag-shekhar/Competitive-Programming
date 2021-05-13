Given a binary tree root, and integers a and b, find the value of the lowest node that has a and b as descendants. A node can be a descendant of itself.

All nodes in the tree are guaranteed to be unique.

Constraints

n ≤ 100,000 where n is the number of nodes in root
Example 1
Input
Visualize

root = [0, [1, null, null], [2, [6, [3, null, null], [4, null, null]], [5, null, null]]]
a = 3
b = 5
Output
2
Example 2
Input
Visualize

root = [0, [1, null, null], [2, [6, [3, null, null], [4, null, null]], [5, null, null]]]
a = 6
b = 4
Output
6
