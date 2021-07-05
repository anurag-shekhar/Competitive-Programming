/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : EmployeeFreeTime.cpp
 * Created on : Mon Jul 05 2021
 ****************************************************************
 */


/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        
        
        map<int, int> timeline;
        for(auto emp : schedule)
        {
            for(auto segment : emp)
            {
                timeline[segment.start]++;
                timeline[segment.end]--;
            }
        }
        
        int person = 0;
        vector<Interval> res;
        for(auto p : timeline)
        {
            person += p.second;
            if(person == 0) 
            {
                Interval I(p.first, 0);
                res.push_back(I);
            }   
            else if(res.size()!=0 && res.back().end == 0)
                res.back().end = p.first;
        }
        
        if(res.size()!=0 && res.back().end == 0)
            res.pop_back();
        return res;
    }
};
