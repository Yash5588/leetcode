class Solution {
public:
    unordered_map<int,vector<int>> adj;
    unordered_map<int,int> depth;
    vector<int> coprimes;
    vector<int> res;
    void solve(vector<int> &nums, int node, int par) {
        //update the depth of each node
        depth[node] = depth[par] + 1;
        //store the original nums value
        int prev = coprimes[nums[node]];
        //change the coprimes[nums[i]] = i which is current node
        //in that particular subtree
        coprimes[nums[node]] = node;
        // cout << node << endl;
        for(auto &child : adj[node]) {
            if(child == par) continue;
            int ma = INT_MIN;
            for(int i = 1;i <= 50;i++) {
                // cout << i << ' ' << coprimes[i] << "   ";
                //get all the latest ancestors for each value
                int ances = coprimes[i];
                if(ances != -1) {
                    //check if ancestor exists or not
                    if(__gcd(nums[child],nums[ances]) == 1) {
                        //if exists then check gcd
                        if(ma < depth[ances]) {
                            //if ancestor exists and gcd 1 compare the depth
                            //we need the ancestor with max depth
                            ma = depth[ances];
                            res[child] = ances;
                        }
                    }
                }
            }
            // cout << endl;
            solve(nums,child,node);
        }
        //after that subtree is completed we are backtracking 
        //so revert back to original value 
        //we are only interested in nums values of ancestors so we
        //have to backtrack after completing all children
        coprimes[nums[node]] = prev;
    }
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<int> indegree(n,0);
        for(auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        res.resize(n,-1);
        //coprimes to store the latest node with that value,
        //anyway it's depth is the maximum in dfs
        coprimes.resize(51,-1);
        solve(nums,0,-1);
        return res;
    }
};