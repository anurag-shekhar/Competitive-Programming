class Solution {
public:
    int getMinSwaps(string num, int k) {
        string original = num;
        while(k--)
            next_permutation(num.begin(), num.end());
        int left = 0;
        int swaps = 0;
        while(left < num.size())
        {
            if(original[left] != num[left])
            {
                int find = left;
                while(original[find] != num[left])
                    find++;
                while(find != left)
                {
                    original[find] = original[find-1];
                    find--;
                    swaps++;
                }
            }
            left++;
        }
        return swaps;
    }
};
