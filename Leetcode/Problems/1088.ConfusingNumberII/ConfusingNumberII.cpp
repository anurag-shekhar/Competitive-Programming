#define ll long long int
class Solution {
public:
    bool confusingNumber(ll n) {
        
        vector<char> m{'0','1','#','#','#','#','9','#','8','6'};
        string res = "";
        string original = to_string(n);
        for(char c : original)
        {
            if(m[c-'0']=='#')
                return false;
            res += m[c-'0'];
        }
        reverse(res.begin(), res.end());
        return res != original;
    }
    void generate(ll local, int A, vector<int> &valid)
    {
        if(local>A)
            return;
        
        if(confusingNumber(local))
             count++;
        for(int i = 0; i<valid.size(); i++)
        {
            local = local*10 + valid[i];
            generate(local, A, valid);
            local /= 10;
        }
    }
    int count;
    int confusingNumberII(int A) {
        
        vector<int> valid{0,1,6,8,9};
        count = 0;
        for(int v : valid)
            if(v!=0)
                generate(v, A, valid);
        
        return count;
    }
};
