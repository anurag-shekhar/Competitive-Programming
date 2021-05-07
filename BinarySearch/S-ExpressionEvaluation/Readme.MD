Given a string s representing an arithmetic s-expression, evaluate and return it as an integer.

An s-expression is an expression that's either an integer, like 5, or a recursive expression wrapped in parentheses like (+ (- 2 1) (* 2 2)), which is equivalent to (2 - 1) + (2 * 2) = 5. Valid operations are +, -, /, and *.

Note: / is integer division.

Constraints

n ≤ 1,000 where n is the length of s
Example 1
Input
s = "(- (+ 2 1) 4)"
Output
-1
Explanation
((2 + 1) - 4) = -1
Example 2
Input
s = "(/ -4 3)"
Output
-1
