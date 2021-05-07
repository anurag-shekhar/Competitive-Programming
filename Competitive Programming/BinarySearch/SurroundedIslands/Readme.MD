You are given a two-dimensional integer matrix matrix containing 1s and 0s. 1 represents land and 0 represents water. An island is a group of 1s that are neighboring whose perimeter is surrounded by water. Return the number of completely surrounded islands.

Constraints

n, m ≤ 250 where n and m are the number of rows and columns in matrix.
Example 1
Input
matrix = [
    [1, 1, 0, 0, 0],
    [0, 0, 0, 0, 0],
    [0, 1, 1, 1, 0],
    [0, 1, 0, 1, 0],
    [0, 1, 1, 1, 0],
    [0, 0, 0, 0, 0]
]
Output
1
Explanation
There's 2 islands but only the middle island is completely surrounded.
