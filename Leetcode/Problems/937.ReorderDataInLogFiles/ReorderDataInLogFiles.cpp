/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : ReorderDataInLogFiles.cpp
 * Created on : Mon Aug 16 2021
 ****************************************************************
 */

static bool compare(string &a, string &b)
{
    int i = 0;
    int j = 0;
    while(a[i]!=' ') i++;
    while(b[j]!=' ') j++;
    i++,j++;
    
    if(a.substr(i)==b.substr(j))
       return a.substr(0,i)<b.substr(0,j);
    else
       return a.substr(i)<b.substr(j);
    
}
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        
        vector<string> letter_log,digit_log;
        
        for(int i = 0; i< logs.size(); i++)
        {
            int j = 0;
            while(logs[i][j]!=' ')j++;
            j++;
            int check = logs[i][j]-'0';
            if(0<=check && check<10)
                digit_log.push_back(logs[i]);
            else 
                letter_log.push_back(logs[i]);
        } 
        sort(letter_log.begin(), letter_log.end(), compare);
        int i =0;
        for(int j=0; j<letter_log.size(); j++,i++)
            logs[i] = letter_log[j];
        for(int j=0; j<digit_log.size(); j++,i++)
            logs[i] = digit_log[j];
        return logs;
    }
};
