/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : FindTheCelebrity_stack.cpp
 * Created on : Mon May 24 2021
 ****************************************************************
 */


/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int potentialCelebrity(int n)
    {
        stack<int> s;
        for(int i = 0; i<n; i++)
            s.push(i);
        
        while(s.size()!=1)
        {
            int p1 = s.top();
            s.pop();
            int p2 = s.top();
            s.pop();
            
            if(knows(p1,p2))
                s.push(p2);
            else 
                s.push(p1);
        }
        return s.top();
    }
    int findCelebrity(int n) {
        
        int person = potentialCelebrity(n);
        
        if(person == -1)
            return -1;
        
        for(int i = 0; i<n; i++)
        {
            if(person != i)
            {
                if(!knows(i,person) || knows(person, i))
                    return -1;
            }
        }
        return person;
    }
};
