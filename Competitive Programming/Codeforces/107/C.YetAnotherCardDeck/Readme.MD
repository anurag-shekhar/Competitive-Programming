C. Yet Another Card Deck
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You have a card deck of 𝑛
n
 cards, numbered from top to bottom, i. e. the top card has index 1
1
 and bottom card — index 𝑛
n
. Each card has its color: the 𝑖
i
-th card has color 𝑎𝑖
a
i
.

You should process 𝑞
q
 queries. The 𝑗
j
-th query is described by integer 𝑡𝑗
t
j
. For each query you should:

find the highest card in the deck with color 𝑡𝑗
t
j
, i. e. the card with minimum index;
print the position of the card you found;
take the card and place it on top of the deck.
Input
The first line contains two integers 𝑛
n
 and 𝑞
q
 (2≤𝑛≤3⋅105
2
≤
n
≤
3
⋅
10
5
; 1≤𝑞≤3⋅105
1
≤
q
≤
3
⋅
10
5
) — the number of cards in the deck and the number of queries.

The second line contains 𝑛
n
 integers 𝑎1,𝑎2,…,𝑎𝑛
a
1
,
a
2
,
…
,
a
n
 (1≤𝑎𝑖≤50
1
≤
a
i
≤
50
) — the colors of cards.

The third line contains 𝑞
q
 integers 𝑡1,𝑡2,…,𝑡𝑞
t
1
,
t
2
,
…
,
t
q
 (1≤𝑡𝑗≤50
1
≤
t
j
≤
50
) — the query colors. It's guaranteed that queries ask only colors that are present in the deck.

Output
Print 𝑞
q
 integers — the answers for each query.

Example
inputCopy
7 5
2 1 1 4 3 3 1
3 2 1 1 4
outputCopy
5 2 3 1 5 
Note
Description of the sample:

the deck is [2,1,1,4,3⎯⎯,3,1]
[
2
,
1
,
1
,
4
,
3
_
,
3
,
1
]
 and the first card with color 𝑡1=3
t
1
=
3
 has position 5
5
;
the deck is [3,2⎯⎯,1,1,4,3,1]
[
3
,
2
_
,
1
,
1
,
4
,
3
,
1
]
 and the first card with color 𝑡2=2
t
2
=
2
 has position 2
2
;
the deck is [2,3,1⎯⎯,1,4,3,1]
[
2
,
3
,
1
_
,
1
,
4
,
3
,
1
]
 and the first card with color 𝑡3=1
t
3
=
1
 has position 3
3
;
the deck is [1⎯⎯,2,3,1,4,3,1]
[
1
_
,
2
,
3
,
1
,
4
,
3
,
1
]
 and the first card with color 𝑡4=1
t
4
=
1
 has position 1
1
;
the deck is [1,2,3,1,4⎯⎯,3,1]
[
1
,
2
,
3
,
1
,
4
_
,
3
,
1
]
 and the first card with color 𝑡5=4
t
5
=
4
 has position 5
5
.
