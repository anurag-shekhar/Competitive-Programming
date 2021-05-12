/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 103.cpp
 * Created on : Thu May 13 2021
 ****************************************************************
 */

int solve(int n) {
    vector<int> A;
    while(n)
    {
        int a = n%10;
        A.push_back(a);
        n /= 10;
    }
    reverse(A.begin(), A.end());
 
    int An = A.size();
    int i = An-2;
    while(i>=0 && A[i] >= A[i+1])
        i--;

    if(i<0)
        sort(A.begin(), A.end());
    else 
    {
        int j = i+1;
        while(j<An && A[i] < A[j])
            j++;
        j--;
        swap(A[i], A[j]);
        sort(A.begin()+i+1, A.end());
    }  

    int res = 0;
    for(i = 0; i<An; i++)
    {
        res = res*10 + A[i];
    }
    return res;
}
