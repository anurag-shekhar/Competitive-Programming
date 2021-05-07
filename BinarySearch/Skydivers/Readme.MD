You are given a list of integers nums where each value represents a group of people looking to skydive together. You are also given k representing the number of days the skydiving facility is open for.

Return the minimum capacity of the plane you need to be able to fulfill all requests in k days. Note that requests should be fulfilled in the order they were given and a plane can only have one flight per day.

Constraints

n ≤ 10,000 where n is the length of nums.
Example 1
Input
nums = [13, 17, 30, 15, 17]
k = 3
Output
32
Explanation
A 32 person airplane can group the requests by [13, 17], [30], [15, 17].
