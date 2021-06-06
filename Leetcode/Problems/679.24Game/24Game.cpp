/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 24Game.cpp
 * Created on : Sun Jun 06 2021
 ****************************************************************
 */

class Solution {
public:
    
    vector<double> evaluate(double a, double b)
    {
        vector<double> res;
        res.push_back(a+b);
        res.push_back(a-b);
        res.push_back(a*b);
        if(b!=0)
            res.push_back(a/b);
        return res;
    }
    
    bool templateFor2(double a, double b)
    {
        vector<double> third;
        
        third = evaluate(a, b);  // (A # B)
        for(double t : third)
        {
            if(abs(t-24.0) < 0.001)
               return true;
        }
        return false;
    }
    
    bool templateFor3(double a, double b, double c) 
    {
        vector<double> second;
        
        second = evaluate(a, b); // (A # B) # C
        for(double s : second)
        {
            if(templateFor2(s,c))
               return true;
        }
        
        second = evaluate(b, c); // A # (B # C)
        for(double s : second)
        {
            if(templateFor2(a,s))
               return true;
        }
        return false;
    }
    
    bool templateFor4(vector<int> cards) 
    {
        vector<double> first;
        first = evaluate(cards[0], cards[1]);//(A # B) # C # D
        for(double f : first)   
        {
            if(templateFor3(f,cards[2], cards[3]))
               return true;
        }
        
        first = evaluate(cards[1], cards[2]);//A # (B # C) # D
        for(double f : first)   
        {
            if(templateFor3(cards[0],f, cards[3]))
               return true;
        }
        
        first = evaluate(cards[2], cards[3]);//A # B # (C # D)
        for(double f : first)       
        {
            if(templateFor3(cards[0], cards[1], f))
                return true;
        } 
        return false;
    }
    
    bool judgePoint24(vector<int>& cards) {
        
        sort(cards.begin(), cards.end());
        
        while(next_permutation(cards.begin(), cards.end()))
        {
            if(templateFor4(cards))
                return true;
        }
        return false;
    }
};
