class Solution {
public:
    void stringBuilder(vector<string>& words, int start, int k, vector<string> &res)
    {   

        if(words.size()==start)
            return;
        int i;
        int wordSize = 0;
        int wordCount = 0;
        int spaces = 0; 
        for(i = start; i<words.size(); i++)
        {
            if(i-start)
                spaces += 1;
            if((wordSize + spaces + words[i].size()) <=k)    
                wordSize += words[i].size(); 
            else 
                break;       
            wordCount++;    
        }
        spaces = (k - wordSize);
        int extraSpaces = 0;
        int mandatorySpaces = spaces;
        if(wordCount>1)
        {   
            extraSpaces = spaces%(wordCount-1);
            mandatorySpaces = spaces/(wordCount-1); 
        }

        string tempStr = "";
        if(i==words.size())
        {
            mandatorySpaces = min(1,spaces);
            extraSpaces = 0;
        }
            
        for(int j = start; j<i-1; j++)
        {
            tempStr += words[j];
            int ms = mandatorySpaces;
            while(ms--)
                tempStr += " ";
            if(extraSpaces)
            {
                tempStr += " ";
                extraSpaces--;
            }    
        }
        tempStr += words[i-1];
        if(wordCount==1)
        {
            int ms = mandatorySpaces;
            while(ms)
            {
                tempStr += " ";
                ms--;
            }
                
        }
        if(i==words.size())
        {
            while(tempStr.size()!=k)
                tempStr+=" ";
        }   
        res.push_back(tempStr);
        stringBuilder(words,i,k,res);
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        
        vector<string> res;
        stringBuilder(words,0,maxWidth,res);
        
        
        return res;
        
    }
};
