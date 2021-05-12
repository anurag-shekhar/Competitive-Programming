/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : DesignAuthenticationManager.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */

class AuthenticationManager {
public:
    
    int live,currTime;
    unordered_map<string, int> keyMap;
    map<int,unordered_set<string> > timeMap;
    AuthenticationManager(int timeToLive) {
        
        live = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        keyMap[tokenId] = currentTime+live;
        currTime = currentTime;
        timeMap[keyMap[tokenId]].insert(tokenId);        
    }
    
    void renew(string tokenId, int currentTime) {
        
        if(keyMap.find(tokenId)!=keyMap.end()){
            int check = keyMap[tokenId];
            if(check>currentTime){
                timeMap[check].erase(tokenId);
                int newTime = currentTime + live;
                keyMap[tokenId] = newTime;
                timeMap[newTime].insert(tokenId);
            }   
            else{
                keyMap.erase(tokenId);
                timeMap[check].erase(tokenId);
            }    
        }
        
    }
    
    int countUnexpiredTokens(int currentTime) {
        
        vector<int> expToken;
        vector<string> expTime;
        int count = 0;
        for(auto itr = timeMap.rbegin(); itr!=timeMap.rend(); itr++)
        {
            int check = itr->first;
            if(check <=currentTime)
                break;
            count += timeMap[check].size();
        }
        return count;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */
