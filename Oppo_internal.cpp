
class Solution{
    public: 
    int count;
    int helper(TreeNode* root, int parent)
    {
        if(!root)
            return -1;
        int l = helper(root->left, root->val);
        int r = helper(root->right, root->val);

        int val = root->val;
        if(parent != val && l != val && r != val)
            count++;
        return root->val;
    }

    int numberOfSingleNodes(TreeNode* root)
    {
        count = 0;
        helper(root, -1);
        return count;
    }
};




int maximumValue(vector<int> & stones)
{
    int n = stones.size();
    vector<long> dp(n+1, 0);
    dp[n] = 0;

    for(int i = n-1; i>=0; i--)
    {
        int val = stones[i];
        dp[i] = val + dp[i+1];

        if(i+1 < n)
        {
            val = max(val, stones[i+1])
            dp[i] = max(dp[i], val*2 + dp[i+2]);
        }

        if(i+2 < n)
        {
            val = max(val, stones[i+2])
            dp[i] = max(dp[i], val*3 + dp[i+3]);
        }
    } 
    return dp[0];
}


int primeFactors(int val)
{
    int count = 0;
    while(val%2 == 0)
    {
        val /= 2; count++;
    }
    for(int i = 3; i*i <= val; i+=2)
    {
        while(val%i == 0)
        {
            val /= i; count++;
        }
    }
    if(n>2)
        count++;
    return count;
}
vector<int> maximumNumberOfPrimes(int low, int high)
{
    vector<vector<int> > arr;

    for(int i = low; i<=high; i++)
    {
        arr.push_back({i, primeFactors(i)});
    }

    int maxFactor1 = 0, maxFactor2 = 0;

    int element1 = -1, element2 = -1;
    for(int i = 0; i<arr.size(); i++)
    {
        if(arr[i][1] > maxFactor1)
        {
            maxFactor2 = maxFactor1;
            maxFactor1 = arr[i][1];
            element2 = element1;
            element1 = arr[i][0];
        }
        else if(arr[i][1] > maxFactor2)
        {
            maxFactor2 = arr[i][1];
            element2 = arr[i][0];
        }
    }
    return {element1, element2};

}