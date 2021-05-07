Minimum AND xor OR
Given an array 
A
 of 
N
 integers. Find out the minimum value of the following expression for all valid 
i
,
j
.


(
A
i
 
a
n
d
 
A
j
)
 
x
o
r
 
(
A
i
 
o
r
 
A
j
)
, where 
i
≠
j
.

Input format

First line: A single integer 
T
 denoting the number of test cases
For each test case:
First line contains a single integer 
N
, denoting the size of the array.
Second line contains 
N
 space separated integers 
A
1
,
A
2
,
.
.
.
,
A
n
Output format

For each test case, print a single line containing one integer that represents the minimum value of the given expression

Constraints


1
≤
T
≤
10
3
1
≤
N
≤
10
5
0
≤
A
i
≤
10
9

Note: Sum of 
N
 overall test cases does not exceed 
10
6

Sample Input
2
5
1 2 3 4 5
3
2 4 7

Sample Output
1
3

Explanation
For test case #1, we can select elements 
2
 and 
3
, the value of the expression is 
(
2
 
a
n
d
 
3
)
 
x
o
r
 
(
2
 
o
r
 
3
)
=
1
, which is the minimum possible value. Another possible pair is 4 and 5.

For test case #2, we can select elements 4 and 7, the value of the expression is 
(
4
 
a
n
d
 
7
)
 
x
o
r
 
(
4
 
o
r
 
7
)
=
3
, which is the minimum possible value.
