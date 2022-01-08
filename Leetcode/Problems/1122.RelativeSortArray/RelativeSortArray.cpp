/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : RelativeSortArray.cpp
 * Created on : Sat Jan 08 2022
 ****************************************************************
 */

class Solution {
public:
    
    
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        map<int, int> m;
        for(int i = 0; i<arr1.size(); i++)
        {
            m[arr1[i]]++;
        }
        vector<int> result;
        for(int i = 0; i<arr2.size(); i++)
        {
            while(m[arr2[i]])
            {
                result.push_back(arr2[i]);
                m[arr2[i]]--;
            }
            m.erase(arr2[i]);
        }
        for(pair<int, int> p : m)
        {
            for(int i = 0; i<p.second; i++)
            {
                result.push_back(p.first);
            }
        }
        return result;
    }
};
