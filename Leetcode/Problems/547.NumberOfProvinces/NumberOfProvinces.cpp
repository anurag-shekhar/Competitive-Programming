/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : NumberOfProvinces.cpp
 * Created on : Wed Jul 28 2021
 ****************************************************************
 */

class Solution {
public:
    
    class DSU
    {
        public: 
        vector<int> parent, rank;
        
        DSU(int n)
        {
            parent = vector<int> (n,0);
            rank = vector<int> (n,0);
            for(int i = 0; i<n; i++)
                parent[i] = i;
        }
        
        
        int find_set(int a)
        {
            if(parent[a] == a)
                return a;
            return parent[a] = find_set(parent[a]);
        }
        void union_set(int a, int b)
        {
            a = find_set(a);
            b = find_set(b);
            
            if(a!=b)
            {
                if(rank[a] < rank[b])
                    swap(a, b );
                parent[b] = a;
                if(rank[a] == rank[b])
                    rank[a]++;
            }
        }
    };
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        
        DSU uf(n);
        
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(isConnected[i][j] == 1 && uf.find_set(i) != uf.find_set(j))
                {
                    uf.union_set(i,j);
                }
            }
        }
        int count = 0;
        for(int i = 0; i<uf.parent.size(); i++)
            if(uf.parent[i]==i)
                count++;
        return count;
            
    }
};
