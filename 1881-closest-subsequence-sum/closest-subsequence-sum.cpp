class Solution {
public:
    void subsetSum(vector<int> &nums,int pos, vector<long long> &ans, long long sum) {
        if(pos >= nums.size()) {
            ans.push_back(sum);
            return;
        }
        subsetSum(nums,pos+1,ans,sum);
        subsetSum(nums,pos+1,ans,sum+nums[pos]);
    }
    int minAbsDifference(vector<int>& nums, long long goal) {
        int n = nums.size();
        vector<int> left(nums.begin(),nums.begin()+n/2);
        vector<int> right(nums.begin()+n/2,nums.end());
        vector<long long> subset1,subset2;
        subsetSum(left,0,subset1,0);
        subsetSum(right,0,subset2,0);
        set<int> se(subset2.begin(),subset2.end());
        long long ans = INT_MAX;
        for(int i=0;i<subset1.size();i++) {
            auto iter = se.lower_bound(goal - subset1[i]);
            if(iter != se.end() && *iter == goal - subset1[i]) return 0;
            if(iter != se.end()) {
                ans = min(ans,abs(goal - subset1[i] - *iter));
            }
            if(iter != se.begin()){
                ans = min(ans, abs(goal - subset1[i] - *(--iter)));
            } 
        }
        return ans;
    }
};