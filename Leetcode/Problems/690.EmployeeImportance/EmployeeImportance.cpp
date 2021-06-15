/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : EmployeeImportance.cpp
 * Created on : Tue Jun 15 2021
 ****************************************************************
 */


/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    unordered_map<int, Employee*> m; 
    int getScore(int id)
    {
        int score = 0;
        for(int subId : m[id]->subordinates)
        {
            score += getScore(subId);
        }
        return m[id]->importance + score;
    }
    int getImportance(vector<Employee*> employees, int id) {
        
        m.clear();
        
        for(auto e : employees)
            m[e->id] = e;
        
        return getScore(id);
        
    }
};
