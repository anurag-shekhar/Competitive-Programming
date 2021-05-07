You are given an array of integers and k moves. Your target is to maximize the rightmost element of the array. In one move you can choose an index i if a[i]>=2 and then replace a[i] by a[i]-2 and a[i+1] by a[i+1]+2.

Print the maximized value of the rightmost element of the array.

Constraints

Sum of values of n over all the testcases, doesn't exceed 10^6.

1<=t<=100

1<=n<=10^6

1<=k<=10^9

1<=a[i]<=10^9

Input

The first line t the number of testcases. The next line contains two integers n and k respectively. The next line contains n elements of the given array.

Output

Print the Maximized value of the rightmost element of the array.

Sample Input

2

4 2

3 8 1 4

4 5

3 8 1 4

Sample Output

6

8

subtask #1 (40 points)

1<=t<=10

1<=n<=10^3

1<=k<=10^3

subtask #2 (60 points)

original constraints
