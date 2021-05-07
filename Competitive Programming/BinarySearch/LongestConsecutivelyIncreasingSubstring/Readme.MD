You are given a string s containing lowercase alphabet characters as well as "?". For each "?" you must either delete it or replace it with any lowercase alphabet character.

Return the length of the longest consecutively increasing substring that starts with "a".

Constraints

1 ≤ n ≤ 100,000 where n is the length of s
Example 1
Input
s = "bca???de"
Output
5
Explanation
We can turn s into "bcabcde" and "abcde" is the longest consecutively increasing substring that starts with "a"
Example 2
Input
s = "zyx"
Output
0
Explanation
No substring here starts with "a"
