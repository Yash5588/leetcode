class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        long long sum = 0;
        priority_queue<long long, vector<long long>, greater<long long>> pq; //min heap
        vector<pair<int,int>> vec;
        for(int i = 0;i < n;i++) {
            vec.push_back({nums1[i], i});
        }
        sort(vec.begin(),vec.end());
        vector<long long> res(n,0);
        long long curr_sum = 0,prev_sum = 0;
        int prev = -1;
        for(int i = 0;i < n;i++) {
            int val = vec[i].first;
            int idx = vec[i].second;
            if(prev != val) {
                prev_sum = curr_sum;
            }
            res[idx] = prev_sum;
            curr_sum += nums2[idx];
            pq.push(nums2[idx]);
            if(pq.size() > k) {
                curr_sum -= pq.top();
                pq.pop();
            }
            prev = val;
        }
        return res;
    }
};