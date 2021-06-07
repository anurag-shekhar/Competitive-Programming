/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : TimeBasedKeyValueStore.cpp
 * Created on : Tue Jun 08 2021
 ****************************************************************
 */

class TimeMap {
public:
    /** Initialize your data structure here. */
    unordered_map<string, unordered_map<int, string> > keyTime_value;
    unordered_map<string, vector<int> > key_time;
    
    TimeMap() {
        keyTime_value.clear();
        key_time.clear();
    }
    
    void set(string key, string value, int timestamp) {
        
        key_time[key].push_back(timestamp);
        keyTime_value[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        
        if(!key_time.count(key))
            return "";
        
        auto itr = lower_bound(key_time[key].begin(),key_time[key].end(), timestamp);
        
        if(itr == key_time[key].end() || *itr > timestamp)
        {
            if(itr == key_time[key].begin())
            {
                if(*itr == timestamp)
                    return keyTime_value[key][*itr];
                else 
                    return "";
            }
            itr = prev(itr);  
        }    

        return keyTime_value[key][*itr];
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
