bool solve(string s, string t) {

    unordered_set<char> t_char;

    for(char a : t)
        t_char.insert(a);

    if(t_char.size()==26 && s!=t)
        return false;    

    if(s.size() != t.size())
        return false;


    unordered_map<char, char> m;
    int n = s.size();
    for(int i = 0; i<n; i++)
    {
        if(m.find(s[i])!= m.end())
        {
            if(m[s[i]] != t[i])
                return false;
        }
        else 
            m[s[i]] = t[i];
    }
    return true;
}
