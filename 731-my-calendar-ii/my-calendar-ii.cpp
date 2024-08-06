class MyCalendarTwo {
public:

    MyCalendarTwo() {
    }

    map<long long, long long> mp;
    bool book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int sum = 0;
        for(auto &x: mp) {
            sum += x.second;
            if(sum >= 3) {
                mp[start]--;
                mp[end]++;
                return false;
            }
        }
        return true;

    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */