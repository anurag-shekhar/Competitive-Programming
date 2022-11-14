/*
 ***************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 * 
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 * 
 * File Name : MostStonesRemovedWithSameRowOrColumn_DailyChallenge.cpp
 * Created on : Mon Nov 14 2022 
 ***************************************************************
 */

class DSU {
    public:
    map<int ,map<int, vector<int> > > parent;
    map<int, map<int, int> >rank;
    DSU() {

    }
    vector<int> find_set(vector<int> a) {
        if(parent.count(a[0]) && parent[a[0]].count(a[1])) {
            int x = parent[a[0]][a[1]][0];
            int y = parent[a[0]][a[1]][1];
            if(x != a[0] || y != a[1])
                return parent[a[0]][a[1]] = find_set(parent[a[0]][a[1]]);
        }
        return a;
    }
    void union_set(vector<int> a, vector<int> b) {
        a = find_set(a);
        b = find_set(b);
        if(a[0]!=b[0] || a[1] != b[1]) {
            if(rank[a[0]][a[1]] < rank[b[0]][b[1]]) {
                vector<int> temp = b;
                b = a;
                a = temp;
            }
            parent[b[0]][b[1]] = a;
            if(rank[a[0]][a[1]] == rank[b[0]][b[1]])
                rank[a[0]][a[1]]++;
        }
    }
};
class Solution {
public:

    int removeStones(vector<vector<int>>& stones) {
        DSU uf;
        int n = stones.size();

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(i!=j && (stones[i][0] == stones[j][0] || stones[i][1]==stones[j][1]) ) {
                    uf.union_set(stones[i], stones[j]); 
                }
            }
        }
        int count = 0;
        for(vector<int> v : stones) {
            vector<int> p = uf.find_set(v);
            if(p[0] == v[0] && p[1] == v[1])
                count++;
        }
        return n-count;
    }
};