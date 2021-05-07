class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        
        int r = mat.size();
        int c = mat[0].size();
        int k = 0;
        int res = 0;
        for(int i = 0; i<r; i++)
            if(res < mat[i][0])
            {
                res = mat[i][0];
                k = i;
            }
        bool flag = 0;
        
        for(int j = 0; j<r; j++)
        {
            int check = mat[k][j];
            flag = true;
            for(int i = 0; i<r; i++)
            {
                if(i!=k)
                {
                    if(!binary_search(mat[i].begin(), mat[i].end(), check))
                    {
                        flag = false;
                        break;
                    }
                    
                }
            }
            if(flag)
                return check;
        }
        return -1;
        
    }
};
