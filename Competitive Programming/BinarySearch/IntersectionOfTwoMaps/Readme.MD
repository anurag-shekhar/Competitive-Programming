
You are given two-dimensional lists of integers a and b, both of which contains 0s and 1s. A 1 represents land and 0 represents water, so an island is a group of 1s that are neighboring whose perimeter is surrounded by water.

Return the number of islands that exist in both a and b at the exact same coordinates.

Constraints

1 ≤ n * m ≤ 200,000 where n and m are the number of rows and columns in a and b
Example 1
Input
a = [
    [1, 0, 1],
    [1, 0, 0],
    [1, 0, 0]
]
b = [
    [1, 0, 0],
    [1, 0, 1],
    [1, 0, 0]
]
Output
1
Explanation
The top left island is shared in both a and b.
Example 2
Input
a = [
    [1, 1, 1],
    [1, 1, 1],
    [1, 1, 1]
]
b = [
    [1, 1, 0],
    [1, 0, 1],
    [1, 0, 0]
]
Output
0
