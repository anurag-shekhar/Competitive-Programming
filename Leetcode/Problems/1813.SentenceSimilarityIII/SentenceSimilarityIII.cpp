/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : SentenceSimilarityIII.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */

class Solution {
public:
    
    bool compare(vector<string> &s1, vector<string> &s2)
    {
        if(s1.size()<s2.size())
            return compare(s2,s1);
        
        int n1 = s1.size(), n2 = s2.size();
        if(s2.size()==1)
        {
            if(s2[0] == s1.front() || s2[0] == s1.back())
                return true;
            return false;
        }
        
        int i1 =0, i2 = 0;
        bool before = 0, middle = 0, after = 0;
        while(i2<n2 && i1<n1)
        {

            if(s1[i1] == s2[i2])
            {
                i1++;i2++;

                while(i2<n2 && i1<n1 && s1[i1] == s2[i2])
                {
                    i1++; i2++;
                }
                while(i2<n2 && i1<n1 && s1[i1] != s2[i2])
                {
                    i1++;
                    middle = 1;
                }
                    
                while(i2<n2 && i1<n1 && s1[i1] == s2[i2])
                {
                    i1++; i2++;
                }
                break;
            }
            before = 1;
            i1++;
            
        }
        if(i1!=n1)
            after = 1;
        
        if(i2!=n2)
            return false;
        int check = before + after + middle;
        if(check == 1)
            return true;
        if(check == 0 && i1==n1 && i2==n2)
            return true;
        return false;
    }
    bool areSentencesSimilar(string sentence1, string sentence2) {
        
        vector<string> s1,s2;
        
        for(int i = 0; i<sentence1.size(); i++)
        {
            string temp = "";
            while( i < sentence1.size() && isalpha(sentence1[i]))
            {
                temp+=sentence1[i];
                i++;
            }
            s1.push_back(temp);     
        }
        
        for(int i = 0; i<sentence2.size(); i++)
        {
            string temp = "";
            while( i < sentence2.size() && isalpha(sentence2[i]))
            {
                temp+=sentence2[i];
                i++;
            }
            s2.push_back(temp);     
        }
        
        return compare(s1,s2);
        
        
        // for(string s : s1)
        //     cout<<s<<"#";
        // cout<<endl;
        // for(string s : s2)
        //     cout<<s<<"#";
        // cout<<endl;
        return 1;
    }
};
