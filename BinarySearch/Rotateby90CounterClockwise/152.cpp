vector<vector<int>> solve(vector<vector<int>>& matrix) {

    int n = matrix.size();
    for(int i = 0; i<=n/2; i++)
    {
        for(int j = i; j<= (n-i-2); j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][n-i-1];
            matrix[j][n-i-1] = matrix[n-i-1][n-j-1];
            matrix[n-i-1][n-j-1] = matrix[n-j-1][i];
            matrix[n-j-1][i] = temp;

        }
    }
    return matrix;
    
}

/*
(0,1) <- (1,2) 

*/
