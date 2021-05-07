bool solve(vector<int>& pushes, vector<int>& pops) {

        int n = pushes.size();
        int m = pushes.size();
        stack<int> s;
        int i = 0, j =0;

        while(i<n && j<m)
        {
            if(s.empty() || s.top() != pops[j])
                s.push(pushes[i++]);
            else 
            {
                s.pop();
                j++;
            }
        }
        while(j<m)
        {
            if(!s.empty() && s.top() == pops[j])
            {
                s.pop();
                j++;
            }
            else
                break;
        }

        if(i==n && j==m)
            return true;
        return false;    
}
