There are a bunch of rockets in space lined up in a row.

You are given a list of integers nums representing each rocket's size and direction. If the number is positive it's going right, and if it's negative it's going left. The value of the number represents the rocket's size.

If two rockets collide, the smaller one will disappear and the larger one will continue on its course unchanged. If they are the same size and they collide, they'll both explode (both numbers are removed). If two rockets are moving in the same direction, they will never collide. The rockets start out equally spaced in the given order and all move at the same speed and become harmless after exploding.

Return the state of the rockets after all collisions.

Constraints

n ≤ 100,000 where n is the length of nums
Example 1
Input
nums = [1, 5, 3, -6]
Output
[-6]
Explanation
The last rocket will collide with everything to its left.
Example 2
Input
nums = [1, 5, 3, -6, 7]
Output
[-6, 7]
Explanation
-6 and 7 are going in separate directions, and the -6 rocket will destroy everything to its left.
