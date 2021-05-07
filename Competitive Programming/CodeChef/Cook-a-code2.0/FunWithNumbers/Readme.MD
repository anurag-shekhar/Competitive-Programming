You are given a string S
 of length N
 where each character S
i (1≤i≤N
) is either 0
 , 1
 or 2
. You can do the following operations on the string :

Change at most x
 0’s to either 1 or 2
Change at most y
 1’s to either 0 or 2
Change at most z
 2’s to either 0 or 1
You need to find the maximum length of the substring for a given x,y,z
 such that all elements in the substring are equal.
Input:
First-line will contain T
, the number of test cases. Then the test cases follow.
Each test case contains three lines of input.
First line of each test case will contain N
, denoting the length of the given string.
Second line of each test case will contain the string S
.
Third line of each test case will contain three integers x
, y
, and z
.
Output:
For each test case, output the maximum length of the subarray such that all elements are equal in the subarray.

Constraints
1≤T≤100
1≤N≤105

0≤
 x
, y
, z
 ≤N

The Sum of N
 over all test cases does not exceed 106
.

Sample Input:
1
16
0112001102221001
2 3 4
Sample Output:
12
EXPLANATION:
For the first test case, 0112001102221001, the substring S(4,15)
 can be changed to 000000000000. Hence, the answer is 12.
