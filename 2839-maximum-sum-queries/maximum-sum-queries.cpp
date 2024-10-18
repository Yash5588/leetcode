class Solution {
public:
    void update(vector<pair<int,int>> &stack, int val, int sum) {
        while(!stack.empty() && stack.back().second <= sum) {
            stack.pop_back();
        }
        if(!stack.empty() && val <= stack.back().first) return;
        stack.push_back({val,sum});
    }
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        vector<pair<int,int>> pairs;
        int n = nums1.size();
        for(int i = 0;i < n;i++) {
            pairs.push_back({nums1[i],nums2[i]});
        }
        int i = 0;
        for(auto &x : queries) {
            x.push_back(i);
            i++;
        }
        sort(pairs.begin(),pairs.end(),greater<pair<int,int>>());
        sort(queries.begin(),queries.end(),greater<vector<int>> ());
        vector<pair<int,int>> stack;
        i = 0;
        vector<int> res(queries.size());
        for(auto &q : queries) {
            int x = q[0];
            int y = q[1];
            int res_ind = q[2];
            while(i < n && pairs[i].first >= x) {
                int sum = pairs[i].first + pairs[i].second;
                update(stack,pairs[i].second,sum);
                i++;
            }
            for(auto &x : stack) cout << x.first << ' ' << x.second << endl;
            int ind = lower_bound(stack.begin(),stack.end(),pair<int,int>{y,INT_MIN}) - stack.begin();
            // cout << stack.size() << endl;
            if(ind != stack.size()) res[res_ind] = stack[ind].second;
            else res[res_ind] = -1;
        }
        return res;
    }
};