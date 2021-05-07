Given a binary tree root, shift all the nodes as far right as possible while maintaining the relative ordering in each level.

Constraints

n ≤ 100,000 where n is the number of nodes in root
Example 1
Input
Visualize

root = [1, [2, [4, null, null], null], [3, [5, [6, null, null], [7, null, null]], null]]
Output
Visualize

[1, [2, null, null], [3, [4, null, null], [5, [6, null, null], [7, null, null]]]]
Example 2
Input
Visualize

root = [1, [2, [3, [4, [5, null, null], null], null], null], null]
Output
Visualize

[1, null, [2, null, [3, null, [4, null, [5, null, null]]]]]
Example 3
Input
Visualize

root = [1, null, [2, null, [3, null, [4, null, [5, null, null]]]]]
Output
Visualize

[1, null, [2, null, [3, null, [4, null, [5, null, null]]]]]
