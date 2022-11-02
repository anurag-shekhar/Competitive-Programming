/*
 ***************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 * 
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 * 
 * File Name : MinimumGeneticMutation.cpp
 * Created on : Wed Nov 02 2022 
 ***************************************************************
 */

class Solution {
public:
    bool oneEdit(string A, string B) {
        int n = A.size();
        int count = 0;
        for(int i = 0; i<n; i++) {
            if(A[i]!=B[i])
                count++;
            if(count==2)
                return false; 
        }
        if(count==0)
            return false;
        return true;
    }
    void createGraph(unordered_map<string, vector<string> > &m, string start, vector<string>& bank) {
        
        for(string s : bank) {
            if(oneEdit(start, s))
                m[start].push_back(s); 
        }
        
        for(string gene1 : bank) {
            for(string gene2 : bank) {
                if(oneEdit(gene1, gene2)) {
                    m[gene1].push_back(gene2);
                    m[gene2].push_back(gene1);
                }
            }
        }
    }
    int minMutation(string start, string end, vector<string>& bank) {
        
        unordered_map<string, vector<string> > graph;
        createGraph(graph, start, bank);
        unordered_set<string> visited;
        
        queue<pair<string, int> > q;
        q.push({start, 0});
        visited.insert(start);
        
        while(!q.empty()) {
            pair<string, int> node = q.front();
            q.pop();
            
            if(node.first == end)
                return node.second;
            
            for(string nextNode : graph[node.first]) {
                if(!visited.count(nextNode)) {
                    q.push({nextNode, node.second+1});
                    visited.insert(nextNode);
                }
            }
        }
        return -1;
        
    }
};
