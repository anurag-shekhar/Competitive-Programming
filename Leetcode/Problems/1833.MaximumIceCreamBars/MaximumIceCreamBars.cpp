class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        
        priority_queue<int, vector<int>, greater<int> > minHeap;
        
        for(int a : costs)
            minHeap.push(a);
        int count =0; 
        while(!minHeap.empty())
        {
            int bar = minHeap.top();
            minHeap.pop();
            
            if(coins < bar)
                return count;
            
            count++;
            coins -= bar;
        }
        return count;
    }
};
