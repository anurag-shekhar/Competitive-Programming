

//A = input 
// (l , r) - > query idxs
// ()


/*
0<= l,r <= n-1
0<= tl, tl <= n-1

1 <= idxTree <= 2n+1
*/

(A, 1, 0, n-1)

vector<int> SegTree(2n+2);

void build(vector<int> &A,int v, int tl,int tr)
{
    if(tl==tr)
        SegTree[v] = A[tl];
    else 
    {
        int tm  = (tl + tr)/2;
        build(A, 2*v, tl, tm );
        build(A,2*v+1, tm+1 ,tr ); 
        segTree[v] = segTree[2*v] + segTree[2*v +1];  
    }     
}

int sumQuery(vector<int> &A,int v, int tl, int tr, int l, int r,)
{
    if(r < l)
        return 0;
    if(tl==l && tr == r)
        return segTree[v];
    else 
    {
        int tm = (tl+tr)/2;
        int leftChild = sumQuery(A, 2*v, tl, tm, l, min(tm,r));
        int rightChild = sumQuery(A,2*v+1, tm+1, tr, max(tm+1, l), r);
        return leftchild + rightChild;
    }
}

void update(int v, int tl, int tr, int pos, int val)
{
    if(tl == tr)
        t[v] = val;
    else 
    {
        int tm = (tl + tr)/2;
        if(tm > pos)
            update(2*v, tl, tm, pos, val);
        else 
            update(2*v+1, tm+1, tr, pos, val);

        t[v] = t[2*v] + t[2*v+1];        
    }    
}


