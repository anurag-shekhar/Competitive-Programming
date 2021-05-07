Given a list of integers nums, return the length of the longest arithmetic subsequence.

A sequence B[i] is defined as an arithmetic sequence if B[i+1] - B[i] have the same value for every 0 ≤ i < len(B) - 1.
For example, [1, 5, 9, 13, 17] is the longest arithmetic subsequence of [-30, 1, 10, 5, 9, -20, 13, 17].

Constraints

n ≤ 1,000 where n is the length of nums
Example 1
Input
nums = [1, 3, 5, 7, 9]
Output
5
Explanation
The whole array is arithmetic since the difference between each consecutive element is 2.
Example 2
Input
nums = [1, 3, 6, 7, 5, 8, 9]
Output
4
Explanation
[6, 7, 8, 9] is the longest arithmetic subsequence.
