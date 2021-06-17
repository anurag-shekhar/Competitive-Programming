Given the mapping a = 1, b = 2, ... z = 26, as well as "*" which can be mapped anything from 1 to 9, and an encoded message message (as a string), count the number of ways it can be decoded.

Mod the result by 10 ** 9 + 7.

Constraints

n ≤ 100,000 where n is the length of message
Example 1
Input
message = "1*"
Output
18
Explanation
The "*" can represent anything from 1 to 9, so this can be decoded as:
["aa", "ab", "ac", "ad", "ae", "af", "ag", "ah", "ai"] - (1, 1), (1, 2), ..., (1, 9)`
["k", "l", "m", "n", "o", "p", "q", "r", "s"] (11), (12), ..., (19)
Example 2
Input
message = "22"
Output
2
Explanation
This can represent "bb" or "v"
Example 3
Input
message = "*00"
Output
0
Explanation
There's no valid decoding
