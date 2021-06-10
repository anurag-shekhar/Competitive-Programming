Given a string s representing characters typed into an editor, with "<-" representing a backspace, return the current state of the editor.

Constraints

n ≤ 100,000 where n is the length of s
Example 1
Input
s = "abc<-z"
Output
"abz"
Explanation
The "c" got deleted by the backspace.
Example 2
Input
s = "<-x<-z<-"
Output
""
Explanation
All characters are deleted. Also note you can type backspace when the editor is empty as well.
