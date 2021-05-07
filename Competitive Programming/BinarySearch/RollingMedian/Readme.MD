Implement a RollingMedian class with the following methods:

add(int val) which adds val to the data structure
median() which retrieves the current median of all numbers added
Median of [1, 2, 3] is 2 whereas median of [1, 2, 3, 4] is 2.5.

Constraints

n ≤ 100,000 where n is the number of calls to add and median
Example 1
Input
methods = ["constructor", "add", "add", "add", "median", "add", "median"]
arguments = [[], [1], [2], [3], [], [4], []]`
Output
[null, null, null, null, 2, null, 2.5]
Explanation
We first add 1, 2, and 3. The median is then 2. Then we add 4. Median is now (2 + 3) / 2 = 2.5
