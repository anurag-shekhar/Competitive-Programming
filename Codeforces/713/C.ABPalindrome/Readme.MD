C. A-B Palindrome
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given a string 𝑠
s
 consisting of the characters '0', '1', and '?'. You need to replace all the characters with '?' in the string 𝑠
s
 by '0' or '1' so that the string becomes a palindrome and has exactly 𝑎
a
 characters '0' and exactly 𝑏
b
 characters '1'. Note that each of the characters '?' is replaced independently from the others.

A string 𝑡
t
 of length 𝑛
n
 is called a palindrome if the equality 𝑡[𝑖]=𝑡[𝑛−𝑖+1]
t
[
i
]
=
t
[
n
−
i
+
1
]
 is true for all 𝑖
i
 (1≤𝑖≤𝑛
1
≤
i
≤
n
).

For example, if 𝑠=
s
=
"01?????0", 𝑎=4
a
=
4
 and 𝑏=4
b
=
4
, then you can replace the characters '?' in the following ways:

"010";
"0110".
For the given string 𝑠
s
 and the numbers 𝑎
a
 and 𝑏
b
, replace all the characters with '?' in the string 𝑠
s
 by '0' or '1' so that the string becomes a palindrome and has exactly 𝑎
a
 characters '0' and exactly 𝑏
b
 characters '1'.

Input
The first line contains a single integer 𝑡
t
 (1≤𝑡≤104
1
≤
t
≤
10
4
). Then 𝑡
t
 test cases follow.

The first line of each test case contains two integers 𝑎
a
 and 𝑏
b
 (0≤𝑎,𝑏≤2⋅105
0
≤
a
,
b
≤
2
⋅
10
5
, 𝑎+𝑏≥1
a
+
b
≥
1
).

The second line of each test case contains the string 𝑠
s
 of length 𝑎+𝑏
a
+
b
, consisting of the characters '0', '1', and '?'.

It is guaranteed that the sum of the string lengths of 𝑠
s
 over all test cases does not exceed 2⋅105
2
⋅
10
5
.

Output
For each test case, output:

"-1", if you can't replace all the characters '?' in the string 𝑠
s
 by '0' or '1' so that the string becomes a palindrome and that it contains exactly 𝑎
a
 characters '0' and exactly 𝑏
b
 characters '1';
the string that is obtained as a result of the replacement, otherwise.
If there are several suitable ways to replace characters, you can output any.

Example
inputCopy
9
4 4
01?????0
3 3
??????
1 0
?
2 2
0101
2 2
01?0
0 1
0
0 3
1?1
2 2
?00?
4 3
??010?0
outputCopy
01011010
-1
0
-1
0110
-1
111
1001
0101010
