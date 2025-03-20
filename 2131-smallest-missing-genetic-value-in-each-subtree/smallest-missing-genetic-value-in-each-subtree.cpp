class Solution {
public:
    vector<bool> isOne;
    unordered_map<int,vector<int>> adj;
    vector<int> path;
    bool check(vector<int> &nums, int node) {
        if(nums[node] == 1) {
            isOne[node] = true;
            if(isOne[node]) path.push_back(node);
            return true;
        } 

        bool isPresent = false;
        for(auto &child : adj[node]) {
            isPresent |= check(nums, child);
        }
        isOne[node] = isPresent;
        if(isOne[node]) path.push_back(node);
        return isPresent;
    }

    void mark(int node, vector<int> &nums, vector<bool> &visited, vector<bool> &marked) {
        for(auto &child : adj[node]) {
            if(!visited[child]) {
                mark(child, nums, visited, marked);
            }
        }
        visited[node] = true;
        marked[nums[node]] = true;
    }
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        int n = nums.size();
        isOne.resize(n,false);
        for(int i = 0;i < n;i++) {
            adj[parents[i]].push_back(i);
        }
        //segregate nodes which have 1 and which doesn't have 1 in their subtree
        check(nums, 0);


        vector<int> ans(n);
        for(int i = 0;i < n;i++) {
            ans[i] = (!isOne[i]) ? 1 : 0;
        }

        int ind = 1;
        vector<bool> visited(n,false);
        vector<bool> marked(100005,false);
        for(auto &node : path) {
            mark(node, nums, visited, marked);
            while(marked[ind]) ind++;
            ans[node] = ind;
        }
        return ans;
    }
};