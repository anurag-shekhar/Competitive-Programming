bool solve(int n) {
    int count = 0;
    while(n)
    {
        count += n%2;
        n = n>>1;
    }
    if(count == 1)
        return true;
    return false;    
}
