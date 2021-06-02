/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MyCalendarIII.cpp
 * Created on : Thu Jun 03 2021
 ****************************************************************
 */

class MyCalendarThree {
public:
    map<int, int> schedule;
    MyCalendarThree() {
        schedule.clear();
    }
    
    int book(int start, int end) {
        
        schedule[start]++;
        schedule[end]--;
        
        int maxBook = 0, currBook = 0;
        
        for(auto p : schedule)
        {
            currBook += p.second;
            maxBook = max(maxBook, currBook);
        }
        return maxBook;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
