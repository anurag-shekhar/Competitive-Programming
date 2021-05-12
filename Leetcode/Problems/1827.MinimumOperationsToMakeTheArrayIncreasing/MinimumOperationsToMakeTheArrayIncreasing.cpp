/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MinimumOperationsToMakeTheArrayIncreasing.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */

class Solution {
public:
    int minOperations(vector<int>& A) {
        int res = 0;
        int n = A.size();
        for(int i = 1; i<n; i++)
        {
            int raise = 0;
            if(A[i]<=A[i-1])
                raise = A[i-1] - A[i] + 1;
            A[i] += raise;
            res += raise;
        }
        return res;
        
    }
};

/*
1,5,2,4,1

*/
