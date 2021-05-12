You are given a two dimensional matrix where a 1 represents a live cell and a 0 represents a dead cell. A cell's (living or dead) neighbors are its immediate horizontal, vertical and diagonal cells. Compute the next state of the matrix using these rules:

Any living cell with two or three living neighbors lives.
Any dead cell with three living neighbors becomes a live cell.
All other cells die.
Constraints

n, m ≤ 500 where n and m are the number of rows and columns in matrix
Example 1
Input
matrix = [
    [1, 1, 1, 0],
    [0, 1, 0, 1],
    [0, 1, 0, 0],
    [1, 1, 0, 1]
]
Output
[
    [1, 1, 1, 0],
    [0, 0, 0, 0],
    [0, 1, 0, 0],
    [1, 1, 1, 0]
]
