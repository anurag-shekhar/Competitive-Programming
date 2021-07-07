Given a list of time exclusive intervals for different movie showings (possibly overlapping), find the minimum number of theatres required to be able to show all movies.

Constraints

0 ≤ n ≤ 100,000 where n is the length of `intervals
Example 1
Input
intervals = [
    [30, 75],
    [0, 50],
    [60, 150]
]
Output
2
Explanation
[30, 75] and [0, 50] overlap. [30, 75] and [60, 150] also overlap but later on. So the max number here is 2.
Example 2
Input
intervals = [
    [10, 20],
    [20, 30]
]
Output
1
Explanation
Boundaries are exclusive so these intervals are not considered overlapping.
Example 3
Input
intervals = [
    [0, 1],
    [0, 1],
    [0, 1]
]
Output
3
Explanation
The three intervals happen all at the same time so we need 3.
