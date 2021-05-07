B. Binary Removals
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given a string 𝑠, consisting only of characters '0' or '1'. Let |𝑠| be the length of 𝑠.

You are asked to choose some integer 𝑘 (𝑘>0) and find a sequence 𝑎 of length 𝑘 such that:

1≤𝑎1<𝑎2<⋯<𝑎𝑘≤|𝑠|;
��𝑖−1+1<𝑎𝑖 for all 𝑖 from 2 to 𝑘.
The characters at positions 𝑎1,𝑎2,…,𝑎𝑘 are removed, the remaining characters are concatenated without changing the order. So, in other words, the positions in the sequence 𝑎 should not be adjacent.

Let the resulting string be 𝑠′. 𝑠′ is called sorted if for all 𝑖 from 2 to |𝑠′| 𝑠′𝑖−1≤𝑠′𝑖.

Does there exist such a sequence 𝑎 that the resulting string 𝑠′ is sorted?

Input
The first line contains a single integer 𝑡 (1≤𝑡≤1000) — the number of testcases.

Then the descriptions of 𝑡 testcases follow.

The only line of each testcase contains a string 𝑠 (2≤|𝑠|≤100). Each character is either '0' or '1'.

Output
For each testcase print "YES" if there exists a sequence 𝑎 such that removing the characters at positions 𝑎1,𝑎2,…,𝑎𝑘 and concatenating the parts without changing the order produces a sorted string.

Otherwise, print "NO".

You may print every letter in any case you want (so, for example, the strings yEs, yes, Yes and YES are all recognized as positive answer).

Example
inputCopy
5
10101011011
0000
11111
110
1100
outputCopy
YES
YES
YES
YES
NO
Note
In the first testcase you can choose a sequence 𝑎=[1,3,6,9]. Removing the underlined letters from "10101011011" will produce a string "0011111", which is sorted.

In the second and the third testcases the sequences are already sorted.

In the fourth testcase you can choose a sequence 𝑎=[3]. 𝑠′= "11", which is sorted.

In the fifth testcase there is no way to choose a sequence 𝑎 such that 𝑠′ is sorted.
