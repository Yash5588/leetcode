class DisjointSet{
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n+1,0);
        size.resize(n+1,1);
        for(int i = 0;i < n;i++) parent[i] = i;
    }

    int findUPar(int node) {
        if(parent[node] == node) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ult_u = findUPar(u);
        int ult_v = findUPar(v);
        if(ult_u == ult_v) return;
        if(size[ult_u] <= size[ult_v]) {
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        }
        else {
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }
    }
};
class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int n = nums.size();
        int size = *max_element(nums.begin(),nums.end())+1;
        DisjointSet ds(size);
        for(auto &x : nums) {
            for(int i = 2;i <= sqrt(x);i++) {
                if(x % i == 0) {
                    ds.unionBySize(i,x);
                    ds.unionBySize(x/i,x);
                }
            }
        }
        int ma = 0;
        unordered_map<int,int> cnt;
        for(auto &x : nums) {
            int parent = ds.findUPar(x);
            cnt[parent]++;
            ma = max(ma, cnt[parent]);
        }
        return ma;
    }
};