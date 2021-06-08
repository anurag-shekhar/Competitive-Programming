/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : PalindromePermutationII.cpp
 * Created on : Tue Jun 08 2021
 ****************************************************************
 */

class Solution {
public:
    vector<string> res;
    string middleEle;
    void backtrack(string nums, int pos)
    {
        int n = nums.size();
        if(pos ==n)
        {
            string l = nums;
            reverse(nums.begin(), nums.end());
            res.push_back(l+middleEle+nums);
            return;
        }
        unordered_set<char> s;
        for(int i = pos; i<n; i++)
        {
            if(s.count(nums[i]))
                continue;
            s.insert(nums[i]);
            swap(nums[i], nums[pos]);
            backtrack(nums, pos+1);
        }
        for(int i = pos+1; i<n; i++)
            swap(nums[i-1], nums[i]);
    }
    vector<string> generatePalindromes(string s) {
        
        vector<int> charMap(26,0);
        res.clear();
        for(char c: s)
            charMap[c-'a']++;
        
        int oddCount = 0;
        middleEle = "";
        for(int i = 0; i<26; i++)
        {    
            if(charMap[i]%2)
            {
                oddCount++;
                middleEle += (i+'a');
            }
        }    
                
        if(oddCount>1)
            return {};
        
        string leftPart = "";
        for(int i = 0; i<26; i++)
        {
            for(int j = 0; j<(charMap[i]/2); j++)
                leftPart += (i+'a');
        }
        backtrack(leftPart, 0);
        return res;
        
    }
};
