/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 418.cpp
 * Created on : Sun May 09 2021
 ****************************************************************
 */

int solve(string s0, string s1) {
    unordered_map<char,int> charFreq;
    unordered_set<char> charCheck; 
    for(char c : s0)
    {
        charFreq[c]++;
        charCheck.insert(c);
    }
        
    int k = s0.size();
    int n = s1.size();
    int count = 0;
    int left = 0, right = 0;

    if(n<k)
        return 0;

    while(right < k)
    {
        if(charCheck.find(s1[right]) != charCheck.end())
        {
            charFreq[s1[right]]--;
            if(charFreq[s1[right]]==0)
                charFreq.erase(s1[right]);
        }
        right++;
    }   
    
    if(charFreq.size()==0)
        count++;
    while(right < n)
    {
        if(charCheck.find(s1[left]) != charCheck.end())   
        {
            charFreq[s1[left]]++; 
            if(charFreq[s1[left]]==0)
                charFreq.erase(s1[left]);
        }
        if(charCheck.find(s1[right]) != charCheck.end())
        {
            charFreq[s1[right]]--;
            if(charFreq[s1[right]]==0)
                charFreq.erase(s1[right]);
        }
        
        if(charFreq.size()==0)
            count++;
        left++;
        right++;    
    }
    return count;

}
/*

aab
^^
*/
