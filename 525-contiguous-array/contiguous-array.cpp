class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n+1,0);
        int ans = 0;
        //map is used to store the initial occurance of the prefix sum
        unordered_map<int,int> mp;
        //initially 0 index is stored as 0
        mp[0] = 0;
        for(int i=1;i<=n;i++) {
            //+1 for 1 and -1 for 0
            if(!nums[i-1])  prefix[i] = prefix[i-1] - 1;
            else  prefix[i] = prefix[i-1] + 1;
            // cout << prefix[i] << endl;
            //if that prefix sum is already present then find max length
            if(mp.find(prefix[i]) != mp.end()) {
                ans = max(ans, i - mp[prefix[i]]);
            }
            //otherwise initialize the index for that prefix sum
            else {
                mp[prefix[i]] = i;
            }
        }
        return ans;
    }
};