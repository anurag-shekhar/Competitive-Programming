/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : WateringPlantsII.cpp
 * Created on : Thu Dec 16 2021
 ****************************************************************
 */

class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        
        int currA = capacityA, currB = capacityB; 
        int refills = 0;
        int n = plants.size();
        int ptrA = 0, ptrB = n-1;
        
        while(ptrA <= ptrB) {
            if(ptrA == ptrB) {
                if(currA>=currB) {
                    if(currA < plants[ptrA]){
                    refills++;
                    currA = capacityA;
                    }
                    currA -= plants[ptrA++];
                }
                else {
                    if(currB < plants[ptrB]){
                    refills++;
                    currB = capacityB;
                    }
                    currB -= plants[ptrB--];

                }
            }
            else {
                
                if(currA < plants[ptrA]){
                    refills++;
                    currA = capacityA;
                }
                if(currB < plants[ptrB]){
                    refills++;
                    currB = capacityB;
                }
                currA -= plants[ptrA++];
                currB -= plants[ptrB--];
                    
            }
        }
        return refills;
        
    }
};
