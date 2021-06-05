/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MaximumPerformanceOfTeam.cpp
 * Created on : Sat Jun 05 2021
 ****************************************************************
 */

#define M 1000000007
class Solution {
public:
    static bool compare(vector<int> &a, vector<int> &b)
    {
        return a[1] > b[1];
    }
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
        
        vector<vector<int> > eff_speed;
        for(int i = 0; i<n; i++)
            eff_speed.push_back({speed[i],efficiency[i]});
        
        sort(eff_speed.begin(), eff_speed.end(), compare);
        
        priority_queue<int, vector<int>, greater<int> > minHeap;
        
        long maxPerf = 0;
        long sum = 0;
        for(auto es : eff_speed)
        {
            int check = -1;
            if(minHeap.size()==k)
            {
                sum -= minHeap.top();
                check = minHeap.top();
                minHeap.pop();

            }   
            
            sum+=es[0];
            minHeap.push(es[0]);
            long perf = (sum * es[1]);
            
            maxPerf = max(maxPerf,perf);
            
            if(check >= es[0])
            {
                minHeap.pop();
                sum -= es[0];
                sum += check;
                minHeap.push(check);
                
            }
        }
        return maxPerf%M;
        
    }
};

/*

f(k,n) = max(f(k-1, n-1),f(k, n-1))

[s1,s2,s3,s4,s5]    =  (s1 + s2 + s3 )*e1
[e1,e2,e3,e4,e5]

*/
