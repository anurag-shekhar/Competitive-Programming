C. Minimum Grid Path
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Let's say you are standing on the 𝑋𝑌-plane at point (0,0) and you want to reach point (𝑛,𝑛).

You can move only in two directions:

to the right, i. e. horizontally and in the direction that increase your 𝑥 coordinate,
or up, i. e. vertically and in the direction that increase your 𝑦 coordinate.
In other words, your path will have the following structure:

initially, you choose to go to the right or up;
then you go some positive integer distance in the chosen direction (distances can be chosen independently);
after that you change your direction (from right to up, or from up to right) and repeat the process.
You don't like to change your direction too much, so you will make no more than 𝑛−1 direction changes.

As a result, your path will be a polygonal chain from (0,0) to (𝑛,𝑛), consisting of at most 𝑛 line segments where each segment has positive integer length and vertical and horizontal segments alternate.

Not all paths are equal. You have 𝑛 integers 𝑐1,𝑐2,…,𝑐𝑛 where 𝑐𝑖 is the cost of the 𝑖-th segment.

Using these costs we can define the cost of the path as the sum of lengths of the segments of this path multiplied by their cost, i. e. if the path consists of 𝑘 segments (𝑘≤𝑛), then the cost of the path is equal to ∑𝑖=1𝑘𝑐𝑖⋅𝑙𝑒𝑛𝑔𝑡ℎ𝑖 (segments are numbered from 1 to 𝑘 in the order they are in the path).

Find the path of the minimum cost and print its cost.

Input
The first line contains the single integer 𝑡 (1≤𝑡≤1000) — the number of test cases.

The first line of each test case contains the single integer 𝑛 (2≤𝑛≤105).

The second line of each test case contains 𝑛 integers 𝑐1,𝑐2,…,𝑐𝑛 (1≤𝑐𝑖≤109) — the costs of each segment.

It's guaranteed that the total sum of 𝑛 doesn't exceed 105.

Output
For each test case, print the minimum possible cost of the path from (0,0) to (𝑛,𝑛) consisting of at most 𝑛 alternating segments.

Example
inputCopy
3
2
13 88
3
2 3 1
5
4 3 2 1 4
outputCopy
202
13
19
Note
In the first test case, to reach (2,2) you need to make at least one turn, so your path will consist of exactly 2 segments: one horizontal of length 2 and one vertical of length 2. The cost of the path will be equal to 2⋅𝑐1+2⋅𝑐2=26+176=202.

In the second test case, one of the optimal paths consists of 3 segments: the first segment of length 1, the second segment of length 3 and the third segment of length 2.

The cost of the path is 1⋅2+3⋅3+2⋅1=13.

In the third test case, one of the optimal paths consists of 4 segments: the first segment of length 1, the second one — 1, the third one — 4, the fourth one — 4. The cost of the path is 1⋅4+1⋅3+4⋅2+4⋅1=19.
