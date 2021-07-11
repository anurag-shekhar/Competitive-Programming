/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : SumGame.cpp
 * Created on : Sun Jul 11 2021
 ****************************************************************
 */

class Solution {
public:
    bool sumGame(string num) {
        
        int countL= 0, countR = 0;
        int sumL = 0, sumR = 0;
        int n = num.size();
        for(int i = 0, j = n/2; i<n/2; i++, j++)
        {
            if(num[i] =='?')
                countL++;
            else 
                sumL += (num[i]-'0');
            
            if(num[j]=='?')
                countR++;
            else 
                sumR += (num[j]-'0');
        }
        
        if((countL+countR)%2)
            return true;
        
        int minCount = min(countL, countR);
        countL -= minCount;
        countR -= minCount;
        
        int minSum = min(sumL, sumR);
        
        sumL -= minSum;
        sumR -= minSum;
        
        if(sumL == 0 && sumR ==0)
            return false;
        if(sumL > 0 && sumL == (countR/2)*9)
            return false;
        if(sumR > 0 && sumR == (countL/2)*9)
            return false;
        return true;   
    }
};
