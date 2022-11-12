/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : FindMedianFromDataStream_clean.cpp
 * Created on : Mon Jul 12 2021
 ****************************************************************
 */

class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, greater<int> > minHeap;
    priority_queue<int> maxHeap;
    MedianFinder() {   
    }
    
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        
        if(minHeap.size() > maxHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size() > minHeap.size())
            return maxHeap.top();
        else return (maxHeap.top() + minHeap.top())/(double)2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
