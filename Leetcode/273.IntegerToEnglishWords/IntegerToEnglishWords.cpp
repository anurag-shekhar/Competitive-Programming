class Solution {
public:
    void solve(int num, int pos,vector<string> &res)
    {
        if(!num)
        {
            if(pos==0)
            {
                res.push_back("Zero");
                return;
            }
            return;
        }
        
        
        vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        
        vector<string>tens_1 = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen","Fifteen", "Sixteen","Seventeen", "Eighteen","Nineteen" };
        
        string s = "";
        if(pos == 1)
            s = "Thousand";
        if(pos == 2)
            s = "Million";
        if(pos == 3)
            s = "Billion";
        
        int extractNum = num%1000;
        num /= 1000;
        solve(num,pos+1,res);
        vector<int> digit(3,0);
        int i=2;
        while(extractNum)
        {
            digit[i--] = extractNum%10;
            extractNum/=10;
        }
        if(digit[0]>0)
        {
            res.push_back(ones[digit[0]]); 
            res.push_back("Hundred");
        }    
        if(digit[1]==1)
        {
            res.push_back(tens_1[digit[2]]);
            res.push_back(s);
        }    
        else 
        {
            if(digit[1]>0)
                res.push_back(tens[digit[1]]);
            if(digit[2]>0)
            {
                res.push_back(ones[digit[2]]);   
            }
            if(digit[1] || digit[2] || digit[0])
                res.push_back(s); 
        }
        
    }
    string numberToWords(int num, int pos = 0) {
        
        vector<string> res;
        string resStr = "";
        solve(num,pos,res);
        bool flag = true;
        for(int i = 0; i<res.size(); i++)
        {   if(res[i]=="")
                continue;
            if(flag)
            {
                flag = false;   
            }
            else 
                resStr+=" ";
                
            resStr += res[i];

            
         }
        return resStr;
    }
};
