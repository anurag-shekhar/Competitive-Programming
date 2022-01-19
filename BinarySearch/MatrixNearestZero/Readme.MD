You are given a two-dimensional list of integers matrix containing 1s and 0s. Return the same matrix except each cell's value is now the Manhattan distance to the nearest 0. You can assume at least one 0 exists in the matrix.

Constraints

0 ≤ n, m ≤ 250 where n and m are the number of rows and columns for matrix.
Example 1
Input
matrix = [
    [1, 1, 1],
    [1, 0, 1],
    [0, 0, 0]
]
Output
[
    [2, 1, 2],
    [1, 0, 1],
    [0, 0, 0]
]
Explanation
Only the top left and top right squares have distance of 2 to the nearest 0.
