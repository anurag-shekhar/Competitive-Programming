After solving programming problems for years, Chef has become lazy and decided to get a better physique by doing some weight lifting exercises.

On any regular day, Chef does N
 exercises at times A1,A2,…,AN
 (in minutes, all distinct) and each exercise provides a tension of B1,B2,…,BN
 units. In the period between two consecutive exercises, his muscles relax R
 units of tension per minute.

More formally, Chef's tension is described by a number x
. Before any workouts, x=0
. When he does a workout at time Ai
, the tension x
 instantly increases by Bi
. Between workouts, the number x
 decreases by R
 units per minute, maximized with 0
.

Considering the time of exercise and hence tension to be negligible, find the maximum tension he will be feeling in his muscles during the entire period of his workout.

Input:
First line will contain T
, number of testcases. Then the testcases follow.
Each testcase contains 3
 lines of input.
The first line will contain 2
 space-separated integers N,R
, number of timestamps at which Chef performs his exercise, and units of tension relaxed per minute.
The second line contains N
 space-separated integers A1,A2,…,AN
.
The third line contains N
 space-separated integers B1,B2,…,BN
.
Output:
For each testcase, output in a single line the maximum amount of tension Chef will have in his muscles.

Constraints
1≤T≤10
1≤N≤5⋅104
1≤R,Bi≤105
1≤Ai≤109
Ai−1<Ai
, for all 2≤i≤N
Sample Input:
3
1 2
10
10
2 2
10 11
10 10
3 1
1 2 3
1 2 3
Sample Output:
10
18
4
Explanation:
Test Case 1: Since there is only 1
 exercise, the maximum tension is equal to the tension provided by that exercise, i.e, 10
 units.

Test Case 2: At time t=10
, Chef has 10
 units of tension.

From t=10
 to t=11
, his muscles releases 2
 unit of tension and at t=11
, he further gains 10
 units of tension to have total of 10−2+10=18
 units of tension.

So the maximum tension Chef feels in his muscles is 18
 units.

Test Case 3: At time t=1
, Chef has 1
 unit of tension.

From t=1
 to t=2
, his muscles releases 1
 unit of tension and at t=2
, he further gains 2
 units of tension to have total of 1−1+2=2
 units of tension.

From t=2
 to t=3
, his muscles releases 1
 unit of tension and at t=3
, he further gains 3
 units of tension to have total of 2−1+3=4
 units of tension.

So the maximum tension Chef feels in his muscles is 4
 units.
