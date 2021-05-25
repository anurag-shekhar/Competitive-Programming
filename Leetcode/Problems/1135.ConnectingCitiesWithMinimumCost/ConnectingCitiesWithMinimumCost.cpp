/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : ConnectingCitiesWithMinimumCost.cpp
 * Created on : Tue May 25 2021
 ****************************************************************
 */


class Solution {
public:
    vector<int> rank,parent;
    void make_set(int a)
    {
        rank[a] = 0;
        parent[a] =a;
    }
    int find_set(int a)
    {
        if(a==parent[a])
            return a;
        return parent[a] = find_set(parent[a]);
    }
    void union_set(int a,int b)
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
        
    static bool compare(vector<int> &a, vector<int> &b)
    {
        return a[2] < b[2];
    }
    int minimumCost(int n, vector<vector<int>>& connections) {
        rank = vector<int> (n+1);
        parent = vector<int> (n+1);
        
        for(int i = 0; i<n+1; i++)
            make_set(i);
        sort(connections.begin(),connections.end(), compare);
        
        int res = 0;
        for(auto edge : connections)
        {
            if(find_set(edge[1]) != find_set(edge[0]))
            {
                res+= edge[2];
                union_set(edge[0], edge[1]);
            }
        }
        int count = 0;
        for(int i = 1; i<parent.size(); i++)
            if(i == parent[i])
                count++;
        if(count>1)
            return -1;
        return res;
        
    }
};
