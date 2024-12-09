class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> count;
        multiset<pair<int,int>,greater<pair<int,int>>> se;
        for(int i = 0;i < n;i++) {
            count[nums[i]]++;
            if(count[nums[i]] == 1) {
                se.insert({1,nums[i]});
            }
            //greater than 1
            else {
                int cnt = count[nums[i]]-1;
                se.erase(se.find({cnt,nums[i]}));
                se.insert({cnt+1,nums[i]});
            }
        }
        vector<int> res;
        int c = 0;
        for(auto &x : se) {
            if(c >= k) break;
            res.push_back(x.second);
            c++;
        }
        return res;
    }
};