class Solution {
public:
    bool diffCheck(vector<int> &nums, int diff) {
        int n = nums.size();
        for(int i = 0;i < n-1;i++) {
            if(abs(nums[i]-nums[i+1]) > diff) return false;
        }
        return true;
    }
    bool checker(vector<int> &nums, int diff) {
        int mi = INT_MAX,ma = INT_MIN;
        int n = nums.size();
        for(int i = 0;i < n;i++) {
            if(nums[i] == -1) {
                if(i-1 >= 0 && nums[i-1] != -1) {
                    mi = min(mi, nums[i-1]);
                    ma = max(ma, nums[i-1]);
                }
                if(i+1 < n && nums[i+1] != -1) {
                    mi = min(mi, nums[i+1]);
                    ma = max(ma, nums[i+1]);
                }
            }
        }
        int x = mi + diff; //minValue
        int y = ma - diff; //maxValue
        vector<int> temp;
        temp = nums;
        //preference to x in case of multiple -1
        for(int i = 0;i < n;i++) {
            if(temp[i] == -1) {
                if((i == 0 || abs(temp[i-1] - x) <= diff) && 
                    (i == n-1 || temp[i+1] == -1 || abs(temp[i+1] - x) <= diff)) {
                        temp[i] = x;
                }
                else temp[i] = y;
            }
        }
        if(diffCheck(temp,diff)) return true;
        
        //preference to y in case multiple -1
        temp = nums;
        for(int i = 0;i < n;i++) {
            if(temp[i] == -1) {
                if((i == 0 || abs(temp[i-1] - y) <= diff) && 
                    (i == n-1 || temp[i+1] == -1 || abs(temp[i+1] - y) <= diff)) {
                        temp[i] = y;
                }
                else temp[i] = x;
            }
        }
        if(diffCheck(temp,diff)) return true;
        return false;

    }
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        int cnt = count(nums.begin(),nums.end(),-1);
        if(cnt == n) return 0;
        if(cnt == 0) {
            int res = 0;
            for(int i = 0;i < n-1;i++) {
                res = max(res, abs(nums[i]-nums[i+1]));
            }
            return res;
        }
        
        int low = 0,high = 1e9;
        int ans = -1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(checker(nums,mid)) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};