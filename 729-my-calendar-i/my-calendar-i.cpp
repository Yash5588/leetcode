class MyCalendar {
public:
    map<int,int> mp;
    MyCalendar() {
        mp.clear();
    }
    
    bool book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int sum = 0;
        for(auto &[key,value] : mp) {
            sum += value;
            if(sum > 1) {
                mp[start]--;
                mp[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */