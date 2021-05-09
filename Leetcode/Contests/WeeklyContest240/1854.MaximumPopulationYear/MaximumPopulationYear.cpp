/*
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * Created on Sun May 09 2021
 */

class Solution {
public:
    static bool compare(vector<int> &a, vector<int> &b)
    {
        return a[0] < b[0];
    }
    int maximumPopulation(vector<vector<int>>& logs) {
        
        vector<vector<int> > record;
        for(vector<int> l : logs)
        {
            record.push_back({l[0],0});
            record.push_back({l[1]-1,1});
        }
        sort(record.begin(), record.end());
        int maxCount = 0;
        int count = 0;
        int resYear;
        for(vector<int> a : record)
        {
            //cout<<count<<" "<<a[0]<<endl;
            if(a[1] == 0)
                count++;
            else 
                count--;
            
            if(maxCount < count)
            {
                maxCount = count;
                resYear = a[0];
            }
                
        }
        return resYear;
        
    }
};
