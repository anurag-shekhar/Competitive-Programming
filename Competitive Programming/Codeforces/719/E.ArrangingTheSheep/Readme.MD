E. Arranging The Sheep
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are playing the game "Arranging The Sheep". The goal of this game is to make the sheep line up. The level in the game is described by a string of length 𝑛
n
, consisting of the characters '.' (empty space) and '*' (sheep). In one move, you can move any sheep one square to the left or one square to the right, if the corresponding square exists and is empty. The game ends as soon as the sheep are lined up, that is, there should be no empty cells between any sheep.

For example, if 𝑛=6
n
=
6
 and the level is described by the string "**.*..", then the following game scenario is possible:

the sheep at the 4
4
 position moves to the right, the state of the level: "**..*.";
the sheep at the 2
2
 position moves to the right, the state of the level: "*.*.*.";
the sheep at the 1
1
 position moves to the right, the state of the level: ".**.*.";
the sheep at the 3
3
 position moves to the right, the state of the level: ".*.**.";
the sheep at the 2
2
 position moves to the right, the state of the level: "..***.";
the sheep are lined up and the game ends.
For a given level, determine the minimum number of moves you need to make to complete the level.

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
 (1≤𝑛≤106
1
≤
n
≤
10
6
).

The second line of each test case contains a string of length 𝑛
n
, consisting of the characters '.' (empty space) and '*' (sheep) — the description of the level.

It is guaranteed that the sum of 𝑛
n
 over all test cases does not exceed 106
10
6
.

Output
For each test case output the minimum number of moves you need to make to complete the level.

Example
inputCopy
5
6
**.*..
5
*****
3
.*.
3
...
10
*.*...*.**
outputCopy
1
0
0
0
9