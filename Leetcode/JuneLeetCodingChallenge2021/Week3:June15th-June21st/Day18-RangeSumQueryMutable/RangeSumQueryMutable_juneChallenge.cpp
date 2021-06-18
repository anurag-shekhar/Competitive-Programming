class NumArray {
public:
    vector<int> tree;
    int n;
    void build(int root, vector<int> &nums, int left, int right)
    {
        if(left==right)
        {
            tree[root] = nums[left];
            return;
        }
        int mid = (left+right)/2;
        build(2*root, nums, left, mid);
        build(2*root+1, nums, mid+1, right);
        tree[root] = tree[2*root] + tree[2*root+1];
    }
    
    void update(int root, int left, int right, int idx, int val)
    {
        if(left == right && left == idx)
        {
            tree[root] = val;
            return;
        }
        int mid = (left+right)/2;
        if(idx <= mid)
            update(2*root, left, mid, idx, val);
        else 
            update(2*root+1, mid+1, right, idx, val);
        
        tree[root] = tree[2*root] + tree[2*root+1];
    }
    int search(int root, int left, int right, int qLeft, int qRight)
    {
        if(qLeft > qRight)
            return 0;
        if(qLeft == left && qRight == right)
        {
            return tree[root];
        }
        int mid = (left+right)/2;
        int leftRes = search(root*2 , left, mid, qLeft, min(mid, qRight));
        int rightRes = search(root*2+1 , mid+1, right, max(mid+1, qLeft), qRight);        
        return leftRes + rightRes;
    }
    NumArray(vector<int>& nums) {
        n = nums.size();
        tree = vector<int> (4*n);
        build(1, nums, 0, n-1);
    }
    
    void update(int index, int val) {
        update(1, 0, n-1, index, val);
    }
    
    int sumRange(int left, int right) {
        return search(1, 0, n-1, left, right);
    }
};
/*

     X 1 3 5 N N N N 
    1 3    5
  1.   3  

*/
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */