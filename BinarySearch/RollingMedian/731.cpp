/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 731.cpp
 * Created on : Sun May 09 2021
 ****************************************************************
 */

class RollingMedian {
    public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;
    RollingMedian() {

    }

    void add(int val) {
        if(maxHeap.empty())
            maxHeap.push(val);
        else if(maxHeap.top() < val)
            minHeap.push(val);
        else 
            maxHeap.push(val);    
        
        if((maxHeap.size() - minHeap.size()) == 2 )
        {
            int popElement = maxHeap.top();
            maxHeap.pop();
            minHeap.push(popElement);
        }
        if((minHeap.size() - maxHeap.size()) ==1)
        {
            int popElement = minHeap.top();
            minHeap.pop();
            maxHeap.push(popElement);
        }
    }

    double median() {
        
        if(maxHeap.size() - minHeap.size() == 0)
            return ((double)maxHeap.top() + minHeap.top())/2;
        else 
            return maxHeap.top();    
    }
};
