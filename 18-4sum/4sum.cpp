class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>> se;
        //we will fix 2-pointers and the rest will be taken care by 2-pointer approach
        for(int d = 0;d < n-3; d++) {
            for(int c = d+1;c < n-2;c++) {
                int a = c+1, b = n-1;
                while(a < b) {
                    long long sum = nums[a];
                    //this to addess the integer overflow i added them seperately
                    sum += nums[b];
                    sum += nums[c];
                    sum += nums[d];
                    if(sum == target) {
                        //store in set for unique combinations
                        se.insert({nums[a],nums[b],nums[c],nums[d]});
                    }
                    if(sum < target) a++;
                    else b--;
                }
            }
        }
        return vector<vector<int>> (se.begin(),se.end());
    }
};