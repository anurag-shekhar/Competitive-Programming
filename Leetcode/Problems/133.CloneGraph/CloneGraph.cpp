/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : CloneGraph.cpp
 * Created on : Mon Jun 14 2021
 ****************************************************************
 */


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node* > visited;
    Node* cloneGraph(Node* node) {
        
        if(!node)
            return NULL;
        if(visited.count(node))
            return visited[node];
        Node* newNode = new Node(node->val);
        visited[node] = newNode;
        for(Node* n : node->neighbors)
        {
            newNode->neighbors.push_back(cloneGraph(n));
        }
        return newNode;
    }
};
