/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : OptimizeWaterDistributionInVillage.cpp
 * Created on : Mon May 24 2021
 ****************************************************************
 */

class Solution {
public:
    vector<int> parent, rank;
    static bool compare(vector<int> &a, vector<int> &b)
    {
        return a[2]<b[2];
    }
    void make_set(int a)
    {
        rank[a] = 0;
        parent[a] = a;
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
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        
        /*  - Since we have village from 1 to n , treat village0 as Source of water and 
            Digging a well is same as connecting village_i with village_0(water souce). 
            
            - Now add these edges to pipes[] and sort .
            
            - Find MST;
        */
        parent = vector<int> (n+1);
        rank = vector<int> (n+1);
        
        
        for(int i = 1; i<n+1; i++)
        {
            if(i!=0)
                pipes.push_back({0,i,wells[i-1]});
            make_set(i);
        }
        
        int p_size = pipes.size();
        sort(pipes.begin(), pipes.end(), compare);
        
        int res=0;
        for(int i = 0; i<p_size; i++)
        {
            if(find_set(pipes[i][0]) != find_set(pipes[i][1]))
            {
                union_set(pipes[i][0], pipes[i][1]);
                res += pipes[i][2];
            }
        }
        return res;;
    }
};
