A. Review Site
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are an upcoming movie director, and you have just released your first movie. You have also launched a simple review site with two buttons to press — upvote and downvote.

However, the site is not so simple on the inside. There are two servers, each with its separate counts for the upvotes and the downvotes.

𝑛
n
 reviewers enter the site one by one. Each reviewer is one of the following types:

type 1
1
: a reviewer has watched the movie, and they like it — they press the upvote button;
type 2
2
: a reviewer has watched the movie, and they dislike it — they press the downvote button;
type 3
3
: a reviewer hasn't watched the movie — they look at the current number of upvotes and downvotes of the movie on the server they are in and decide what button to press. If there are more downvotes than upvotes, then a reviewer downvotes the movie. Otherwise, they upvote the movie.
Each reviewer votes on the movie exactly once.

Since you have two servers, you can actually manipulate the votes so that your movie gets as many upvotes as possible. When a reviewer enters a site, you know their type, and you can send them either to the first server or to the second one.

What is the maximum total number of upvotes you can gather over both servers if you decide which server to send each reviewer to?

Input
The first line contains a single integer 𝑡
t
 (1≤𝑡≤104
1
≤
t
≤
10
4
) — the number of testcases.

Then the descriptions of 𝑡
t
 testcases follow.

The first line of each testcase contains a single integer 𝑛
n
 (1≤𝑛≤50
1
≤
n
≤
50
) — the number of reviewers.

The second line of each testcase contains 𝑛
n
 integers 𝑟1,𝑟2,…,𝑟𝑛
r
1
,
r
2
,
…
,
r
n
 (1≤𝑟𝑖≤3
1
≤
r
i
≤
3
) — the types of the reviewers in the same order they enter the site.

Output
For each testcase print a single integer — the maximum total number of upvotes you can gather over both servers if you decide which server to send each reviewer to.

Example
inputCopy
4
1
2
3
1 2 3
5
1 1 1 1 1
3
3 3 2
outputCopy
0
2
5
2
Note
In the first testcase of the example you can send the only reviewer to either of the servers — they'll downvote anyway. The movie won't receive any upvotes.

In the second testcase of the example you can send all reviewers to the first server:

the first reviewer upvotes;
the second reviewer downvotes;
the last reviewer sees that the number of downvotes is not greater than the number of upvotes — upvote themselves.
There are two upvotes in total. Alternatevely, you can send the first and the second reviewers to the first server and the last reviewer — to the second server:

the first reviewer upvotes on the first server;
the second reviewer downvotes on the second server;
the last reviewer sees no upvotes or downvotes on the second server — upvote themselves.
