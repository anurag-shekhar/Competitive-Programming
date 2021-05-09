/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 738.cpp
 * Created on : Sun May 09 2021
 ****************************************************************
 */

class HitCounter {
    public:
    queue<int> q;
    HitCounter() {
    }

    void add(int timestamp) {
        q.push(timestamp);
    }

    int count(int timestamp) {
        int last60 = timestamp - 60;

        while(!q.empty() && q.front() < last60)
            q.pop();

        return q.size();    
    }
};
