/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MyCalendarII.cpp
 * Created on : Thu Jun 03 2021
 ****************************************************************
 */

class MyCalendarTwo {
public:
    map<int,int> schedule;
    MyCalendarTwo() {
        schedule.clear();
    }
    
    bool book(int s, int e) {
       
        
    
        schedule[s]++;
        schedule[e]--;
        
        int currBook=0 ;
        
        for(auto p : schedule)
        {
            currBook += p.second;
            if(currBook == 3)
            {
                schedule[s]--;
                schedule[e]++;
                return false;
            }
                
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
