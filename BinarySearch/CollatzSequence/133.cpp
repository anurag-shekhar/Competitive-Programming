int solve(int n) {
    vector<int> res;
    int count = 0;
    while(n!=1)
    {
        count++;
        if(n%2)
        {
            n = 3*n+1;
        }
        else 
            n /=2;

    }
    count++;
    return count;
}
