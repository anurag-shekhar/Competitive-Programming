You are given two lists of integers customers and mood, both of them the same length, and an integer k. On each minute i, customers[i] number of people come to the store and if mood[i] = 1, then the customers are happy whereas if mood[i] = 0, then they are unhappy.

Given that you can set a sublist of length k of mood to 1s, return the maximum number of people you can make happy.

Constraints

k ≤ n ≤ 100,000 where n is the length of customers and mood
Example 1
Input
customers = [1, 2, 5, 5, 2]
mood = [1, 1, 0, 0, 0]
k = 2
Output
13
Explanation
If we set mood[2] and mood[3] to 1, then we can make 1 + 2 + 5 + 5 = 13 customers happy.
