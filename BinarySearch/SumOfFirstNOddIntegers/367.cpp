int solve(int n) {
    
    int num = 1;
    int sum = 0;
    for(int i = 0; i<n; i++)
    {
        sum += num;
        num+=2;
    }
    return sum;
}
