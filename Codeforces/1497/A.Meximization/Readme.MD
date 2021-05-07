A. Meximization
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given an integer 𝑛 and an array 𝑎1,𝑎2,…,𝑎𝑛. You should reorder the elements of the array 𝑎 in such way that the sum of 𝐌𝐄𝐗 on prefixes (𝑖-th prefix is 𝑎1,𝑎2,…,𝑎𝑖) is maximized.

Formally, you should find an array 𝑏1,𝑏2,…,𝑏𝑛, such that the sets of elements of arrays 𝑎 and 𝑏 are equal (it is equivalent to array 𝑏 can be found as an array 𝑎 with some reordering of its elements) and ∑𝑖=1𝑛𝐌𝐄𝐗(𝑏1,𝑏2,…,𝑏𝑖) is maximized.

𝐌𝐄𝐗 of a set of nonnegative integers is the minimal nonnegative integer such that it is not in the set.

For example, 𝐌𝐄𝐗({1,2,3})=0, 𝐌𝐄𝐗({0,1,2,4,5})=3.

Input
The first line contains a single integer 𝑡 (1≤𝑡≤100)  — the number of test cases.

The first line of each test case contains a single integer 𝑛 (1≤𝑛≤100).

The second line of each test case contains 𝑛 integers 𝑎1,𝑎2,…,𝑎𝑛 (0≤𝑎𝑖≤100).

Output
For each test case print an array 𝑏1,𝑏2,…,𝑏𝑛  — the optimal reordering of 𝑎1,𝑎2,…,𝑎𝑛, so the sum of 𝐌𝐄𝐗 on its prefixes is maximized.

If there exist multiple optimal answers you can find any.

Example
inputCopy
3
7
4 2 0 1 3 3 7
5
2 2 8 6 9
1
0
outputCopy
0 1 2 3 4 7 3 
2 6 8 9 2 
0 
Note
In the first test case in the answer 𝐌𝐄�� for prefixes will be:

𝐌𝐄𝐗({0})=1
𝐌𝐄𝐗({0,1})=2
𝐌𝐄𝐗({0,1,2})=3
𝐌𝐄𝐗({0,1,2,3})=4
𝐌𝐄𝐗({0,1,2,3,4})=5
𝐌𝐄𝐗({0,1,2,3,4,7})=5
𝐌𝐄𝐗({0,1,2,3,4,7,3})=5
The sum of 𝐌𝐄𝐗=1+2+3+4+5+5+5=25. It can be proven, that it is a maximum possible sum of 𝐌𝐄𝐗 on prefixes.
