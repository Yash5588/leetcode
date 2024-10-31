class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> res;
        int n = nums.size();
        for(int i = 0;i < pow(2,n);i++) {
            vector<int> temp;
            for(int j = 0;j < n;j++) {
                if((i & (1<<j))) {
                    temp.push_back(nums[j]);
                }
            }
            sort(temp.begin(),temp.end());
            res.insert(temp);
        }
        return vector<vector<int>> (res.begin(),res.end());
    }
};