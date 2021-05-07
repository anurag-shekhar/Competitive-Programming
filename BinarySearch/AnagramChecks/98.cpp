bool solve(string s0, string s1) {
    
    unordered_map<char ,int> m;

    for(char c : s0)
        m[c]++;

    for(char c : s1)
    {
        m[c]--;
        if(m[c]==0)
            m.erase(c);
    }

    if(m.size()==0)
        return true;
    return false;    


//---------------------------------
    sort(s0.begin(),s0.end());
    sort(s1.begin(),s1.end());

    return s0==s1;
}
