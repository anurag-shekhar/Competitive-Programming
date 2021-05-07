You are given a binary tree root. Return the length of the longest path starting from a node that goes top to bottom where its values form an arithmetic sequence.

An arithmetic sequence is a sequence of numbers where the difference between each consecutive two numbers is the same. For example, [2, 4, 6, 8] is an arithmetic sequence as is [1, 4, 7, 10]. A sequence of length two or fewer is considered an arithmetic sequence.

Constraints

0 ≤ n ≤ 100,000 where n is the number of nodes in root
Example 1
Input
Visualize

root = [1, [4, [7, [0, null, null], null], null], null]
Output
3
