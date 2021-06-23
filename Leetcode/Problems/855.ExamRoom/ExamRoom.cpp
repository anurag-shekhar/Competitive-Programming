/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : ExamRoom.cpp
 * Created on : Wed Jun 23 2021
 ****************************************************************
 */

class ExamRoom {
public:
    set<int> s;
    int N ;
    ExamRoom(int n) {
        N = n;
        s.clear();
    }
    
    int seat() {
        if(s.size()==0)
        {
            s.insert(0);
            return 0;
        }
        int maxDist = 0;
        int pos = -1;
        int last = -1;
        if(*s.begin() > maxDist)
        {
             pos = 0;
             maxDist = *s.begin();
        }   
        
        for(auto itr = s.begin(); itr!=s.end(); itr++)
        {
            if(last != -1) 
            {
                int diff = *itr - last;
                if(diff/2 > maxDist)
                {
                    pos = diff/2 + last;
                    maxDist = diff/2;
                } 
            }
            last = *itr;
        }
        if((N - 1 - last) > maxDist)
            pos = N-1;
        s.insert(pos);
        return pos;
    }
    
    void leave(int p) {
        s.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
