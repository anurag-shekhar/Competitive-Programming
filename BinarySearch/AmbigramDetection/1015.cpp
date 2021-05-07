bool check(string s, int i , int j)
{
    while(i<=j)
    {
        if(s[i]!=s[j])
            return false;
        i++;
        j--;    
    }
    return true;  
}

int Find(vector<int> &parent, int a)
{
    if(parent[a] == a)
        return a;
    return parent[a] = Find(parent, parent[a]);    
}

void Union(vector<int> &parent, vector<int> &size, int a, int b)
{   
    a = Find(parent,a);
    b = Find(parent,b);   
    if(a!=b)
    {
        if(size[a]<size[b])
            size[b]+=size[a];
        else 
            size[a]+=size[b];        
        parent[a] = b;
    }   
}

bool solve(string s, vector<vector<string>>& pairs) {
    
    int n = s.size();
    vector<int> parent(26),size(26);

    for(int i = 0; i<26; i++)
    {
        parent[i] = i;
        size[i] = 1;
    }
    for(vector<string> p : pairs)
    {
        int a = p[0][0] - 'a';
        int b = p[1][0] - 'a';
        Union(parent,size,a,b); 
    }
    for(int i = 0; i<n; i++)
    {
        
        s[i] = char('a' + Find(parent,s[i]-'a'));
        
    }
    cout<<s<<endl;
    return check(s,0,n-1);

}
