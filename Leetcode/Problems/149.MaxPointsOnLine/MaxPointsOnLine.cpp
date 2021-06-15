class Solution {
public:
    int gcd(int a, int b)
    {
        a = abs(a);
        b = abs(b);
        if(b==0)
            return a;
        return gcd(b, a%b);
    }
    int maxPoints(vector<vector<int>>& points) {
        
        int res = 1;
        for(int i = 0; i<points.size(); i++)
        {
            unordered_map<string, int> m;
            for(int j = 0; j<points.size(); j++)
            {
                if(j==i)
                    continue;
                int numerator = points[j][0] - points[i][0];
                int denominator = points[j][1] - points[i][1];
                
                int common = gcd(numerator, denominator);
                
                numerator /= common;
                denominator /= common;
                
                string hash = to_string(numerator) + "/" +  to_string(denominator);
       
                m[hash]++;
                res = max(m[hash]+1, res);
            }
        }
        return res;
    }
};
