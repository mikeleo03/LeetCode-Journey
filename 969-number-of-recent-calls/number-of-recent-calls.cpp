class RecentCounter {
public:
    int counter;
    std::queue<int> pings;
    RecentCounter() {
        counter = 0;
    }
    
    int ping(int t) {
        this->counter++;
        pings.push(t);
        while (t - 3000 > pings.front()) {
            pings.pop();
            this->counter--;
        }
        return this->counter;
    }
};