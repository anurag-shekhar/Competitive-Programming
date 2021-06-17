/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 434.cpp
 * Created on : Thu Jun 17 2021
 ****************************************************************
 */

string rotate(string s, int k)
{
    string temp = "";
    for(int i = k; i<s.size(); i++)
        temp += s[i];
    for(int i = 0; i<k; i++)
        temp += s[i];
    return temp;
}
int solve(vector<string>& words) {
    
    unordered_map<string, int> m;
    int group = 0;
    for(int i = 0; i<words.size(); i++)
    {
        if(!m.count(words[i]))
        {
            for(int j = 0; j<words[i].size(); j++)
            {
                m[rotate(words[i], j)] = group;
            }
            group++;
        }
    }
    return group;
}
