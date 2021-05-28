class Solution {
public:
    string reorderSpaces(string text) {
        
        int spaces = 0;
        int words = 0;
        int n = text.size();
        
        for(int i = 0; i<n; i++)
        {
            if(text[i]==' ')
                spaces++;
            else if(isalpha(text[i]))
            {
                words++;
                while(i<n && isalpha(text[i])) i++;
                i--;
            }
        }
        string res = "";
        int spacePerWord = 0;
        string spaceProvider = "";
        words--;
        if(words>0)
        {
            spacePerWord = spaces / words;
            for(int i = 0; i<spacePerWord; i++)
                spaceProvider += " ";
        }

        for(int i = 0; i<n; i++)
        {

            if(isalpha(text[i]))
            {
                string stringBuilder = "";
                while(i<n && isalpha(text[i])) stringBuilder += text[i++];
                i--;
                if(words)
                {
                    stringBuilder += spaceProvider;
                    spaces-= spaceProvider.size();
                    words--;
                } 
                res+=stringBuilder;
            }
        }
        
        while(spaces>0)
            res+=" ", spaces--;
        return res;
    }
};
