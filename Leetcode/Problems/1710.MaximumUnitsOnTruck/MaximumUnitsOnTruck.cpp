class Solution {
public:
    static bool compare(vector<int> &a, vector<int> &b)
    {
        if(a[1] > b[1])
            return true;
        return false;
    }
    int maximumUnits(vector<vector<int> >& boxTypes, int truckSize) {
        
        sort(boxTypes.begin(), boxTypes.end(), compare);
        int n = boxTypes.size();
        
        int res = 0;
        for(int i = 0; i<n && truckSize; i++)
        {
            if(truckSize >= boxTypes[i][0])
            {
                truckSize -= boxTypes[i][0];
                res += boxTypes[i][0]*boxTypes[i][1];
            }
            else 
            {
                res += truckSize*boxTypes[i][1];  //remaining boxes
                truckSize = 0;
            }
        }
        return res;
    }
};
