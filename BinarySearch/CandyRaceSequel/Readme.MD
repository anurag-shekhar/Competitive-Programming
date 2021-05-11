You are playing a game with Lawrence. There are several candies arranged in a line, and you are given a list of integers nums representing the point value of each candy.

On each player's turn, they can select 1, 2, or 3 candies from the front of the line, remove them, and get the sum of their points added to their score.

The game ends when all the candies are removed and the person with the higher score is the winner.

Assuming you start first and everyone plays optimally, return whether you can win.

Constraints

n ≤ 100,000 where n is the length of nums
Example 1
Input
nums = [1, 1, 2, 3, 100]
Output
true
Explanation
If you take 1 candy, then Lawrence has to take 1, 2 or 3 candies. In any case, you can take the candy with the value of 100.
Example 2
Input
nums = [5, 5, 5, 5, 5, 5]
Output
false
Explanation
The best you can do is take 3 candies. Then Lawrence also takes 3 candies. The game is tied.
