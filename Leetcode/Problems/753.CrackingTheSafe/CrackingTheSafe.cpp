/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : CrackingTheSafe.cpp
 * Created on : Sat Jun 19 2021
 ****************************************************************
 */

class Solution {
public:
    unordered_set<string> s;
    string res;
    string dfs(string A, int k, int n)
    {
        
        string local = "";
        for(int i = 0; i<k; i++)
        {
            A+= to_string(i);
            if(!s.count(A))
            {
                s.insert(A);
                dfs(A.substr(1), k, n);
                res += to_string(i);
            }
            A.pop_back();            
        }
            
        return local;
    }
    string crackSafe(int n, int k) {
        s.clear();
        
        string A;
        for(int i = 0; i<n-1 ; i++)
            A+='0';
        dfs(A,k,n);
        res += A;
        return res;
        
        
    }
};

/*

               
            00
        00,0
          00,1
        01,0
      10,0   
          10,1
          
            0
        0,0  
           0,1  01
         1,0  1,1
                 
             
     

            
       
            
        
      
     
*/
