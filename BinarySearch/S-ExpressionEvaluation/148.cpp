/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 148.cpp
 * Created on : Sun May 09 2021
 ****************************************************************
 */

int operation(int a, int b, char op)
{
    if(op=='+')
        return a + b;
    if(op=='-')
        return a - b;
    if(op=='*')
        return a * b;
    return a / b;    
}

int solve(string s) {
       
    stack<int> numbers;
    stack<char> sign;
    int n = s.size();
    for(int i = 0; i<n; i++)
    {
        if(s[i]==' ')
            continue;

        if(s[i]==')')
        {
            while(!sign.empty() && sign.top()!='(')
            {
                int b = numbers.top();
                numbers.pop();
                int a = numbers.top();
                numbers.pop();
                int afterOp = operation(a,b,sign.top());
                numbers.push(afterOp);
                sign.pop();
            }
            if(!sign.empty())
                sign.pop();
        }
        else if(isdigit(s[i]) || (s[i]=='-' && isdigit(s[i+1])))  
        {
            bool neg = false;
            if(s[i]=='-')
            {
                i++;
                 neg= true;
            }   
            int createNum = 0;    
            while(isdigit(s[i]))
                createNum = createNum*10 + (s[i++]-'0');
            i--;    
            if(neg)
                numbers.push(-1 * createNum);
            else 
                numbers.push(createNum);   
        }      
        else 
            sign.push(s[i]);
    }
    return numbers.top();
}
