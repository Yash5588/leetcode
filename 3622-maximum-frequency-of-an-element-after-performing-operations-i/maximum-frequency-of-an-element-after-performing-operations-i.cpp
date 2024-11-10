class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        map<int,int> ranges;
        unordered_map<int,int> freq;
        int n = nums.size();
        set<int> critical_points;
        for(auto &num : nums) {
            ranges[num - k]++;
            ranges[num + k + 1]--;
            freq[num]++;
            critical_points.insert(num - k);
            critical_points.insert(num + k + 1);
            critical_points.insert(num);
        }
        auto iter = ranges.begin();
        int oper = 0;
        int ma = INT_MIN;
        for(auto &x : critical_points) {
            for(;iter != ranges.end();iter++) {
                if(iter->first <= x) {
                    oper += iter->second;
                }
                else break;
            }
            int currentFreq = freq[x] + min(numOperations, max(0, oper - freq[x]));
            ma = max(ma, currentFreq);
        }
        return ma;
    }
};