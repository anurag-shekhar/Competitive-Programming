You are given a list of strings dictionary and two strings start and end. You want to reach from start to end by modifying one character at a time and making sure each resulting word is also in the dictionary. Words are case-sensitive.

Return the minimum number of steps it would take to reach end. Return -1 if it's not possible.

Constraints

0 ≤ n * m ≤ 300,000 where n is the length of dictionary and m is the length of the longest string
Example 1
Input
dictionary = ["day", "say", "soy"]
start = "soy"
end = "day"
Output
3
Explanation
We can take this path: ["soy", "say", "day"].
Example 2
Input
dictionary = ["day", "soy"]
start = "soy"
end = "day"
Output
-1
Explanation
There's no way to change 1 character to reach "day".
