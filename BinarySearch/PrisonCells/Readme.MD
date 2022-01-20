You are given a list of integers nums containing 1s and 0s and an integer k. Each value in nums represents the state of a prison cell where 1 means it's occupied and 0 means it's empty.

On each day if a cell has two adjacent cells that are either both occupied or both empty, then it becomes occupied. Otherwise, it becomes empty.

Return the state of the prison cells after k days.

Constraints

n = 8 where n is the length of nums
1 ≤ k < 2 ** 31
Example 1
Input
nums = [1, 0, 1, 0, 0, 0, 1, 0]
k = 1
Output
[0, 1, 1, 0, 1, 0, 1, 0]
Explanation
Note that the first and last index can never be occupied since they can never have 2 neighbors.
And any cell that had two neighbors of the same value have been set to 1
