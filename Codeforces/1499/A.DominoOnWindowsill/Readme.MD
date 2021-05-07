A. Domino on Windowsill
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You have a board represented as a grid with 2×𝑛 cells.

The first 𝑘1 cells on the first row and first 𝑘2 cells on the second row are colored in white. All other cells are colored in black.

You have 𝑤 white dominoes (2×1 tiles, both cells are colored in white) and 𝑏 black dominoes (2×1 tiles, both cells are colored in black).

You can place a white domino on the board if both board's cells are white and not occupied by any other domino. In the same way, you can place a black domino if both cells are black and not occupied by any other domino.

Can you place all 𝑤+𝑏 dominoes on the board if you can place dominoes both horizontally and vertically?

Input
The first line contains a single integer 𝑡 (1≤𝑡≤3000) — the number of test cases.

The first line of each test case contains three integers 𝑛, ��1 and 𝑘2 (1≤𝑛≤1000; 0≤𝑘1,𝑘2≤𝑛).

The second line of each test case contains two integers 𝑤 and 𝑏 (0≤𝑤,𝑏≤𝑛).

Output
For each test case, print YES if it's possible to place all 𝑤+𝑏 dominoes on the board and NO, otherwise.

You may print every letter in any case you want (so, for example, the strings yEs, yes, Yes and YES are all recognized as positive answer).

Example
inputCopy
5
1 0 1
1 0
1 1 1
0 0
3 0 0
1 3
4 3 1
2 2
5 4 3
3 1
outputCopy
NO
YES
NO
YES
YES
Note
In the first test case, 𝑛=1, 𝑘1=0 and 𝑘2=1. It means that 2×1 board has black cell (1,1) and white cell (2,1). So, you can't place any white domino, since there is only one white cell.

In the second test case, the board of the same size 2×1, but both cell are white. Since 𝑤=0 and 𝑏=0, so you can place 0+0=0 dominoes on the board.

In the third test case, board 2×3, but fully colored in black (since 𝑘1=𝑘2=0), so you can't place any white domino.

In the fourth test case, cells (1,1), (1,2), (1,3), and (2,1) are white and other cells are black. You can place 2 white dominoes at positions ((1,1),(2,1)) and ((1,2),(1,3)) and 2 black dominoes at positions ((1,4),(2,4)) ((2,2),(2,3)).
