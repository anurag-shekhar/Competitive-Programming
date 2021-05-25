/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : RobotBoundedInCircle.cpp
 * Created on : Tue May 25 2021
 ****************************************************************
 */

class Solution {
public:
    
    void execute(pair<int, int> &p,int &direction, char order)
    {
        if(order=='L')
            direction = (direction-1+4)%4;
        if(order=='R')
            direction = (direction+1)%4;
        if(order=='G')
        {
            if(direction%2==0)
            {
                if(direction==0)
                    p.second++;
                else 
                    p.second--;
            }
            else 
            {
                if(direction==1)
                    p.first++;
                else 
                    p.first--;
            }
        }
    }
    string convert(pair<int,int> &p)
    {
        return to_string(p.first)+","+to_string(p.second);
    }
    bool isRobotBounded(string instructions) {
        
        unordered_set<string> s;
        
        int direction = 0;
        /*
        Idea : Robot stays in circle if it changes the direction after one cylcle of instruction 
                N(0)
                |
         (3)W -   - E(1)               
                |
                S(2)
        */
        pair<int,int> p = make_pair(0,0), origin;
        origin = p;
        s.insert(convert(p));
        int n = instructions.size();
        for(int i =0; i<n; i++)
        {
            execute(p,direction, instructions[i]);
//             if(instructions[i]=='G')
//             {

//                 string newCoordinate = convert(p);
//                 if(s.count(newCoordinate)!=0)
//                     return true;
//                 s.insert(newCoordinate);
//             }
        }
        
       
        
        if(convert(p)==convert(origin))
            return true;
        if(direction==0)
            return false;
        return true;
        
        
        
    }
};
