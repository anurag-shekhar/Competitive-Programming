class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        //s - s1
        //p - s0
        
        unordered_map<char,int> charFreq;
        unordered_set<char> charCheck; 
        for(char c : p)
        {
            charFreq[c]++;
            charCheck.insert(c);
        }

        int k = p.size();
        int n = s.size();
        int count = 0;
        int left = 0, right = 0;
        
        vector<int> res;
        if(n<k)
            return res;
        
        while(right < k)
        {
            if(charCheck.find(s[right]) != charCheck.end())
            {
                charFreq[s[right]]--;
                if(charFreq[s[right]]==0)
                    charFreq.erase(s[right]);
            }
            right++;
        }   
        
        if(charFreq.size()==0)
            res.push_back(left);
        while(right < n)
        {
            if(charCheck.find(s[left]) != charCheck.end())   
            {
                charFreq[s[left]]++; 
                if(charFreq[s[left]]==0)
                    charFreq.erase(s[left]);
            }
            if(charCheck.find(s[right]) != charCheck.end())
            {
                charFreq[s[right]]--;
                if(charFreq[s[right]]==0)
                    charFreq.erase(s[right]);
            }

            left++;
            right++;    
            if(charFreq.size()==0)
                res.push_back(left);
        }
        return res;
    }
};
