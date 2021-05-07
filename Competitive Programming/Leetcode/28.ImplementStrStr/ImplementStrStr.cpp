class Solution {
public:

    int strStr(string haystack, string needle) {
        
        if(needle.size()==0)
            return 0;
        
        string s = needle+"#"+haystack;
        int n = s.size();
        
        vector<int> pi(n);
        pi[0] = 0;
        
        for(int i = 1; i<n; i++)
        {
            int j = pi[i-1];
            while(j>0 && s[i] != s[j])
                j = pi[j-1];
            if(s[i]==s[j])
                j++;
            pi[i] = j;
            
            if(i>needle.size() && pi[i]==needle.size())
                return (i-2*needle.size());
        }
        return -1;
        
    }
};
