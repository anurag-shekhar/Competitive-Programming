
/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 240.cpp
 * Created on : Fri May 14 2021
 ****************************************************************
 */
int solve(string a, string b) {
    
    unordered_map<char, int> m;
    int check = 0;

    for(int i = 0; i<b.size(); i++)
        m[b[i]]++;

    int left = 0, right = 0;

    int n = a.size();
    int res = INT_MAX;
    while(right <= n)
    {
        if(check != m.size())
        {
            if(right == n)
                break;
            if(m.find(a[right])!=m.end())
            {
                m[a[right]]--;
                if(m[a[right]] == 0)
                    check++; 
            }
            right++;
        }
        else 
        {
            res = min(res, right-left);

            if(m.find(a[left])!=m.end())
            {
                m[a[left]]++;
                if(m[a[left]] == 1)
                    check--; 
            }
             left++;
        }
    }
    if(res == INT_MAX)
        return -1;
    return res;
}
