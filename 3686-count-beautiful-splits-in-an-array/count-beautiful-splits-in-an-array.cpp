class Solution {
public:
    vector<int> zfunc(vector<int> nums) {
        int n = nums.size();
        vector<int> z(n,0);
        int left = 0,right = 0;
        for(int i = 1;i < n;i++) {
            if(i > right) {
                left = right = i;
                while(right < n && nums[right] == nums[right-left]) {
                    right++;
                }
                z[i] = right - left;
                right--;
            }
            else {
                int ind = i - left;
                if(i + z[ind] <= right) z[i] = z[ind];
                else {
                    left = i;
                    while(right < n && nums[right] == nums[right - left]) right++;
                    z[i] = right - left;
                    right--; 
                }
            }
        }
        return z;
    }

    int beautifulSplits(vector<int>& nums) {
        int n = nums.size();
        vector<int> z1 = zfunc(nums);
        int res = 0;

        unordered_map<int,int> len;
        for (int j = 1; j < n; j++) {
            if (z1[j] >= j) {
                res += (n - 2 * j);
                //we have to avoid taking lesser index if there is a split in j then  after 2*j-1 index
                //till that len we can consider new combos becoz after that are already taken care here
                len[j] = j;
            }
            else len[j] = n - j;
        }


        for (int i = 1; i < n - 1; i++) {
            vector<int> new_nums(nums.begin() + i, nums.end());
            vector<int> z2 = zfunc(new_nums);
            for(int j = 1;j < len[i];j++) {
                if(z2[j] >= j) res++;
            }
        }
        return res;
    }
};
