class MyCalendarThree {
private:
    map<long long, long long> mp;
public:
    MyCalendarThree() {
    }
    
    int book(int startTime, int endTime) {
        mp[startTime]++;
        mp[endTime]--;
        long long ma = LONG_MIN;
        long long prefix = 0;
        for(auto &[range,val] : mp) {
            prefix += val;
            ma = max(ma, prefix);
        }
        return ma;

    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */