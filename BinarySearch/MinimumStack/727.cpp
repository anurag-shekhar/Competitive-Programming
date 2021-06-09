/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 727.cpp
 * Created on : Wed Jun 09 2021
 ****************************************************************
 */

class MinimumStack {
    public:
    stack<int> stk, minStack;
    MinimumStack() {
    }

    void append(int val) {
        stk.push(val);
        if(minStack.empty() || minStack.top() >= val)
            minStack.push(val);
    }

    int peek() {
        return stk.top();
    }

    int min() {
        return minStack.top();
    }

    int pop() {
        int val = stk.top();
        stk.pop();
        if(minStack.top()==val)
            minStack.pop();
        return val;
    }
};
