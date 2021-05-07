class Solution {
public:
    int longestValidParentheses(string A) {
        
        stack<int> s;
        s.push(-1);
        int res = 0;
        for(int i = 0; i<A.size(); i++)
        {
            if(A[i] == '(')
                s.push(i);
            else 
            {
                if(s.top()!= -1 && A[s.top()] == '(')
                {
                    s.pop();
                    res  = max(res , i - s.top());
                }
                else 
                    s.push(i);
            }
        }
        return res;
        
    }
};
