/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 233.cpp
 * Created on : Sun May 09 2021
 ****************************************************************
 */

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
        while(ms--)
            tempStr += " ";
    }
    res.push_back(tempStr);
    stringBuilder(words,i,k,res);
}

vector<string> solve(vector<string>& words, int k) {
    vector<string> res;
    stringBuilder(words,0,k,res);
    return res;
}
