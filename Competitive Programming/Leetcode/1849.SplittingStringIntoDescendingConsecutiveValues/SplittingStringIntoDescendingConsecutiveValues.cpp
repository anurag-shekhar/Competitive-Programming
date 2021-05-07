#define ll long long int
class Solution {
public:
    bool backtrack(string &s, int pos, ll prev,int count)
    {
        ll curr = 0;
        int n = s.size();
        if(pos==n)
        {
            if(count>=2)
                return true;
            return false;
        }    
        
        for(int i =pos; i<n; i++)
        {
            if(curr >= LLONG_MAX/10)
                return false;
            curr = curr*10 + (s[i]-'0');
            if(pos!=0 && curr >=prev)
                return false;
            if(pos ==0 || prev - curr == 1)
            {
                if(backtrack(s,i+1, curr, count+1))
                    return true;
            } 
        }
        return false;
    }
    
    bool splitString(string s) {
        
        //return false;
        return backtrack(s,0,0,0);
    }
};
