You are given a list of integers nums. Return whether the list alternates from first strictly increasing to strictly decreasing and then strictly increasing etc. If a list is only strictly increasing, return true.

Constraints

2 ≤ n ≤ 100,000 where n is the length of nums
Example 1
Input
nums = [1, 2, 5, 7, 4, 1, 6, 8, 3, 2]
Output
true
Explanation
This list strictly increases, strictly decreases, strictly increases, then strictly decreases.
Example 2
Input
nums = [1, 1, 2, 3, 2, 1]
Output
false
Explanation
This list increases and then decreases, but is not strictly increasing at first.
Example 3
Input
nums = [1, 3, 5, 7]
Output
true
Explanation
This list is strictly increasing.
Example 4
Input
nums = [5, 3, 1, 5, 7]
Output
false
Explanation
This list is not strictly increasing at first.
