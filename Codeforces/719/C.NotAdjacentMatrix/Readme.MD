C. Not Adjacent Matrix
time limit per test4 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
We will consider the numbers 𝑎
a
 and 𝑏
b
 as adjacent if they differ by exactly one, that is, |𝑎−𝑏|=1
|
a
−
b
|
=
1
.

We will consider cells of a square matrix 𝑛×𝑛
n
×
n
 as adjacent if they have a common side, that is, for cell (𝑟,𝑐)
(
r
,
c
)
 cells (𝑟,𝑐−1)
(
r
,
c
−
1
)
, (𝑟,𝑐+1)
(
r
,
c
+
1
)
, (𝑟−1,𝑐)
(
r
−
1
,
c
)
 and (𝑟+1,𝑐)
(
r
+
1
,
c
)
 are adjacent to it.

For a given number 𝑛
n
, construct a square matrix 𝑛×𝑛
n
×
n
 such that:

Each integer from 1
1
 to 𝑛2
n
2
 occurs in this matrix exactly once;
If (𝑟1,𝑐1)
(
r
1
,
c
1
)
 and (𝑟2,𝑐2)
(
r
2
,
c
2
)
 are adjacent cells, then the numbers written in them must not be adjacent.
Input
The first line contains one integer 𝑡
t
 (1≤𝑡≤100
1
≤
t
≤
100
). Then 𝑡
t
 test cases follow.

Each test case is characterized by one integer 𝑛
n
 (1≤𝑛≤100
1
≤
n
≤
100
).

Output
For each test case, output:

-1, if the required matrix does not exist;
the required matrix, otherwise (any such matrix if many of them exist).
The matrix should be outputted as 𝑛
n
 lines, where each line contains 𝑛
n
 integers.

Example
inputCopy
3
1
2
3
outputCopy
1
-1
2 9 7
4 6 3
1 8 5
