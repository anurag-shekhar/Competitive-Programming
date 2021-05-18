/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : FindDuplicateFileInSystem.cpp
 * Created on : Tue May 18 2021
 ****************************************************************
 */

class Solution {
public:
    
    vector<string> splitter( string &s, char ch)
    {
        vector<string> splitSpaces;
        for(int i = 0; i<s.size(); i++)
        {
            string temp = "";
            while(i<s.size() && s[i]!=ch)
            {
                temp += s[i];
                i++;
            }
            splitSpaces.push_back(temp);
        }
        return splitSpaces;
    }
    void process(string &s, unordered_map<string, vector<string> > &m)
    {
        vector<string> splitSpaces = splitter(s, ' ');
        
        for(int i = 1; i<splitSpaces.size(); i++)
        {
            vector<string> file_content = splitter(splitSpaces[i], '(');
            
            string path_filename = splitSpaces[0] + "/" + file_content[0];
            m[file_content[1]].push_back(path_filename);
        }
    }
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        
        unordered_map<string, vector<string> > m;
        
        for(int i = 0; i<paths.size(); i++)
        {
            process(paths[i], m);
        }
        
        vector<vector<string> > res;
        for(pair<string, vector<string> > p: m)
        {
            if(p.second.size()>1)
                res.push_back(p.second);
        }
        return res;
    }
};
