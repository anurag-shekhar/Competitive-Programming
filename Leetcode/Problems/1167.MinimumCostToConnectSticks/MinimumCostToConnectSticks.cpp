class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        
        priority_queue<int, vector<int>, greater<int> > minHeap;
        
        for(int s : sticks)
            minHeap.push(s);
        
        int sum = 0;
        while(!minHeap.empty())
        {
            int a = minHeap.top(); minHeap.pop();
            
            if(minHeap.empty())
                return sum;
            int b = minHeap.top(); minHeap.pop();
            
            sum += a+b;
            
            minHeap.push(a+b);
        }
        return sum;
        
    }
};
