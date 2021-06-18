C. Challenging Cliffs
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are a game designer and want to make an obstacle course. The player will walk from left to right. You have 𝑛
n
 heights of mountains already selected and want to arrange them so that the absolute difference of the heights of the first and last mountains is as small as possible.

In addition, you want to make the game difficult, and since walking uphill or flat is harder than walking downhill, the difficulty of the level will be the number of mountains 𝑖
i
 (1≤𝑖<𝑛
1
≤
i
<
n
) such that ℎ𝑖≤ℎ𝑖+1
h
i
≤
h
i
+
1
 where ℎ𝑖
h
i
 is the height of the 𝑖
i
-th mountain. You don't want to waste any of the mountains you modelled, so you have to use all of them.

From all the arrangements that minimize |ℎ1−ℎ𝑛|
|
h
1
−
h
n
|
, find one that is the most difficult. If there are multiple orders that satisfy these requirements, you may find any.

Input
The first line will contain a single integer 𝑡
t
 (1≤𝑡≤100
1
≤
t
≤
100
) — the number of test cases. Then 𝑡
t
 test cases follow.

The first line of each test case contains a single integer 𝑛
n
 (2≤𝑛≤2⋅105
2
≤
n
≤
2
⋅
10
5
) — the number of mountains.

The second line of each test case contains 𝑛
n
 integers ℎ1,…,ℎ𝑛
h
1
,
…
,
h
n
 (1≤ℎ𝑖≤109
1
≤
h
i
≤
10
9
), where ℎ𝑖
h
i
 is the height of the 𝑖
i
-th mountain.

It is guaranteed that the sum of 𝑛
n
 over all test cases does not exceed 2⋅105
2
⋅
10
5
.

Output
For each test case, output 𝑛
n
 integers — the given heights in an order that maximizes the difficulty score among all orders that minimize |ℎ1−ℎ𝑛|
|
h
1
−
h
n
|
.

If there are multiple orders that satisfy these requirements, you may output any.

Example
inputCopy
2
4
4 2 1 2
2
3 1
outputCopy
2 4 1 2 
1 3
Note
In the first test case:

The player begins at height 2
2
, next going up to height 4
4
 increasing the difficulty by 1
1
. After that he will go down to height 1
1
 and the difficulty doesn't change because he is going downhill. Finally the player will go up to height 2
2
 and the difficulty will increase by 1
1
. The absolute difference between the starting height and the end height is equal to 0
0
 and it's minimal. The difficulty is maximal.

In the second test case:

The player begins at height 1
1
, next going up to height 3
3
 increasing the difficulty by 1
1
. The absolute difference between the starting height and the end height is equal to 2
2
 and it's minimal as they are the only heights. The difficulty is maximal.