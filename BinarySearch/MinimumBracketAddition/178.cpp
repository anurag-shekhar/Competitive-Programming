/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 178.cpp
 * Created on : Fri May 14 2021
 ****************************************************************
 */

int solve(string s) {

    int junk = 0;
    int stack = 0;

    for(int i = 0; i<s.size();i++)
    {
        if(s[i]==')')
        {
            if(stack)
                stack--;
            else 
                junk++;    
        }
        else 
            stack++;   
    }
    return stack + junk;
}
