bool isValid(vector<int>& piles, int k, int r)
{
    int count = 0;
    int n = piles.size();
    for(int i = 0; i<n; i++)
    {
        count += ceil((double)piles[i]/(double)r);
        if(count > k)
            return false;
    }
    return true;
}
int solve(vector<int>& piles, int k) {

    int n = piles.size();
    int right = accumulate(piles.begin(), piles.end(), 0);
    int left = ceil((double)right/(double)k);

    int res = left;
    while(left<=right)
    {
        int mid = (right-left)/2 + left;

        if(isValid(piles, k, mid))
        {   
            res = mid;
            right = mid-1;
        }
        else 
            left = mid+1;
    }
    return res;
    
}
