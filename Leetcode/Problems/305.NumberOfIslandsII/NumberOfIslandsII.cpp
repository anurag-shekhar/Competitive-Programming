/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : NumberOfIslandsII.cpp
 * Created on : Wed Jun 23 2021
 ****************************************************************
 */

class Solution {
public:
    bool isValid(int x, int y, int r, int c)
    {
        if(x>=0 && y>=0 && x<r && y<c)
            return true;
        return false;
    }
    int island = 0;
    class DSU
    {
        public:
        vector<int> parent;
        vector<int> rank;
        DSU(int n)
        {
            rank = vector<int> (n, 0);
            parent = vector<int> (n, -1);
        }
        void make_set(int a)
        {
            parent[a] = a;
        }
        int find_set(int a)
        {
            if(parent[a] == -1)
                return -1;
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
                    swap(a,b);
                parent[b] = a;
                if(rank[a]==rank[b])
                    rank[a]++;
            }
        }
    };
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        
        DSU uf(m*n);
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,1,-1};
        vector<int> res;
        for(auto p : positions)
        {
            int A = uf.find_set(p[0]*n + p[1]);
            if(A==-1)
            {
                uf.make_set(p[0]*n + p[1]);
                island++;
            
                for(int k = 0; k<4; k++)
                {
                    int x = p[0]+dx[k];
                    int y = p[1] + dy[k];
                    
                    if(isValid(x,y,m,n))
                    {
                        int B = uf.find_set(x*n+y);
                        A = uf.find_set(p[0]*n + p[1]);
                        if(B!=-1 && B != A)
                        {
                            uf.union_set(x*n+y, p[0]*n + p[1]);
                            island--;
                        }   
                    }
                }
            }
            res.push_back(island);
        }
        return res;
    }
};
