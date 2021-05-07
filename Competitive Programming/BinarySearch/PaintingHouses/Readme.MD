You are looking to paint a row of N fences that can be of K different colors. You have a goal of minimizing cost while ensuring that no two neighboring fences are of the same color.

Given an N by K matrix where the nth row and kth column represents the cost to paint the nth fence with kth color, return the minimum cost which achieves this goal.

Note: All costs will be integers greater than or equal to 0, and there is guaranteed to be at least 2 possible colors.

Bonus: solve in 
O
(
1
)
O(1) space.

Constraints

N, K ≤ 500
Example 1
Input
matrix = [
    [5, 3, 4],
    [2, 1, 6],
    [2, 3, 4],
    [4, 3, 3]
]
Output
10
Explanation
Choose the following color indices (starting from the first fence): 4 -> 1 -> 2 -> 3.
Example 2
Input
matrix = [
    [1, 1, 1],
    [1, 1, 1],
    [1, 1, 1],
    [1, 1, 1],
    [1, 1, 1]
]
Output
5
Explanation
It doesn't matter which colors we paint since they're all cost 1.
Example 3
Input
matrix = [
    [1, 5, 1],
    [1, 5, 1],
    [1, 5, 1],
    [1, 5, 1],
    [1, 5, 1]
]
Output
5
Explanation
Alternate between the first and the third color which each cost 1.
Example 4
Input
matrix = [
    [1, 2, 3],
    [4, 1, 8],
    [2, 3, 4],
    [3, 3, 1],
    [4, 2, 3]
]
Output
7
Explanation
Choose the following colors: 1 -> 1 -> 2 -> 1 -> 2.
