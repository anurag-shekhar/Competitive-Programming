class HitCounter {
    public:
    queue<int> q;
    HitCounter() {
    }

    void add(int timestamp) {
        q.push(timestamp);
    }

    int count(int timestamp) {
        int last60 = timestamp - 60;

        while(!q.empty() && q.front() < last60)
            q.pop();

        return q.size();    
    }
};
