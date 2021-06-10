/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 194.cpp
 * Created on : Thu Jun 10 2021
 ****************************************************************
 */

string solve(string s) {
    
    int n = s.size();
    string res = "";
    for(int i = 0; i<n; i++)
    {   
        if(s[i] =='<' && i+1<n && s[i+1]=='-')
        {
            if(res!="")
                res.pop_back();
            i++;
        }
        else 
            res.push_back(s[i]);

    }
    return res;
}
