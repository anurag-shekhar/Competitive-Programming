/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : GraphValidTree.cpp
 * Created on : Sat May 29 2021
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

    bool validTree(int n, vector<vector<int>>& edges) {
        
        DSU uf(n);
        
        for(auto e : edges)
        {
            if(uf.find_set(e[0]) != uf.find_set(e[1]))
                uf.union_set(e[0], e[1]);
            else 
                return false;
        }
        int numParents = 0;
        for(int i = 0; i<n; i++)
            if(uf.parent[i] == i)
                numParents++;
        
        return numParents==1;
    }
};
