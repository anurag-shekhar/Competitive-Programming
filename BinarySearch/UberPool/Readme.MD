You are given a two-dimensional integer list requested_trips containing [start_x, end_x, num_passengers], and an integer capacity. Each requested trip asks to pick up num_passengers passenger at start_x and drop them off at end_x. You also have a car with the given capacity, and start at x = 0.

Given that you'd like to pick up every passenger and can only move right, return whether you can pick up and drop off everyone.

Constraints

n ≤ 100,000 where n is the length of requested_trips
Example 1
Input
trips = [
    [1, 30, 2],
    [3, 5, 3],
    [5, 9, 3]
]
capacity = 6
Output
true
