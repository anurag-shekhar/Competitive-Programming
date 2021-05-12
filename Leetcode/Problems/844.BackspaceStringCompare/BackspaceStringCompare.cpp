/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : BackspaceStringCompare.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        int s_skips = 0;
        int t_skips = 0;
        
        int si = s.size()-1, ti = t.size()-1;
        
        while(si>=0  )
        {
            if(s[si]=='#')
                s_skips++;
            else if(s_skips)
            {
                s[si]='#';
                s_skips--;
            }
                
            
            si--;
        } 
        
        while(ti >=0 )
        {
             if(t[ti]=='#')
                t_skips++;
            else if(t_skips)
            {
                t[ti] = '#';
                t_skips--;
            }
                
            
            ti--;
        }  
        
        si = 0, ti=0;
        
        //cout<<s<<endl<<t<<endl;
        while(si<s.size() && ti<t.size())
        {
            while(si<s.size() && s[si]=='#')
                si++;
            while(ti<t.size() && t[ti]=='#')
                ti++;
            if(si==s.size() || ti==t.size() )
                break;
            
            if( s[si]!=t[ti])
                return false;
            si++;
            ti++;
        }
        while(si<s.size() && s[si]=='#')
                si++;
        while(ti<t.size() && t[ti]=='#')
                ti++;
        
        if(si==s.size() && ti==t.size())
            return true;
        return false;
        
    }
};
