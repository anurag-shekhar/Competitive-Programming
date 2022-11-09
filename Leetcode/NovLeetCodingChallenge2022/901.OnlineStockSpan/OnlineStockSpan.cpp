/*
 ***************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 * 
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 * 
 * File Name : OnlineStockSpan.cpp
 * Created on : Wed Nov 09 2022 
 ***************************************************************
 */

class StockSpanner {
public:
    stack<vector<int> > s;
    int count;
    StockSpanner() {
        count = -1;
    }
    
    int next(int price) {
        count++;
        while(!s.empty() && s.top()[0] <= price) {
            s.pop();
        }
        int res;
        if(s.empty())
            res = count + 1;
        else
            res = count - s.top()[1];
        s.push({price, count});
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */