int solve(int n) {
    
    int run = 0;
    int maxRun = 0;

    while(n)
    {
        if(n%2)
        {
            run++;
            maxRun = max(maxRun, run);
        }
        else 
        {
            run = 0;
        }
        n = n>>1;
    }
    return maxRun;
}
