class Solution {
public:
    
    void backtrack(string &s, vector<string> store, int idx,int bucket, vector<string> &res)
    {
        if(idx == s.size() && bucket == 4)
        {
            string temp = "";
            for(int i = 0; i<4; i++)
            {
                temp += store[i];
                if(i!=3)
                    temp+=".";    
            }
            res.push_back(temp);
            return;
        }
        if(bucket == 4 || idx == s.size())
            return;
        
        string temp = "";
        for(int i = idx; i<s.size(); i++)
        {
            temp += s[i];
            if(stoi(temp) > 255)
                break;
            store[bucket] = temp;
            if(temp.size()==1 || temp.size()>1 && temp[0] != '0')
                backtrack(s,store, i+1, bucket+1, res);
        }
    }
    vector<string> restoreIpAddresses(string s) {
     
        vector<string> store(4);
        vector<string> res;
        backtrack(s, store, 0, 0, res);
        return res;
    }
};
