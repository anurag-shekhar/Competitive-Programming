/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : RemoveOutermostParentheses.cpp
 * Created on : Fri May 28 2021
 ****************************************************************
 */

class Solution {
public:
    string removeOuterParentheses(string A) {
        
        bool open = false;
        int opening = 0;
        string res = "";
        int n = A.size();
        for(int i = 0; i<n; i++)
        {
            if(!open)
                open = true;
            else 
            {
                if(A[i]=='(')
                    opening++;
                else 
                {
                    if(opening==0)
                    {
                        open= false;
                        continue;
                    }
                    opening--;
                        
                }
                res+=A[i];
            }
        }
        return res;
    }
};
/*
(()()) ,  (()) , (()(()))
*/
