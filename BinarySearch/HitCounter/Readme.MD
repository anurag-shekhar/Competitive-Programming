Implement a hit counter which keeps track of number of the number of hits in the last 60 seconds.

add(int timestamp) which adds timestamp in seconds in the hit counter
count(int timestamp) which returns the number of hits that have been made in the last 60 seconds, given the current time is timestamp.
You can assume that the timestamps passed into add and count are monotonically increasing.

Constraints

n ≤ 100,000 where n is the number of calls that are made to add and count
Example 1
Input
methods = ["constructor", "add", "add", "count", "add", "count"]
arguments = [[], [10], [40], [40], [70], [100]]`
Output
[null, null, null, 2, null, 2]
Explanation
We create a HitCounter
We add timestamp 10 to the data structure
We add timestamp 40 to the data structure
We count the number of timestamps that are within last 60 seconds of 40. There's 10 and 40 so we return 2
We add timestamp 70 to the data structure
We count the number of timestamps that are within last 60 seconds of 100. There's 40 and 70 so we return 2
