/*
 ***************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 * 
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 * 
 * File Name : FindMedianFromDataStream_DailyChallenge.cpp
 * Created on : Sat Nov 12 2022 
 ***************************************************************
 */

class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;
    MedianFinder() {
        
    }
    /* 1 */
    void addNum(int num) {
        maxHeap.push(num);
        if(maxHeap.top() == num) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        int maxHeapSize = maxHeap.size();
        int minHeapSize = minHeap.size();
        if(maxHeapSize - minHeapSize > 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            minHeapSize++;
            maxHeapSize--;
        }
        if(minHeapSize - maxHeapSize >=1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
            minHeapSize--;
            maxHeapSize++;
        }        
    }
    
    double findMedian() {
        double maxHeapTop = maxHeap.top();
        if(maxHeap.size() == minHeap.size()) {
           double minHeapTop = minHeap.top();
           return (minHeapTop + maxHeapTop)/2.0;
        }
        return maxHeapTop;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */