You are given four integers n, x, y, and k. n represents an n by n chessboard and x, y represents a knight positioned at (x, y). The knight has to take exactly k steps, where at each step it chooses any of the 8 directions uniformly at random.

Return the percentage chance rounded down to the nearest integer that the knight remains in the chessboard after taking k steps, with the condition that it can’t enter the board again once it leaves it.

Constraints

1 ≤ n ≤ 25
0 ≤ k ≤ 100
Example 1
Input
n = 8
x = 0
y = 0
k = 1
Output
25
Explanation
This is an 8x8 chessboard and the initial position of the knight is (0, 0). It can take k = 1 step. After taking one step it will lie inside the board only at 2 out of 8 positions, and will lie outside at other positions.
So, the probability is 2/8 = 0.25

