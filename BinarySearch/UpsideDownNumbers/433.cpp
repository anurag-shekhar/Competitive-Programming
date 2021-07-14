/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 433.cpp
 * Created on : Wed Jul 14 2021
 ****************************************************************
 */

unordered_map<char, char> m;
bool isUpsideDown(string s)
{
    if(s.size() == 0)
        return false;
    for(char c : s)
    {
        if(c=='#')
            return false;
    }
    return true;
}
void backtrack(vector<string> &res, string local, int left, int right)
{
    if(left > right)
    {
        if(isUpsideDown(local))
            res.push_back(local);
        return;
    }

    for(auto p : m)
    {
        if(p.first == '0' && left == 0 && right!=0)
            continue;

        if(left == right)
        {
            if(p.first != '6' && p.first != '9')
                local[left] = p.first;
        }
        else 
        {
            local[left] = p.first;
            local[right] = p.second;
        }
            
        backtrack(res,local, left+1, right-1);
    }
}
vector<string> solve(int n) {

    m['0'] = '0';
    m['1'] = '1';
    m['6'] = '9';
    m['8'] = '8';
    m['9'] = '6';

    vector<string> res;
    string local;
    for(int i = 0; i<n; i++)
        local+='#';
    backtrack(res, local, 0, n-1);
    sort(res.begin(), res.end());
    return res;
}
