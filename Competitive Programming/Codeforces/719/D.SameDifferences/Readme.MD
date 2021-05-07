D. Same Differences
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given an array 𝑎
a
 of 𝑛
n
 integers. Count the number of pairs of indices (𝑖,𝑗)
(
i
,
j
)
 such that 𝑖<𝑗
i
<
j
 and 𝑎𝑗−𝑎𝑖=𝑗−𝑖
a
j
−
a
i
=
j
−
i
.

Input
The first line contains one integer 𝑡
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

The first line of each test case contains one integer 𝑛
n
 (1≤𝑛≤2⋅105
1
≤
n
≤
2
⋅
10
5
).

The second line of each test case contains 𝑛
n
 integers 𝑎1,𝑎2,…,𝑎𝑛
a
1
,
a
2
,
…
,
a
n
 (1≤𝑎𝑖≤𝑛
1
≤
a
i
≤
n
) — array 𝑎
a
.

It is guaranteed that the sum of 𝑛
n
 over all test cases does not exceed 2⋅105
2
⋅
10
5
.

Output
For each test case output the number of pairs of indices (𝑖,𝑗)
(
i
,
j
)
 such that 𝑖<𝑗
i
<
j
 and 𝑎𝑗−𝑎𝑖=𝑗−𝑖
a
j
−
a
i
=
j
−
i
.

Example
inputCopy
4
6
3 5 1 4 6 6
3
1 2 3
4
1 3 3 4
6
1 6 3 4 5 6
outputCopy
1
3
3
10
