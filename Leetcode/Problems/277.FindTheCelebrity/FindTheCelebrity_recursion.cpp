/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : FindTheCelebrity_recursion.cpp
 * Created on : Mon May 24 2021
 ****************************************************************
 */


/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int potentialCelebrity(int n)
    {
        if(n == 0)
            return -1;
        int id = potentialCelebrity(n-1);
        
        if(id == -1 || knows(id , n-1))
            return n-1;
        else if(knows(n-1,id))
            return id;
        return id;
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
