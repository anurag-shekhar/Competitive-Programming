You are given an array A
 with N
 integers. An array's score is defined as the bitwise AND of all its elements. You need to find the bitwise OR of the scores of all possible non-empty subarrays of A
.

Furthermore, there are Q
 queries. Each query consists of two integers X
 and V
. You need to change the value of the element at index X
 to V
. After each query, you again need to find the bitwise OR of the scores of all possible non-empty subarrays.

See the example for more clarification.

Input:
The first line of the input contains a single integer T
 - the number of test cases. The description of T
 test cases follows.

The first line of each test case contains two space-separated integers N
 and Q
 - the size of the array and the number of queries, respectively.

The second line contains N
 space-separated integers A1,…,AN
.

Each of the next Q
 lines contains two space-separated integers X
 and V
 - the position and the new value of the query, respectively.

Output:
For each test case print Q+1
 lines. In the first line print the answer for the original array and in the next Q
 lines print the answer after every query.

Constraints
1≤T≤100

1≤N,Q≤105

0≤Ai≤231−1

1≤X≤N

0≤V≤231−1

The sum of N
 over all test cases does not exceed 105

The sum of Q
 over all test cases does not exceed 105

Sample Input:
2
3 2
1 2 3
1 4
3 0
4 1
1 2 3 4
4 0
Sample Output:
3
7
6
7
3
EXPLANATION:
Example case 1: For the original array, all possible subarrays and their scores are as follows.

AND(1)=1
, AND(2)=2
, AND(3)=3
, AND(1,2)=0
, AND(1,3)=1
, AND(2,3)=2
, AND(1,2,3)=0
.

The bitwise OR of all possible subarray's score is OR(1,2,3,0,1,2,0)=3
.

After the first query new array will be [4,2,3]
 and the answer will be 7
.

After the second query new array will be [4,2,0]
 and the answer will be 6
.
