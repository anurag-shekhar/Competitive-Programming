/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : FindCenterOfStarGraph.cpp
 * Created on : Sun May 23 2021
 ****************************************************************
 */

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        //OBSERVATION : a center node must appear in every edge
	//Another method could be to just count the number of incoming edges and whichever node has the count n-1 thatwill be our answer.        
        if(edges[0][0] ==edges[1][0])
            return edges[0][0];
        if(edges[0][0] == edges[1][1])
            return edges[0][0];
        return edges[0][1];
    }
};
