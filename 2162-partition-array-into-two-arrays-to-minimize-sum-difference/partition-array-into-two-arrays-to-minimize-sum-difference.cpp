class Solution {
public:
    void Subsets(vector<int> &nums, int pos, int cnt, int sum, map<int,vector<int>> &subset) {
        int n = nums.size();
        if(pos >= n) {
            subset[cnt].push_back(sum);
            return;
        }
        Subsets(nums, pos+1, cnt+1, sum + nums[pos], subset);
        Subsets(nums, pos+1, cnt, sum, subset);
    }
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(nums.begin(),nums.begin()+n/2);
        vector<int> right(nums.begin()+n/2,nums.end());
        map<int, vector<int>> subset1, subset2;
        Subsets(left, 0, 0, 0, subset1);
        Subsets(right, 0, 0, 0, subset2);
        int sum = accumulate(nums.begin(), nums.end(), 0);
        for(int i = 0;i < n/2;i++) {
            sort(subset2[i].begin(),subset2[i].end());
        }
        int res = INT_MAX;
        for(int size = 0;size < n/2;size++) {
            for(auto &ele : subset1[size]) {
                int target = sum/2 - ele;
                int rightInd = n/2 - size;
                auto &vec = subset2[rightInd];
                auto iter = lower_bound(vec.begin(), vec.end(), target);
                if(iter != vec.end()) {
                    int leftSum = ele + *iter;
                    int rightSum = sum - leftSum;
                    res = min(res, abs(leftSum - rightSum));
                }
                if(iter != vec.begin()) {
                    iter--;
                    int leftSum = ele + *iter;
                    int rightSum = sum - leftSum;
                    res = min(res, abs(leftSum - rightSum));
                }
            }
        }
        return res;
    }
};