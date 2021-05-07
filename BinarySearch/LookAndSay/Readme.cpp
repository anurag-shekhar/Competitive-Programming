The "look and say" sequence is defined as follows: beginning with the term 1, each subsequent term visually describes the digits appearing in the previous term. The first few terms are as follows:

1
11             <- 1 one
21             <- 2 ones
1211           <- 1 two, 1 one
111221         <- 1 one, 1 two, 2 ones
312211         <- 3 ones, 2 twos, 1 one
Given an integer n, return the nth term of this sequence as a string.

Constraints

1 ≤ n ≤ 40
Example 1
Input
n = 3
Output
"21"
Example 2
Input
n = 4
Output
"1211"
Example 3
Input
n = 5
Output
"111221"
