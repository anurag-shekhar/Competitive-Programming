You are given two lowercase alphabet strings s and t. Consider an operation where we replace all occurrences of a character in s to another character. Given that you can perform any number of operations, return whether s can be turned into t.

Constraints

n ≤ 100,000 where n is the length of s.
Example 1
Input
s = "aab"
t = "zzz"
Output
true
Explanation
We can transform "a"s into "z"s and the "b" into "z"
Example 2
Input
s = "aab"
t = "xyz"
Output
false
Explanation
Since the "a"s need to be transformed together, they can't turn into "x" and "y".
