/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 155.cpp
 * Created on : Sun May 09 2021
 ****************************************************************
 */

class compare
{
    public:
    bool operator()(vector<int> &a, vector<int> &b)
    {
        return a[0] > b[0];
    }
};

vector<int> solve(vector<vector<int>>& lists) {

    priority_queue<vector<int>, vector<vector<int>> , compare> minheap;
    for(int i = 0; i<lists.size(); i++)
    {   
        int size = lists[i].size();
        if(size)
            minheap.push({lists[i][0], 0, i, size});
    }
    vector<int> res;
    while(!minheap.empty())
    {
        vector<int> t = minheap.top();
        minheap.pop();
        res.push_back(t[0]);
        t[1]++;
        if(t[1] < t[3])
            minheap.push({lists[t[2]][t[1]], t[1], t[2], t[3]});
    }
    return res;

    
}
