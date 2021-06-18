/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : SentenceSimilarityII.cpp
 * Created on : Sat Jun 19 2021
 ****************************************************************
 */


class Solution {
public:
    class DSU
    {
        public:
        unordered_map<string, int> rank;
        unordered_map<string, string> parent;

        void build(string a)
        {
            parent[a] = a;
            rank[a] = 0;
        }
        void union_set(string a, string b)
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
        string find_set(string a)
        {
            if(parent[a] == a)
                return a;
            return parent[a] = find_set(parent[a]);
        }
    };
    bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        
        int s1 = sentence1.size();
        int s2 = sentence2.size();
        if(s1 != s2)
            return false;
        DSU uf;
        for(auto a : sentence1)
            uf.build(a);
        for(auto a : sentence2)
            uf.build(a);
        
        for(auto v : similarPairs)
            uf.union_set(v[0], v[1]);
        
        for(int i = 0; i<s1; i++)
        {
            if(uf.find_set(sentence1[i]) != uf.find_set(sentence2[i]))
                return false;
        }
        return true;
        
    }
};
