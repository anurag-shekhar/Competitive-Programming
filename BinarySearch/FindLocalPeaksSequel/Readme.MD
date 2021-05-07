You are given a list of integers nums. Return the index of every peak in the list, sorted in ascending order. An index i is called a peak if all three conditions are true:

The next number on its right that's different than nums[i] doesn't exist or is smaller than nums[i]
The next number on its left that's different than nums[i] doesn't exist or is smaller than nums[i]
There is at least one number on its left or its right that's different than nums[i]
Constraints

0 ≤ n ≤ 100,000 where n is the length of nums
Example 1
Input
nums = [2, 5, 5, 5, 3, 8, 8]
Output
[1, 2, 3, 5, 6]
Explanation
The plateau of 5s are considered peaks. So are the 8s.
Example 2
Input
nums = [3]
Output
[]
Explanation
A list of length 1 is not considered a peak.
Example 3
Input
nums = [2, 2, 2]
Output
[]
