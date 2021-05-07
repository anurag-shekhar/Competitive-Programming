You are given a lowercase alphabet string s and a two-dimensional list of strings pairs. Each element in pairs contains [a, b] meaning that character a and b are considered equivalent. We say that if a and b are equivalent and b and c are equivalent, then a and c are also equivalent. Also, any character a is equivalent to itself.

Return whether s is a palindrome given the equivalence relations.

Constraints

0 ≤ n ≤ 100,000 where n is the length of s
0 ≤ p ≤ 100,000 where p is the length of p
Example 1
Input
s = "acba"
pairs = [
    ["b", "c"]
]
Output
true
Explanation
Since "b" = "c", we have "acba" = "acca", which is a palindrome.
Example 2
Input
s = "zz"
pairs = []
Output
true
Explanation
"z" is equivalent to itself.
Example 3
Input
s = "ac"
pairs = [
    ["a", "b"],
    ["b", "c"]
]
Output
true
Explanation
Since "a" = "c", we have "ac" = "cc", which is a palindrome.
