class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        
        unordered_set<string> banSet;
        unordered_map<string,int> m;
        
        for(string s : banned)
            banSet.insert(s);
        
        for(int i = 0; i<paragraph.size(); i++)
        {
            if(isalpha(paragraph[i]))
                paragraph[i] = tolower(paragraph[i]);
            else 
                 paragraph[i] = ' ';
            
        }
        cout<<paragraph<<endl;
        for(int i = 0; i<paragraph.size(); i++)
        {
            if(isalpha(paragraph[i]))
            {
                string s = "";
                while(i<paragraph.size() && paragraph[i] != ' ')
                {    
                    s+= paragraph[i];
                    i++;
                }    
                if(banSet.find(s)==banSet.end())
                    m[s]++;
            }
        }
        int maxFreq = 0;
        string resString = "";
        for(auto i = m.begin(); i!=m.end(); i++)
            if(maxFreq < i->second)
            {
                resString = i->first;
                maxFreq = i->second;
            }
            
   
        return resString;
        
    }
};
