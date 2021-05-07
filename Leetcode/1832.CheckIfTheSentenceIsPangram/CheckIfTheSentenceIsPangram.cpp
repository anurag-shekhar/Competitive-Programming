class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> s;
        for(char ch : sentence)
        {
           s.insert(ch); 
        }
        if(s.size()==26)
            return true;
        return false;
    }
};
