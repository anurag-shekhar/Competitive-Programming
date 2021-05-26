/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : CountServersThatCommunicate_DSU.cpp
 * Created on : Wed May 26 2021
 ****************************************************************
 */

class Solution {
public:
    class DSU
    {
        public:
        vector<int> size;
        vector<int> parent;

        DSU(int capacity)
        {
            size = vector<int> (capacity,1);
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
                if(size[a] < size[b])
                    swap(a,b);
                parent[b] = a;
                size[a]+=size[b];
            }
        }
        int find_set(int a)
        {
            if(parent[a] == a)
                return a;
            return parent[a] = find_set(parent[a]);
        }
    };
    int countServers(vector<vector<int>>& grid) {
           
        int r = grid.size();
        int c = grid[0].size();
        
        
        DSU uf(r*c);

        for(int i = 0; i<r; i++)
        {
            int lastServer = -1;
            for(int j = 0; j<c; j++)
            {
                if(grid[i][j]==1)
                {
                    if(lastServer>=0)
                        uf.union_set(lastServer, i*(c)+j);
                    lastServer = i*(c)+j;
                }
            }
        }
        
        for(int j = 0; j<c; j++)
        {
            int lastServer = -1;
            for(int i = 0; i<r; i++)
            {
                if(grid[i][j]==1)
                {
                    if(lastServer>=0)
                        uf.union_set(lastServer, i*c+j);
                    lastServer = i*(c)+j;
                }
            }
        }

        int count = 0;
        for(int i = 0; i<r*c; i++)
            if(uf.parent[i]==i && uf.size[i]>1)
                count+=uf.size[i];
        return count;
    }
};
