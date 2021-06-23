/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : SentenceScreenFitting.cpp
 * Created on : Wed Jun 23 2021
 ****************************************************************
 */

class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        
        int idx = 0;
        int n = sentence.size();
        int count = 0;
        
        for(int i = 0; i<rows; i++)
        {
            for(int j = 0; j<cols; j++)
            {
                int wordSize = sentence[idx].size();
                
                if(idx==0 && j==0 && i!=0)
                {
                    
                    int times = (rows-i) / (i);
                    i = i+ i*times;
                    count += (times*count);
                }
                if(i>=rows)
                    break;
                if(j+wordSize-1 < cols)
                {
                    j = j+wordSize;
                    idx++;
                    if(idx == n)
                    {
                        count++;
                        idx%=n;
                    }
                }
                else 
                    break;
            }
        }
        return count;
    }
};
