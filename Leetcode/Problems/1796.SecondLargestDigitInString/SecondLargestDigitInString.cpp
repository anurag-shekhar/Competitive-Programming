class Solution {
public:
    int secondHighest(string s) {
        
        int n = s.size();
        vector<bool> v(10,false);
        for(int i = 0; i<n; i++)
        {
            int check = s[i]-'0';
            if(0<=check && check <=9)
                v[check] = true;
        }
        
        for(int i = 9; i>=0; i--)
        {
            if(v[i])
            {
                i--;
                while(i>=0)
                {
                    if(v[i])
                        return i;
                    i--;
                }
                return -1;
            }
        }
        return -1;
        
    }
};
