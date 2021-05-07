int solve(vector<vector<int>>& matrix) {
    
    int n = matrix.size();
    int k = matrix[0].size();
    int firstMin = INT_MAX, secondMin = INT_MAX;


    int res = INT_MAX;
    for(int i = 0; i<n; i++)
    {
        firstMin = INT_MAX;
        secondMin = INT_MAX;
        for(int j = 0; j<k; j++)
        {
            if(i!=0)
                matrix[i][j] += matrix[i-1][j];
            if(matrix[i][j] < firstMin)
            {
                secondMin = firstMin;
                firstMin = matrix[i][j];
            }
            else if(matrix[i][j] < secondMin)
                secondMin = matrix[i][j];
            if(i==(n-1))
                res = min(res, firstMin);  
        }
        for(int j = 0; j<k; j++)
        {
            if(matrix[i][j] == firstMin)
                matrix[i][j] = secondMin;
            else 
                matrix[i][j] = firstMin;   
        }   
        cout<<endl;        
    }
    return res;
}
