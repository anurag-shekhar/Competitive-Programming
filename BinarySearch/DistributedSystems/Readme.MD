A network consists of nodes labeled 0 to n. You are given n and a list of edges (a, b, t) of an undirected graph, describing the time t it takes for a message to be sent from node a to node b (or vice versa). Whenever a node receives a message, it immediately passes the message on to a neighboring node.

Assuming all nodes are connected, determine how long it will take for every node to receive a message that begins at node 0.

Example 1
Input
n = 3
edges = [
    [0, 1, 2],
    [1, 2, 3],
    [2, 3, 1]
]
Output
6
Explanation
Node 3 receives the message from 0 -> 1 -> 2 -> 3 which takes 2 + 3 + 1 = 6 time.
Example 2
Input
n = 3
edges = [
    [0, 1, 2],
    [0, 2, 3],
    [0, 3, 5]
]
Output
5
Explanation
0 emits the message to all nodes, but node 3 gets it last at time = 5.
