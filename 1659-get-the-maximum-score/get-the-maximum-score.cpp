class Solution {
public:
    int mod = 1e9+7;
    long long dp[100002][2];
    long long solve(vector<int> &nums1, vector<int> &nums2, unordered_map<int,int> &map1, unordered_map<int,int> &map2, int pos, bool infirst) {
        int n = nums1.size();
        int m = nums2.size();
        if(pos >= n && infirst) return 0;
        if(pos >= m && !infirst) return 0;
        if(dp[pos][infirst] != -1) return dp[pos][infirst];
        long long ma = 0,straight = 0,zig_zag = 0;
        if(infirst) {
            if(map1[nums1[pos]] != -1) {
                straight = nums1[pos] + solve(nums1,nums2,map1,map2,pos+1,true);
                zig_zag = nums1[pos] + solve(nums1,nums2,map1,map2,map1[nums1[pos]]+1,false);
                ma = max(straight,zig_zag);
            }
            else {
                ma = max(ma, (nums1[pos] + solve(nums1,nums2,map1,map2,pos+1,true)));
            }
        }
        else {
            if(map2[nums2[pos]] != -1) {
                straight = nums2[pos] + solve(nums1,nums2,map1,map2,pos+1,false);
                zig_zag = nums2[pos] + solve(nums1,nums2,map1,map2,map2[nums2[pos]]+1,true);
                ma = max(straight,zig_zag);
            }
            else {
                ma = max(ma, nums2[pos] + solve(nums1,nums2,map1,map2,pos+1,false));
            }
        }
        return dp[pos][infirst] = ma;
    }
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        unordered_map<int,int> map1,map2;
        int first = 0,second = 0;
        while(first < n && second < m) {
            if(nums1[first] < nums2[second]) {
                map1[nums1[first]] = -1;
                first++;
            }
            else if(nums1[first] > nums2[second]) {
                map2[nums2[second]] = -1;
                second++;
            }
            else {
                map1[nums1[first]] = second;
                map2[nums2[second]] = first;
                first++;
                second++;
            }
        }
        while(first < n) {
            map1[nums1[first]] = -1;
            first++;
        }
        while(second < m) {
            map2[nums2[second]] = -1;
            second++;
        }
        // for(auto &x : map1) cout << x.first << ' ' << x.second << endl;
        // for(auto &x : map2) cout << x.first << ' ' << x.second << endl;
        memset(dp,-1,sizeof(dp));
        long long first_take = solve(nums1,nums2,map1,map2,0,true);
        memset(dp,-1,sizeof(dp));
        long long second_take = solve(nums1,nums2,map1,map2,0,false);
        return max(first_take,second_take) % mod; 
    }
};