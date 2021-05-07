A. Perfectly Imperfect Array
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Given an array 𝑎
a
 of length 𝑛
n
, tell us whether it has a non-empty subsequence such that the product of its elements is not a perfect square.

A sequence 𝑏
b
 is a subsequence of an array 𝑎
a
 if 𝑏
b
 can be obtained from 𝑎
a
 by deleting some (possibly zero) elements.

Input
The first line contains an integer 𝑡
t
 (1≤𝑡≤100
1
≤
t
≤
100
) — the number of test cases. The description of the test cases follows.

The first line of each test case contains an integer 𝑛
n
 (1≤𝑛≤100
1
≤
n
≤
100
) — the length of the array 𝑎
a
.

The second line of each test case contains 𝑛
n
 integers 𝑎1
a
1
, 𝑎2
a
2
, …
…
, 𝑎𝑛
a
n
 (1≤𝑎𝑖≤104
1
≤
a
i
≤
10
4
) — the elements of the array 𝑎
a
.

Output
If there's a subsequence of 𝑎
a
 whose product isn't a perfect square, print "YES". Otherwise, print "NO".

Example
inputCopy
2
3
1 5 4
2
100 10000
outputCopy
YES
NO
Note
In the first example, the product of the whole array (20
20
) isn't a perfect square.

In the second example, all subsequences have a perfect square product.
