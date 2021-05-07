It’s the time for IPL auction and you have an array of N Players and an integer K i.e the Number of teams. Each player has a base price of A[i] .You are allowed to perform an operation several times.
You can choose any two players let it be I and J (1<=I< j <=n) present in the array which has the same remainder when their base price divided by k and you have to erase data of those two players and append the absolute value of subtraction of their base price( abs(A[i]-A[j]) ) into the array.(Note: The size of the array will decrease by 1 after an operation is performed).
Your task is to find what is the minimum size of the array we can get after performing the operation as many times as you want.

Constraints:
1<=N<=10^5
1<=K<=10^5
1<=A[i]<=10^9

Input Format:
First line of the input contains two integers N and K.
Second line contains N elements A[1],A[2],…A[i].

Output Format:
The minimum size of the array we will get after performing operations.

Example:
Input:
4 3
3 6 9 12

Output:
1

Explanation:
After 1st operation array becomes: 3 6 3

After 2nd operation array becomes: 3 3

After 3rd operation array becomes: 0

No further operations can be done.

Hence the output is 1
