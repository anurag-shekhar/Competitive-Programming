class Solution {
public:
    class node
    {
        public:
        int dist;
        string str;
        node(int a, string b): dist(a), str(b) {}
    };
    int diff(string &A, string &B)
    {
        int dif = 0;
        for(int i = 0; i<A.size(); i++)
        {    
            if(A[i]!=B[i])
                dif++;
            if(dif > 1)
                return 2; 
        }    
        return dif;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        bool flag = false;
        for(string s : wordList)
            if(s==endWord)
                flag = true;
        if(!flag)
            return 0;
        

        queue<node*> q;
        node* k = new node(1,beginWord);
        q.push(k);
        
        vector<bool> isVisited(wordList.size(),false);
        
        while(!q.empty())
        {
            node* temp = q.front();
            q.pop();
            
            if(temp->str == endWord)
                return temp->dist;
            
            for(int i = 0; i<wordList.size(); i++)
            {   
                
                if(diff(temp->str,wordList[i])==1 && !isVisited[i])
                {
                    node*n = new node(temp->dist+1, wordList[i]);
                    q.push(n);
                    isVisited[i] = true;
                }
             }
        }
        return 0;
        
    }
};
