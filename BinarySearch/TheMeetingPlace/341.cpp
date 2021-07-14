/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 341.cpp
 * Created on : Wed Jul 14 2021
 ****************************************************************
 */

class person
{
    public:
    int id;
    int x;
    int y; 
    int dist;
    person(int a, int b, int c, int d): id(a), x(b), y(c), dist(d){}
};
int r,c;
bool isValid(int x, int y)
{
    if(x>=0 && x<r && y>=0 && y<c)
        return true;
    return false;
}
int solve(vector<vector<int>>& matrix) {
    
    r = matrix.size();
    c = matrix[0].size();
    vector<vector<int> > cell(r,vector<int> (c,0));
    vector<vector<unordered_set<int> > > visited(r,vector<unordered_set<int> > (c));

    int id = 0;

    queue<person*> q;

    for(int i = 0; i<r; i++)
    {
        for(int j = 0; j<c; j++)
        {
            if(matrix[i][j] == 2)
            {
                q.push(new person(id, i, j, 0));
                visited[i][j].insert(id);
                id++;
            }
                
        }
    }

    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};
    while(!q.empty())
    {
        person* p  = q.front();
        q.pop();

        for(int k = 0; k<4; k++)
        {
            int x = p->x + dx[k];
            int y = p->y + dy[k];

            if(isValid(x,y) && !visited[x][y].count(p->id) && matrix[x][y] != 1)
            {
                q.push(new person(p->id, x, y, p->dist+1));
                cell[x][y] += p->dist+1;
                visited[x][y].insert(p->id);
            }
        }
    }
    int res = INT_MAX;
    for(int i = 0; i<r; i++)
    {
        for(int j = 0; j<c; j++)
        {
            if(visited[i][j].size() == id)
                res = min(res, cell[i][j]);
        }
    }
    return res;
}
