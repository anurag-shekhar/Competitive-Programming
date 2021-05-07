class Solution {
public:
    string minWindow(string s, string t) {
        
        unordered_map<char,int> m;
        unordered_set<char> valid,hold;
        
        for(char i : t)
        {
            valid.insert(i);
            hold.insert(i);
            m[i]++;
        }    
        int left = 0, right = 0;
        
        int end = INT_MAX;
        int start = 0;
        while(right <= s.size())
        {
            if(hold.size()!=0)
            {
                if(right == s.size())
                    break;
                if(valid.find(s[right])!=valid.end())
                {    
                    m[s[right]]--;
                    if(m[s[right]]==0)
                        hold.erase(s[right]);
                }
                right++;
            }
            else
            {
                if(end - start > right-left)
                {
                    start = left;
                    end = right;
                }
                if(valid.find(s[left])!=valid.end())
                {
                    m[s[left]]++;
                    if(m[s[left]] == 1)
                        hold.insert(s[left]);
                }
                left++;
            }
        }
        if(end == INT_MAX)
            return "";
        return s.substr(start,end-start);
        
    }
};
