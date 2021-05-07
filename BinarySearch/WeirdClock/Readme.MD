Given a string s representing a 24-hour time represented in the format "hh:mm", return the next closest time that can be made by reusing digits. You may reuse digits from the input as many times as you like.

Example 1
Input
s = "04:26"
Output
"04:40"
Example 2
Input
s = "23:59"
Output
"22:22"
Explanation
We wrap around to the next day to "22:22". Note that we don't pick "23:55" since it's not the next closest time.
Example 3
Input
s = "11:11"
Output
"11:11"
Explanation
We wrap around 24 hours
Example 4
Input
s = "12:22"
Output
"21:11"
