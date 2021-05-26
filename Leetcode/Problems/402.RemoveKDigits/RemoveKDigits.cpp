class Solution {
public:
    string removeKdigits(string num, int k) {
        
        string res = "";
        stack<char> s;
        int n = num.size();
        for(int i = 0;i<n; i++)
        {
           while(k && !s.empty() && s.top() > num[i])
           {
               s.pop();
               k--;
           }
            s.push(num[i]);
        }
        
        while(!s.empty())
        {
            res+=s.top();
            s.pop();
        }
        reverse(res.begin(),res.end());
        res = res.substr(0,res.size()-k);
        int i = 0;
        while(i<res.size() && res[i]=='0')i++;
        res = res.substr(i,res.size());
        if(res=="")
            return "0";

        return res;
        
        
    }
};

/*


k=3
12456789
987654321
*/
