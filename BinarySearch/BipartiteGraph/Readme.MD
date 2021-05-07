Given an undirected graph represented as an adjacency list, return whether the graph is bipartite.

Constraints

n, m ≤ 250 where n and m are the number of rows and columns in graph
Example 1
Input
Visualize

graph = [
    [1],
    [0]
]
Output
true
Explanation
This is bipartite since the node 1 can belong in set A and node 2 can belong in set B. Then the edges 0 -> 1 and 1 -> 0 has one node in A and one node in B
Example 2
Input
Visualize

graph = [
    [2, 3],
    [2, 3],
    [0, 1],
    [0, 1]
]
Output
true
Explanation
0 and 1 can belong in set A and 2 and 3 can belong in set B.
Example 3
Input
Visualize

graph = [
    [1, 2, 3],
    [0, 2],
    [0, 1, 3],
    [0, 2]
]
Output
false
Explanation
No matter how the nodes are partitioned, an edge will belong to the same set.
