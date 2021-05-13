/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : SeatReservationManager.cpp
 * Created on : Thu May 13 2021
 ****************************************************************
 */

class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int> > minHeap;
    SeatManager(int n) {
        for(int i = 1; i<=n; i++)
            minHeap.push(i);
            
    }
    
    int reserve() {
        
        int seat = minHeap.top();
        minHeap.pop();
        return seat;
    }
    
    void unreserve(int seatNumber) {
        minHeap.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
