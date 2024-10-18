class Solution {
public:
    void update(vector<pair<int,int>> &stack, int val, int sum) {
        //what are we doing here.
        //see if we have query as y = 2 and in our vector we have (3,4),(5,9)
        //which one would you consider?
        //obviously the one with max sum (5,9) then what is the use of (3,4)?
        //for all y <= 5 the result is still (5,9)
        //so discard all the sum which have less than current sum(assuming previously all pairs are 
        //already in monotonicity)
        while(!stack.empty() && stack.back().second <= sum) {
            stack.pop_back();
        }
        //if want to add the current pair to stack
        //now think of it like this stack has top as (4,9) we have (3,5)
        //anyway all the sums in stacks are removed the so the stack top sum is strictly 
        //greater than current sum
        //now sum is greater now we want to add a lesser y value
        //same case if we have query y = 2 then if we add (3,5) we will get (3,5) as result
        //so to avoid that we won't add if (y < stack.top y value)
        //then we can get (4,9)
        if(!stack.empty() && val <= stack.back().first) return;
        stack.push_back({val,sum});
        //finally the stack should be of the form {(1,2),(4,5),(7,9)}
        //both y and sum should be increasing fashion
    }
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        vector<pair<int,int>> pairs;
        //form pairs
        int n = nums1.size();
        for(int i = 0;i < n;i++) {
            pairs.push_back({nums1[i],nums2[i]});
        }
        //attach indices to queries for not loosing track of res when sorted
        int i = 0;
        for(auto &x : queries) {
            x.push_back(i);
            i++;
        }
        //sort pairs and queries in decreasing order
        sort(pairs.begin(),pairs.end(),greater<pair<int,int>>());
        sort(queries.begin(),queries.end(),greater<vector<int>> ());
        //real stack is not used because we can't use lower bound for it 
        //so we use vector
        vector<pair<int,int>> stack;
        i = 0;
        vector<int> res(queries.size(),-1);
        for(auto &q : queries) {
            int x = q[0];
            int y = q[1];
            int res_ind = q[2];
            //now we only consider pairs which have nums1[i] >= x of query
            while(i < n && pairs[i].first >= x) {
                //for all those pairs which satisfy above condition now we need 2 more things
                //nums2[i] >= y and maximum sum among all those pairs
                int sum = pairs[i].first + pairs[i].second;
                //it can be achieved by monotonic stack
                //we pass nums2[i] and nums1[i]+nums2[i]
                update(stack,pairs[i].second,sum);
                i++;
            }
            // for(auto &x : stack) cout << x.first << ' ' << x.second << endl;
            int ind = lower_bound(stack.begin(),stack.end(),pair<int,int>{y,INT_MIN}) - stack.begin();
            // cout << stack.size() << endl;
            if(ind != stack.size()) res[res_ind] = stack[ind].second;
        }
        return res;
    }
};