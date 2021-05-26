/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : DisjointSetUnion_size.cpp
 * Created on : Wed May 26 2021
 ****************************************************************
 */

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