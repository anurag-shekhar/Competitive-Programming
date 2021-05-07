A univalue tree is a tree where all nodes under it have the same value.

Given a binary tree root, return the number of univalue subtrees.

Constraints

1 ≤ n ≤ 100,000 where n is the number of nodes in root
Example 1
Input
Visualize

root =
0
1
0
1
0
1
1
Output
5
Explanation
The unival trees include four leaf nodes (three of them are 1s, the other one is the rightmost 0), and one subtree in the middle (containing all 1s).
Example 2
Input
Visualize

root =
1
0
0
Output
2
Explanation
The two leaf nodes are unival trees.
