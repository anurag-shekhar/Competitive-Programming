/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : RedundantConnection.cpp
 * Created on : Tue May 25 2021
 ****************************************************************
 */

class Solution {
public:
    
    class DSU
    {
        public:
        vector<int> rank;
        vector<int> parent;
        
        DSU(int capacity)
        {
            rank = vector<int> (capacity,0);
            parent = vector<int> (capacity);
            
            for(int i = 0; i<capacity; i++)
                parent[i] = i;
        }
        void union_set(int a, int b)
        {
            a = find_set(a);
            b = find_set(b);
            if(a!=b)
            {
                if(rank[a] < rank[b])
                    swap(a,b);
                parent[b] = a;
                if(rank[a] == rank[b])
                    rank[a]++;
            }
        }
        int find_set(int a)
        {
            if(parent[a] == a)
                return a;
            return parent[a] = find_set(parent[a]);
        }
    };
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        DSU UF(1001);
        
        vector<int> res;
        
        for(auto e : edges)
        {
            
            if(UF.find_set(e[0]) != UF.find_set(e[1]))
            {
                UF.union_set(e[0],e[1]);
            }
            else 
                res = e;
        }
        return res;
    }
};
