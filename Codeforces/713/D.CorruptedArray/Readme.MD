D. Corrupted Array
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given a number 𝑛
n
 and an array 𝑏1,𝑏2,…,𝑏𝑛+2
b
1
,
b
2
,
…
,
b
n
+
2
, obtained according to the following algorithm:

some array 𝑎1,𝑎2,…,𝑎𝑛
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
 was guessed;
array 𝑎
a
 was written to array 𝑏
b
, i.e. 𝑏𝑖=𝑎𝑖
b
i
=
a
i
 (1≤𝑖≤𝑛
1
≤
i
≤
n
);
The (𝑛+1)
(
n
+
1
)
-th element of the array 𝑏
b
 is the sum of the numbers in the array 𝑎
a
, i.e. 𝑏𝑛+1=𝑎1+𝑎2+…+𝑎𝑛
b
n
+
1
=
a
1
+
a
2
+
…
+
a
n
;
The (𝑛+2)
(
n
+
2
)
-th element of the array 𝑏
b
 was written some number 𝑥
x
 (1≤𝑥≤109
1
≤
x
≤
10
9
), i.e. 𝑏𝑛+2=𝑥
b
n
+
2
=
x
; The
array 𝑏
b
 was shuffled.
For example, the array 𝑏=[2,3,7,12,2]
b
=
[
2
,
3
,
7
,
12
,
2
]
 it could be obtained in the following ways:

𝑎=[2,2,3]
a
=
[
2
,
2
,
3
]
 and 𝑥=12
x
=
12
;
𝑎=[3,2,7]
a
=
[
3
,
2
,
7
]
 and 𝑥=2
x
=
2
.
For the given array 𝑏
b
, find any array 𝑎
a
 that could have been guessed initially.

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

The first line of each test case contains a single integer 𝑛
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

The second row of each test case contains 𝑛+2
n
+
2
 integers 𝑏1,𝑏2,…,𝑏𝑛+2
b
1
,
b
2
,
…
,
b
n
+
2
 (1≤𝑏𝑖≤109
1
≤
b
i
≤
10
9
).

It is guaranteed that the sum of 𝑛
n
 over all test cases does not exceed 2⋅105
2
⋅
10
5
.

Output
For each test case, output:

"-1", if the array 𝑏
b
 could not be obtained from any array 𝑎
a
;
𝑛
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
, otherwise.
If there are several arrays of 𝑎
a
, you can output any.

Example
inputCopy
4
3
2 3 7 12 2
4
9 1 7 1 6 5
5
18 2 2 3 2 9 2
3
2 6 9 2 1
outputCopy
2 3 7 
-1
2 2 2 3 9 
1 2 6 
