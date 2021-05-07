You are given integers sx, sy, ex, ey and two-dimensional list of integers roads. You are currently located at coordinate (sx, sy) and want to move to destination (ex, ey). Each element in roads contains (x, y) which is a road that will be added at that coordinate. Roads are added one by one in order. You can only move to adjacent (up, down, left, right) coordinates if there is a road in that coordinate or if it's the destination coordinate. For example, at (x, y) we can move to (x + 1, y) if (x + 1, y) is a road or the destination.

Return the minimum number of roads in order that must be added before there is a path consisting of roads that allows us to get to (ex, ey) from (sx, sy). If there is no solution, return -1.

Constraints

0 ≤ n ≤ 100,000 where n is the length of roads
Example 1
Input
sx = 0
sy = 0
ex = 1
ey = 2
roads = [
    [9, 9],
    [0, 1],
    [0, 2],
    [0, 3],
    [3, 3]
]
Output
3
Explanation
We need to add the first three roads which allows us to go from (0, 0), (0, 1), (0, 2), (1, 2). Note that we must take (9, 9) since roads must be added in order.
