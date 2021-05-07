int solve(vector<int>& rooms, int target) {
    

    for(int a : rooms)
    {
        if(a>= target)
            return a;
    }
    return -1;
}
