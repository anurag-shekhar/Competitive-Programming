/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : DisjointSetUnion.cpp
 * Created on : Wed May 26 2021
 ****************************************************************
 */

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
