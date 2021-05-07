class SnapshotArray {
public:
    vector<vector<int> > v;
    int snap_id;
    SnapshotArray(int length) {
        v.resize(length);
        for(int i = 0 ; i< length ; i++)
            v[i].push_back(0);
        snap_id = -1;     
    }
    
    void set(int index, int val) {
        v[index][v[index].size()-1] = val;
    }
    
    int snap() {
        snap_id++;
        for(int i = 0; i<v.size(); i++)
            v[i].push_back(v[i][v[i].size()-1]);
        return snap_id;
    }
    
    int get(int index, int snap_id) {
        return v[index][snap_id];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */