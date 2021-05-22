/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : ShortestWayToFormString.cpp
 * Created on : Sat May 22 2021
 ****************************************************************
 */

class Solution {
public:
    int shortestWay(string source, string target) {
        
        int tSize = target.size();
        int sSize = source.size();
        int j = 0;
        int count = 0;
        for(int i = 0; i<tSize;)
        {
            bool flag = true;
            for(int j = 0; j<sSize; j++)
            {
                if(source[j]==target[i])
                {
                    flag = false;
                    i++;
                }
            }
            if(flag)
                return -1;
            count++;
        }
        return count;
    }
};
