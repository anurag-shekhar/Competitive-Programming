Problem Name :
Range GCD
Problem Definition :
Cheetah loves mathematics and solving challenges is something that he never misses.One fine day cheetah comes across a new tricky type of problem.

Each problem consists of multiple subproblems. In each subproblem cheetah is given an array and some queries Each query can one of the following two types:

Update query, where given a range of indices, multiply all number in the range by given number.
Calculate query, where given a range of indices, find the Greatest Common Divisor(GCD) of all the numbers in this range.
Now since cheetah is already busy studying for unit tests, can you solve this problem for him.

Input :
First line contains t, the total number of test cases

First line in each test case contains two integers n and q, denoting the length of the array and number of queries respectively.

The next line consists of n integers a[i]of the array.

The next q lines consists of queries, which can be one of two types denoted in following manner.

Calculate Query

each calculate query will start with integer 1 followed by two integers denoting left index l, right index r denoting the range in which the gcd is to be found

Update Query

each update query will start with integer 2 followed by three integers denoting left index l, right index r and the multiplication value m to be multiplied to each number in the range

Note: Range l to r is inclusive and zero indexed.

Output :
For each query of Calculate (type 1) print the GCD of all the elements in that range on a new line.
Constraints :
0 < t <= 10
0 < n <= 10000
0 < q <= 10000
0 < a[i] <= 1000000
0 <= l <= r < n
0 < m <= 100
Note: final value of each number a[i]after all update queries will be less than 10^18.

Example :
Input :
    1
    5 5
    2 4 8 16 32
    1 1 2
    2 0 1 3
    1 0 1
    2 0 3 5
    1 1 3
Output :
    4
    6
    20
Explanation :
Initially the array is 2 4 8 16 32
The first query is type calculate in range 1 to 2 so gcd of (4,8) which is 4
The second query is type update in range 0 to 1 so new array becomes 6 12 8 16 32
The third query is type calculate in range 0 to 1 so gcd of (6,12) which is 6
The fourth query is type update in range 0 to 3 with 5 so new array becomes 30 60 40 80 32
The fifth query is type calculate in range 1 to 3 so gcd of (60,40,80) which is 20
