class Solution {
public:
    bool isValid(string A) {
        
        stack<char> s;
        
        unordered_map<char, char> m;
        m[']'] = '[';
        m['}'] = '{';
        m[')'] = '(';
        for(int i = 0; i<A.size(); i++)
        {
            auto itr = m.find(A[i]);
            if(itr==m.end())
                s.push(A[i]);
            else 
            {
                if(!s.empty() && s.top() == m[A[i]])
                    s.pop();
                else 
                    return false;
            }
        }
        if(s.empty())
            return true;
        return false;
    }
};
