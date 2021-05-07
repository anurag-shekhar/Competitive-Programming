class node
{
    public :
    int id;
    int duration;

    node(int a, int b) : id(a), duration(b){}
};
void bfs(unordered_map<int, vector<pair<int,int> > > &m, vector<int> &time)
{
    queue<node*> q;
    q.push(new node(0,0));

    while(!q.empty())
    {
        node* t = q.front();
        q.pop();

        if(time[t->id] <= t->duration)
            continue;
        else 
        {
            time[t->id] = t->duration;
            for(pair<int,int> p : m[t->id])
                q.push(new node(p.first, t->duration + p.second));

        }       
    }
}

int solve(int n, vector<vector<int>>& edges) {
    vector<int> time(n+1, INT_MAX);
    unordered_map<int, vector<pair<int,int> > >m;

    for(vector<int> a : edges)
    {
        m[a[0]].push_back({a[1], a[2]});
        m[a[1]].push_back({a[0], a[2]});
    }    
    bfs(m, time);

    int res = 0;
    for(int a : time)
        res = max(res , a);

        
    return res;    

    
}
