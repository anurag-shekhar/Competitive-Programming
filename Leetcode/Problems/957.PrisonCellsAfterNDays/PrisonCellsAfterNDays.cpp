class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        
        vector<vector<int> > res(14);
        
        for(int i = 1; i<15; i++)
        {
            vector<int> v(8);
            for(int j = 1; j<=6; j++)
            {
                if(i==1)
                {
                    if(cells[j-1] == cells[j+1])
                        v[j] = 1;
                    else
                        v[j] = 0;
                }
                else
                {
                    if(res[i-1][j-1] == res[i-1][j+1])
                        v[j] = 1;
                    else
                        v[j] = 0;
                } 
            }      
            v[0] = 0;
            v[7] = 0;
            res[i%14] = v;
        }
        // for(vector<int> v : res)
        // {
        //     for(int a : v)
        //         cout<<a<<" ";
        //     cout<<endl;
        // }
        return res[n%14];
    }
};
