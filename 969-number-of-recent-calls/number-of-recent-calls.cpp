class RecentCounter {
public:
    queue<int> q;
    int counter;

    RecentCounter() : counter(0) {}
    
    int ping(int t) {
        this->counter++; q.push(t);
        
        while (q.front() < t - 3000) {
            q.pop(); this->counter--;
        }

        return this->counter;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */