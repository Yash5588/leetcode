class Solution {
public:
    vector<int> kmp(vector<int> &nums, vector<int> &p) {
        string str;
        for(auto &x : p) {
            if(x == -1) str += '2';
            else str += to_string(x);
        }
        str += '#';
        for(int i=0;i<nums.size()-1;i++) {
            if(nums[i] < nums[i+1]) str += '1';
            else if(nums[i] > nums[i+1]) str += '2';
            else str += '0'; 
        }
        vector<int> lps(str.size(),0);
        for(int i=1;i<str.size();i++) {
            int prev_index = lps[i-1];
            while(prev_index>0 && str[i] != str[prev_index]) {
                prev_index = lps[prev_index-1];
            }
            lps[i] = prev_index + (str[i] == str[prev_index]);
        }
        return lps;
    }
    int countMatchingSubarrays(vector<int>& nums, vector<int>& p) {
        vector<int>lps = kmp(nums,p);
        int plen = p.size();
        int count = 0;
        for(int i=plen;i<lps.size();i++) {
            if(lps[i] == plen) count++;
        }
        return count;
    }
};