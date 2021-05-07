You are given a two dimensional integer matrix where 0 is an empty cell and 1 is a wall. You can start at any empty cell on row 0 and want to end up on any empty cell on row n - 1. Given that you can move left, right, or down, return the longest such path where you visit each cell at most once. If there is no viable path, return 0.

Constraints

1 ≤ n * m ≤ 200,000 where n and m are the number of rows and columns in matrix.
Example 1
Input
matrix = [
    [0, 0, 0, 0],
    [1, 0, 0, 0],
    [0, 0, 0, 0]
]
Output
10
Explanation
We can move (0, 0), (0, 1), (0, 2), (0, 3), (1, 3), (1, 2), (1, 1), (2, 1), (2, 2), (2, 3).
