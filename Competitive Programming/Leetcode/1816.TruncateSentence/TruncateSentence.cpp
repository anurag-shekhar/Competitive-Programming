class Solution {
public:
    string truncateSentence(string s, int k) {
        
        string res = "";
        for(int i = 0; i<s.size() && k; i++)
        {
            string temp="";
            while(i<s.size() && isalpha(s[i]))
            {
                temp += s[i];
                i++;
            }
            res+= temp;
            if(temp.size()!=0)
                k--;
            if(k==0)
                break;
            res += s[i];
        }
        return res;
        
    }
};
