/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : RangeSumQueryMutable.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */


class NumArray {
public:
    
    int n;
    vector<int> segTree;

    void build(vector<int> &A,int v, int tl,int tr)
    {
        if(tl==tr)
            segTree[v] = A[tl];
        else 
        {
            int tm  = (tl + tr)/2;
            build(A, 2*v, tl, tm );
            build(A,2*v+1, tm+1 ,tr ); 
            segTree[v] = segTree[2*v] + segTree[2*v +1];  
        }     
    }

    int sumQuery(int v, int tl, int tr, int l, int r)
    {
        //cout<<"query :"<<v<<endl;
        if(r < l)
            return 0;
        if(tl==l && tr == r)
            return segTree[v];
      
        {
            int tm  = (tl + tr)/2;
            int leftChild = sumQuery(2*v, tl, tm, l, min(tm,r));
            int rightChild = sumQuery(2*v+1, tm+1, tr, max(tm+1, l), r);
            return leftChild + rightChild;
        }
    }

    void updateTree(int v, int tl, int tr, int pos, int val)
    {
        //cout<<"update :"<<v<<endl;
        if(tl == tr && pos == tl)
            segTree[v] = val;
        else 
        {
            int tm = (tl + tr)/2;
            if(tm >= pos)
                updateTree(2*v, tl, tm, pos, val);
            else 
                updateTree(2*v+1, tm+1, tr, pos, val);

            segTree[v] = segTree[2*v] + segTree[2*v+1];        
        }    
    }
    
    NumArray(vector<int>& nums) {
        
        n = nums.size();
        for(int i = 0 ; i<2*n+2; i++)
            segTree.push_back(0);
        build(nums,1,0,n-1);
    }
    
    void update(int index, int val) {
        
        updateTree(1,0,n-1,index,val);
        
    }
    
    int sumRange(int left, int right) {
        
        return sumQuery(1,0, n-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
