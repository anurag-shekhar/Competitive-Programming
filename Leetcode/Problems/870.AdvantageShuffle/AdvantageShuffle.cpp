/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : AdvantageShuffle.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */

class Solution {
public:

    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        
        
        multiset<int> s;
        for(int a : A)
            s.insert(a);
        
        
        auto del = s.begin();
        for(int i = 0; i<B.size(); i++)
        {
            
            del = s.begin();
            auto itr = s.upper_bound(B[i]);
            if(itr!=s.end())
                    del = itr;
            A[i] = *del;
            s.erase(del);
            //cout<<endl;
        }
        //A[A.size()-1] = *s.begin();
        return A;
       
            
    }
};
