class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        
        map<int , deque<vector<int> > > sell,buy;
        
        for(vector<int> a : orders){
            
            if(a[2] == 1 )  //sell
            {
                if(buy.size() == 0 || buy.rbegin()->first < a[0])
                    sell[a[0]].push_back(a);
                else 
                {
                    vector<int> deletes;
                    for(auto i = buy.rbegin(); i!=buy.rend(); i++)
                    {
                        if(i->first < a[0])
                            break;
                        vector<int> temp;
                        while(a[1]>0)
                        {
                            temp = i->second.front();
                            if(a[1] < temp[1])
                            {
                                i->second.front()[1] = temp[1]-a[1];
                                a[1] = 0;
                                break; 
                            }   
                            a[1] = a[1]-temp[1];
                            i->second.pop_front();
                            if(i->second.size()==0)
                            {    
                                deletes.push_back(i->first);
                                break;
                            }    
                        }
                    }
                    if(a[1]>0)
                        sell[a[0]].push_back(a);
                    for(int i : deletes)
                        buy.erase(i);
                }
            }
            else if(a[2] == 0 )  //buy
            {
                if(sell.size() == 0 || sell.begin()->first > a[0])
                    buy[a[0]].push_back(a);
                else 
                {
                    vector<int> deletes;
                    for(auto i = sell.begin(); i!=sell.end(); i++)
                    {
                        if(i->first > a[0])
                            break;
                        vector<int> temp;
                        while(a[1]>0)
                        {
                            temp = i->second.front();
                            if(a[1] < temp[1])
                            {
                                i->second.front()[1] = temp[1]-a[1];
                                a[1] = 0;
                                break; 
                            }   
                            a[1] = a[1]-temp[1];                                
                            i->second.pop_front();
                            if(i->second.size()==0)
                            {    
                                deletes.push_back(i->first);
                                break;
                            }    
                        }
                    }
                    if(a[1]>0)
                        buy[a[0]].push_back(a);
                    for(int i : deletes)
                        sell.erase(i);
                }
            }
            
          for(auto i = buy.begin(); i!=buy.end(); i++)
              cout<<"("<<i->first<<"), ";
            cout<<endl;
            for(auto i = sell.begin(); i!=sell.end(); i++)
              cout<<"["<<i->first<<"], ";
            cout<<endl;
              
            
        }
        
        long res = 0;
        for(auto i = sell.begin(); i!=sell.end(); i++)
        {
            while(!i->second.empty())
            {
                cout<<"("<<i->first<<","<<i->second.front()[1]<<"), ";
                cout<<endl;
                res += i->second.front()[1];
                res = res %1000000007;
                i->second.pop_front();
            }    
        }    
            
        for(auto i = buy.begin(); i!=buy.end(); i++)
        {
            while(!i->second.empty())
            {
                cout<<"("<<i->first<<","<<i->second.front()[1]<<"), ";
                cout<<endl;
                res += i->second.front()[1];
                res = res %1000000007;
                i->second.pop_front();
            } 
        }
        
        return res%1000000007;
        
    }
};