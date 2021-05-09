/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 1013.cpp
 * Created on : Sun May 09 2021
 ****************************************************************
 */

class node
{
    public:
    int x;
    int y;
    int size;
    node(int a, int b): x(a),y(b), size(1){}
};

node* Find(unordered_map<int,unordered_map<int, node*> > &parent, node* a)
{
    if(parent.find(a->x)==parent.end())
        return NULL;
    if(parent[a->x].find(a->y)==parent[a->x].end())    
        return NULL;
    if(parent[a->x][a->y] == a)
        return a;

    parent[a->x][a->y] = Find(parent, parent[a->x][a->y]);
    return parent[a->x][a->y];        
}

void Union(unordered_map<int,unordered_map<int, node*> > &parent, node* a, node* b)
{
    a = Find(parent, a);
    b = Find(parent, b);
    if(a!=b)
    {
        if(a->size < b->size)
        {
            parent[b->x][b->y] = a;
            a->size += b->size;
        }
        else 
        {
            parent[a->x][a->y] = b;
            b->size += a->size;
        }
    }
}

vector<node*> getNeighbour(node* a)
{
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    vector<node*> res;
    for(int i=0; i<4; i++)
    {
        node* n = new node(a->x+dx[i], a->y+dy[i]);
        res.push_back(n);
    }
    return res;
}

int solve(int sx, int sy, int ex, int ey, vector<vector<int>>& roads) {
    
    node* origin = new node(sx,sy);
    node* destination = new node(ex,ey);

    int n = roads.size();
    unordered_map<int,unordered_map<int, node*> > parent;
    parent[origin->x][origin->y] = origin;
    parent[destination->x][destination->y] = destination;
    
    //check neighbour of dest  
    vector<node*> neighbour = getNeighbour(destination);   
    for(node* j : neighbour)
    {
        node* c = Find(parent, j);
        if(c==origin)
            return 0;         
    }


    for(int i = 0; i<n ; i++)
    {

        node* road = new node(roads[i][0],roads[i][1]);
        parent[road->x][road->y] = road;
        neighbour = getNeighbour(road);  
        
        for(node* j : neighbour)
        {
            //cout<<"("<<j->x<<","<<j->y<<")"<<endl;
            node* c = Find(parent, j);
            //cout<<c<<endl;

            if(c!=NULL)
                Union(parent, c, road);
        }

        // for(pair<int, unordered_map<int,node*> > pi : parent)
        // {
        //     for(pair<int, node*> p : pi.second)
        //         cout<<"("<<pi.first<<","<<p.first<<") -> ("<<p.second->x<<","<<p.second->y<<")"<<endl;
        // }
        // cout<<"-------------"<<endl;
        
        node* a = Find(parent, origin);
        node* b = Find(parent, destination);
        if(a == b)
            return i+1;


    }
    return -1;
}
