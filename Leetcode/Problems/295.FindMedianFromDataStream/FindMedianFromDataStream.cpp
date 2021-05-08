class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;
    MedianFinder() {
        
    }
    
    void addNum(int val) {
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
    
    double findMedian() {
           if(maxHeap.size() - minHeap.size() == 0)
            return ((double)maxHeap.top() + minHeap.top())/2;
        else 
            return maxHeap.top();    
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
