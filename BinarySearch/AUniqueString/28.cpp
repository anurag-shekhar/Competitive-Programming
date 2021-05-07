bool solve(string s) {
    unordered_map<char,int> m;
    for(char c : s)
    {
        m[c]++;
        if(m[c]==2)
            return false;
            
    }
    return true;
}
