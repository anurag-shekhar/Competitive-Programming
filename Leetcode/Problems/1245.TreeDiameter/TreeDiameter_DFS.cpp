/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : TreeDiameter_DFS.cpp
 * Created on : Fri May 14 2021
 ****************************************************************
 */

class Solution {
public:
    int longestPath(unordered_map<int,vector<int> > &edge, int root, int &res)
    {
        int farthestLeaf = 0;
        int secondFarthestLeaf = 0;
        
        for(int i : edge[root])
        {
            int a = longestPath(edge, i, res);
            if(a > farthestLeaf)
            {
                secondFarthestLeaf = farthestLeaf;
                farthestLeaf = a;
            }
            else if(a > secondFarthestLeaf) 
                secondFarthestLeaf = a;
        }
        
        int temp = 1+farthestLeaf;
        res = max(res, temp + secondFarthestLeaf);
        return temp;
    }
    int treeDiameter(vector<vector<int>>& edges) {
        
        unordered_map<int,vector<int> > edge;   
        for(vector<int> e : edges)
        {
            edge[e[0]].push_back(e[1]);
            //edge[e[1]].push_back(e[0]);
        }
        
        int res = 0;
        longestPath(edge, edges[0][0], res);
        
        return res-1;
    }
};

/*


*/
