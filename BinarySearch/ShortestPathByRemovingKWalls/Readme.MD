You are given a two-dimensional matrix of 1s and 0s, where 0 represents an empty space while 1 represents a wall you cannot walk through. You are also given an integer k.

You can walk up, down, left, or right. Given that you can remove up to k walls, return the minimum number of steps to walk from the top left corner (0, 0) to the bottom right corner (n - 1, m - 1).

If there is no way to walk from the top left corner to the bottom right corner, return -1.

Constraints

n, m ≤ 50 where n and m are the number of rows and columns in matrix
Example 1
Input
matrix = [
    [0, 0, 0],
    [1, 1, 1],
    [0, 0, 0]
]
k = 1
Output
4
Explanation
We can remove any of the walls and get to the bottom right in 4 moves.
