You are given a string s containing digits from 0 to 9. Return whether there is some arrangement where we can have one pair of the same digits and the rest of the numbers form any number of triples of the same digits.

Constraints

0 ≤ n ≤ 100,000 where n is the length of s
Example 1
Input
s = "21112"
Output
true
Explanation
We can have "22" as the pair and "111" as a triple.
Example 2
Input
s = "55"
Output
true
Explanation
We can have "55" as the pair and there's no triple.
Example 3
Input
s = "111222"
Output
false
Example 4
Input
s = "11111"
Output
true
Example 5
Input
s = "22222222"
Output
true
