/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MyCalendarI.cpp
 * Created on : Thu Jun 03 2021
 ****************************************************************
 */

class MyCalendar {
public:
    
    map<int, int> schedule;
    MyCalendar() {
        schedule.clear();
    }
    
    bool book(int s, int e) {
        
        schedule[s]++;
        schedule[e]--;
        
        int currBook=0 ;
        
        for(auto p : schedule)
        {
            currBook += p.second;
            if(currBook == 2)
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
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
