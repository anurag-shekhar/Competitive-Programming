/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : SnapshotArray.cpp
 * Created on : Tue May 18 2021
 ****************************************************************
 */

class SnapshotArray {
public:
    unordered_map<int, map<int,int> > m;
    int snapCount;
    SnapshotArray(int length) {
        
       for(int i = 0; i<length; i++)
       {
           map<int,int> temp;
           temp[0] = 0;
           m[i] = temp;
       }
       snapCount = 0;    
    }
    
    void set(int index, int val) {
        m[index][snapCount] = val;
        return;
    }
    
    int snap() {
        
        snapCount++;
        return snapCount-1;
    }
    
    int get(int index, int snap_id) {
        
        auto itr = m[index].upper_bound(snap_id);
        itr = prev(itr);
        return itr->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
