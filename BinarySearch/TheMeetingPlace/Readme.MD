You are given a two dimensional integer matrix consisting of:

0 which represents an empty cell.
1 which represents a wall.
2 which represents a person.
A person can walk up, down, left and right. Find a non-wall cell such that it minimizes the total travel distance each person has to walk to and return the distance.

Note: two people can walk through a same non-wall cell and you can assume there is some path between any two people.

Constraints

n, m ≤ 250 where n and m are the number of rows and columns in matrix
k ≤ 20 where k is the number of people in matrix
Example 1
Input
matrix = [
    [2, 0, 1, 0],
    [1, 0, 1, 2],
    [0, 0, 2, 2]
]
Output
7
Explanation
The best meeting point is in the bottom right corner.
