/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : UniqueEmailAddresses.cpp
 * Created on : Mon May 24 2021
 ****************************************************************
 */

class Solution {
public:
    string preprocessLocal(string local)
    {
        string res = "";
        for(int i = 0; i<local.size(); i++)
        {
            if(local[i]=='+')
                break;
            if(local[i]=='.')
                continue;
            res+=local[i];
        } 
        return res;
    }
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;
        int n = emails.size();
        for(int i = 0; i<n; i++)
        {
            int j = 0;
            string local = "";
            while(j<emails[i].size() && emails[i][j]!='@') local += emails[i][j++];   
            local = preprocessLocal(local);
            j++;
            string domain = "";
            while(j<emails[i].size() && emails[i][j]!='@') domain += emails[i][j++];  
            
            emails[i] = local + "@" + domain;
            s.insert(emails[i]);
        }
        return s.size();
        
    }
};
