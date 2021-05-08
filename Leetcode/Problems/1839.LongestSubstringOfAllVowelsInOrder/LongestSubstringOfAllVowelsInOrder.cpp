class Solution {
public:
    int longestBeautifulSubstring(string word) {
        
        unordered_map<char, int> m;
        
        m['a'] = 1;
        m['e'] = 2;
        m['i'] = 3;
        m['o'] = 4;
        m['u'] = 5;
        
        stack<char> s;
        int res = 0;
        int n = word.size();
        for(int i = 0; i<n; i++)
        {
            if(s.empty())
            {
                if(m[word[i]]==1)
                    s.push(word[i]);
            }
            else
            {
                int delta = m[word[i]] - m[s.top()];
                if(delta == 1 || delta ==0)
                {
                    s.push(word[i]);
                    if(m[word[i]] == 5)
                    {
                        int size = s.size();
                        res = max(res, size);
                    }
                        
                }
                else 
                {
                    while(!s.empty())
                        s.pop();
                    i--;
                }
            }   
        }
        return res;
    }
};