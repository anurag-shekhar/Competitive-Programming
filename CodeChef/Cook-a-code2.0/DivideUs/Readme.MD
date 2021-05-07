You are given a bitstring S
 . A bitstring is a string consisting only of the characters 0 and 1.

Score for a bitstring Score
 = V
 * X
 ,where V
 is the decimal value of the bitstring when treated as binary and X
 is xor of each element of the bitstring.

For example ,for bitstring 00111
 , V
 = 20
 + 21
 + 22
 =7
 and X
=0
^0
^1
^1
^1
=1
,so Score
 =V
*X
= 7
 *1
=7

You need to find whether it is possible to divide the string into 3 contiguous non-empty segments such that the score of every segment is the same and each character must belong to exactly one segment.

For instance , 100101 can be divided as [1][001][01] but cannot be divided in 3 parts as [1001],[ ],[01] or [1],[00101][ ] because any part cannot be empty.

Input:
First line will contain T
, number of testcases. Then the testcases follow.
Each testcase contains of two lines of input .
First line of each testcase will contain N
 ,length of bitstring.
Second line of each testcase will contain bitstring S
.
Output:
For each testcase, output "Yes" if it possible to divide the string into 3 parts such that no part is empty and score of every part is same. Else print "No".

Constraints
1≤T≤100
3≤N≤105

N
 = Length of bitstring
Sample Input:
2
6
100101
6
100111
Sample Output:
Yes  
No  
EXPLANATION:
For first testcase ,the bit string can be divided as [1][001][01] .
