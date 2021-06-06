Given a list of integer nums, return the earliest index i such that the sum of the numbers left of i is equal to the sum of numbers right of i. If there's no solution, return -1.

Sum of an empty list is defined to be 0.

Constraints

1 ≤ n ≤ 100,000 where n is the length of nums
Example 1
Input
nums = [2, 3, 4, 0, 5, 2, 2]
Output
3
Explanation
Sum of the numbers left of index 3 is 9 and sum of the numbers right of index 3 also 9.
Example 2
Input
nums = [1, -2, 2]
Output
0
Explanation
Sum of the numbers left of index 0 is 0 and sum of the numbers right of index 0 also 0.
