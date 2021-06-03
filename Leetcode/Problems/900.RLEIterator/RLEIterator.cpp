/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : RLEIterator.cpp
 * Created on : Thu Jun 03 2021
 ****************************************************************
 */

class RLEIterator {
public:
    vector<int> enc;
    int idx;
    RLEIterator(vector<int>& encoding) {
        enc = encoding;
        idx = 0;
    }
    
    int next(int n) {
        
        int res = -1;
        while(n && idx<enc.size())
        {
            if(n>=enc[idx])
            {
                n-=enc[idx];
                res = enc[idx+1];
                idx+=2;
            }
            else 
            {
                enc[idx] -= n;
                res = enc[idx+1];
                n=0;
            }
        }
        if(idx>=enc.size() && n)
            return -1;
        return res;
        
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */
