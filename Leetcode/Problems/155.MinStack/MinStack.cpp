/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MinStack.cpp
 * Created on : Sat Jun 26 2021
 ****************************************************************
 */

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s;
    stack<int> minS;
    MinStack() {
    }
    
    void push(int val) {
        if(s.empty() || minS.top() >= val)
            minS.push(val);
        s.push(val);
    }
    
    void pop() {
        if(s.top() == minS.top())
            minS.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minS.top();
    }
};

/**
3 4 3 2 1
stk = 3 4 3  
min = 3 
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
