class RecentCounter {
public:
    RecentCounter() {}
    
    int ping(int t) {
        pings.push_back(t);
        currTime = t;
        while (pings.front() < t - 3000) {
            pings.pop_front();
        }
        return pings.size();
    }

private:
    deque<int> pings;
    int currTime;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */