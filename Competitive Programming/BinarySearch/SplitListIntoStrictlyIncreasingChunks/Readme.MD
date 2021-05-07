Given a list of integers nums, and an integer k, return whether it's possible to split the list into lists such that each list has a length ≥ k and is strictly increasing. The list does not need to be split contiguously, that is, you can take integers from nums and place them in any list in any order.

Constraints

n ≤ 100,000 where n is the length of nums.
Example 1
Input
nums = [5, 6, 4, 9, 12]
k = 2
Output
true
Explanation
One possible split is [4, 5] and [6, 9, 12].
Example 2
Input
nums = [5, 7, 7, 7]
k = 2
Output
false
Explanation
It's not possible to split this list so that each list is strictly increasing.

