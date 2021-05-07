#define ll long long int
int solve(vector<vector<int>>& matrix) {

    int r = matrix.size();
    if(r==0)
        return 0;
    int c = matrix[0].size();


    int res = 0;
    for(int i = 0; i<r; i++)
    {
        for(int j = 0; j<c; j++)
        {
            if(i && j) 
            {
                int minOf3 = min(matrix[i-1][j],min(matrix[i][j-1],matrix[i-1][j-1]));
                matrix[i][j] = matrix[i][j]*(minOf3+1);
            }        
            res += matrix[i][j];

        }
    }
    return res;

    
    
}
