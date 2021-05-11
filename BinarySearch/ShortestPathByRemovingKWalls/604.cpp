/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 604.cpp
 * Created on : Tue May 11 2021
 ****************************************************************
 */

class node
{
    public:
    int x;
    int y;
    int k;
    int steps;
    node(int a, int b, int c,int d): x(a), y(b), k(c), steps(d){}
};

bool isValid(int i, int j, int r, int c)
{
    if(i>=0 && j>=0 && i<r && j<c)
        return true;
    return false;    
}
int solve(vector<vector<int>>& matrix, int k) {

    int r = matrix.size();
    int c = matrix[0].size();

    vector<vector<int> > visited(r,vector<int> (c, -1));

    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,-1,1};


    queue<node*> q;
    q.push(new node(0,0,k, 0)); 
    visited[0][0] = k;

    while(!q.empty())
    {
        node* n = q.front();
        q.pop();
        if(n->k < 0)
            continue;

        if(n->x == r-1 && n->y == c-1 && n->k>=0)
            return n->steps;


        for(int i = 0; i<4; i++)
        {
            int x = n->x + dx[i];
            int y = n->y + dy[i];

            if(isValid(x,y,r,c) && visited[x][y] < n->k-matrix[x][y])
            {
                if(n->k-matrix[x][y] >=0)
                {
                    visited[x][y] = n->k-matrix[x][y];
                    q.push(new node(x,y,n->k-matrix[x][y], n->steps+1));
                }
                
            }
        }     
    }
    return -1;
    
    
}
