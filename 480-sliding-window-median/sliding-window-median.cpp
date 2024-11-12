class Solution {
public:
    multiset<long long> low, high;
    void remove(long long ele) {
        auto iter = low.find(ele);
        if(iter != low.end()) {
            low.erase(iter);
            if(!high.empty()) {
                low.insert(*high.begin());
                high.erase(high.begin());
            }
        }
        else {
            iter = high.find(ele);
            if(iter != high.end()) {
                high.erase(iter);
            }
        }
    }

    void update(long long ele, int low_size) {
        low.insert(ele);
        if(low.size() > low_size) {
            long long ele = *low.rbegin();
            low.erase(low.find(ele));
            high.insert(ele);
        }
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        long long low_size = 0;
        long long n = nums.size();
        if(k & 1) {
            low_size = k/2+1;
        }
        else {
            low_size = k/2;
        }
        for(int i = 0;i < k;i++) {
            low.insert(nums[i]);
            if(low.size() > low_size) {
                int ele = *low.rbegin();
                low.erase(low.find(ele));
                high.insert(ele);
            }
        }
        vector<double> res;
        if(k & 1) {
            res.push_back({double(*low.rbegin())});
        }
        else {
            res.push_back({(*low.rbegin() + *high.begin())/2.0});
        }
        for(int i = 0;i < n-k;i++) {
            remove(nums[i]);
            update(nums[i+k],low_size);
            if(k & 1) {
                res.push_back({double(*low.rbegin())});
            }
            else {
                res.push_back({(*low.rbegin() + *high.begin())/2.0});
            }
        }
        return res;
    }
};