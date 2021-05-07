class Solution {
public:
    int firstUniqChar(string s) {
        
        unordered_map<char,int> idxMap;
        for(char i : s)
            idxMap[i]++;
    
        for(int i=0; i<s.size(); i++)
        {
            if(1==idxMap[s[i]])
                return i;    
        }
        return -1;
            
    }
};
