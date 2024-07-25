class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> nextGreat;
        stack<int> sta;
        int n = nums2.size();
        for(int i=n-1;i>=0;i--) {
            while(!sta.empty() && sta.top()<=nums2[i]) {
                sta.pop();
            }
            if(sta.empty()) nextGreat[nums2[i]] = -1;
            else nextGreat[nums2[i]] = sta.top();
            sta.push(nums2[i]);
        }
        for(auto &x : nums1) x = nextGreat[x];
        return nums1;
    }
};