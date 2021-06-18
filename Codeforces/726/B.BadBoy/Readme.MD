B. Bad Boy
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Riley is a very bad boy, but at the same time, he is a yo-yo master. So, he decided to use his yo-yo skills to annoy his friend Anton.

Anton's room can be represented as a grid with 𝑛
n
 rows and 𝑚
m
 columns. Let (𝑖,𝑗)
(
i
,
j
)
 denote the cell in row 𝑖
i
 and column 𝑗
j
. Anton is currently standing at position (𝑖,𝑗)
(
i
,
j
)
 in his room. To annoy Anton, Riley decided to throw exactly two yo-yos in cells of the room (they can be in the same cell).

Because Anton doesn't like yo-yos thrown on the floor, he has to pick up both of them and return back to the initial position. The distance travelled by Anton is the shortest path that goes through the positions of both yo-yos and returns back to (𝑖,𝑗)
(
i
,
j
)
 by travelling only to adjacent by side cells. That is, if he is in cell (𝑥,𝑦)
(
x
,
y
)
 then he can travel to the cells (𝑥+1,𝑦)
(
x
+
1
,
y
)
, (𝑥−1,𝑦)
(
x
−
1
,
y
)
, (𝑥,𝑦+1)
(
x
,
y
+
1
)
 and (𝑥,𝑦−1)
(
x
,
y
−
1
)
 in one step (if a cell with those coordinates exists).

Riley is wondering where he should throw these two yo-yos so that the distance travelled by Anton is maximized. But because he is very busy, he asked you to tell him.

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
) — the number of test cases. Then 𝑡
t
 test cases follow.

The only line of each test case contains four integers 𝑛
n
, 𝑚
m
, 𝑖
i
, 𝑗
j
 (1≤𝑛,𝑚≤109
1
≤
n
,
m
≤
10
9
, 1≤𝑖≤𝑛
1
≤
i
≤
n
, 1≤𝑗≤𝑚
1
≤
j
≤
m
) — the dimensions of the room, and the cell at which Anton is currently standing.

Output
For each test case, print four integers 𝑥1
x
1
, 𝑦1
y
1
, 𝑥2
x
2
, 𝑦2
y
2
 (1≤𝑥1,𝑥2≤𝑛
1
≤
x
1
,
x
2
≤
n
, 1≤𝑦1,𝑦2≤𝑚
1
≤
y
1
,
y
2
≤
m
) — the coordinates of where the two yo-yos should be thrown. They will be thrown at coordinates (𝑥1,𝑦1)
(
x
1
,
y
1
)
 and (𝑥2,𝑦2)
(
x
2
,
y
2
)
.

If there are multiple answers, you may print any.

Example
inputCopy
7
2 3 1 1
4 4 1 2
3 5 2 2
5 1 2 1
3 1 3 1
1 1 1 1
1000000000 1000000000 1000000000 50
outputCopy
1 2 2 3
4 1 4 4
3 1 1 5
5 1 1 1
1 1 2 1
1 1 1 1
50 1 1 1000000000
Note
Here is a visualization of the first test case.

