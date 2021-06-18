There is a box protected by a password. The password is a sequence of n digits where each digit can be in the range [0, k - 1].

While entering a password, the last n digits entered will automatically be matched against the correct password.

For example, assuming the correct password is "345", if you type "012345", the box will open because the correct password matches the suffix of the entered password.
Return any password of minimum length that is guaranteed to open the box at some point of entering it.

 

Example 1:

Input: n = 1, k = 2
Output: "10"
Explanation: "01" will be accepted too.
Example 2:

Input: n = 2, k = 2
Output: "01100"
Explanation: "01100", "10011", "11001" will be accepted too.
 

Constraints:

1 <= n <= 4
1 <= k <= 10
1 <= kn <= 4096
