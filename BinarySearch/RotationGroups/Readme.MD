A rotation group for a string contains all of its unique rotations. For example, "123" can be rotated to "231" and "312" and they are all in the same rotation group.

Given a list of strings words, group each word by their rotation group, and return the total number of groups.

Constraints

n ≤ 200 where n is the length of words.
Example 1
Input
words = ["abc", "xy", "yx", "z", "bca"]
Output
3
Explanation
There are three rotation groups:
["abc", "bca"]
["xy", "yx"]
["z"]
