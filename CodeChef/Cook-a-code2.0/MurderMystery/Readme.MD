Feluda is working on a very sensitive murder mystery. Among all evidence, there is a need where he has to decode a particular word. He has already collected the required evidence word E
. If all characters of that evidence word are found in the problem word P
 then the mystery is declared as solved otherwise Feluda will look for more evidence.

Note:
If a character c
 occurs x
 times in E
, then P
 must contains c
 atleast x
 times.
Input:
First-line will contain T
, denoting the number of testcases.
The second line contains a string denoting the evidence word E
.
The third line contains a string denoting the problem word P
.

Note- E
 and P
 contain lowercase english alphabets.

Output:
For each test case print "YES", if the mystery is solved else print "NO" on a separate line without quotes.

Constraints
1≤T≤1000
1≤
 Length of E and P ≤100
Sample Input:
2
apple
bxarlqpccenp
toy
rtuhyydense
Sample Output:
YES
NO
EXPLANATION:
Example case 1: all the characters of apple can be found in the problem word, bxarlqpccenp.

Note:- as there are two 'p' in word apple so problem word must include at least two 'p' in it.

Example case 2: Evidence word contains 3 characters t, o, and y but o is not present in problem word.
