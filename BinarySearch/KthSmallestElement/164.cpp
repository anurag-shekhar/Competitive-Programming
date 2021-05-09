/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 164.cpp
 * Created on : Sun May 09 2021
 ****************************************************************
 */

void swap(vector<int>& nums, int i, int j)
{
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}
int partition(vector<int>& nums, int start, int end)
{
    int pivot = nums[start];

    int i = start+1;
    while(i<=end)
    {
        if(pivot < nums[i])
        {
            swap(nums, i, end);
            end--;
        }
        else 
            i++;
    }
    swap(nums, start, end);
    return end;
}

// 5 2 1 7 8 6
// s   ie
int solve(vector<int>& nums, int k) {

    int left = 0, right = nums.size()-1;

    while(left<=right)
    {
        int pivot = partition(nums, left, right);

        if(pivot == k)
            return nums[pivot];
        else if(pivot < k)
            left = pivot+1;
        else 
            right = pivot-1;        
    }
    return nums[left];



   /* METHOD 2
    priority_queue<int> maxHeap;
    int n = nums.size();
    for(int i = 0; i<n; i++)
    {
        maxHeap.push(nums[i]);
        if(maxHeap.size()>k+1)
            maxHeap.pop();
    }
    return maxHeap.top();
    */
}
