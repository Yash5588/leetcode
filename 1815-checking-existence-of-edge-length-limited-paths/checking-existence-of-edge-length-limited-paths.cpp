class disjointSet{
public:
    //O(nlogn) Time Complexity
    //O(n) space complexity
    vector<int> parent,rank;
    disjointSet(int n) {
        parent.resize(n);
        rank.resize(n,0);
        for(int i = 0;i < n;i++) parent[i] = i;
    }

    int findUPar(int node) {
        return parent[node] = (parent[node] == node) ? node : findUPar(parent[node]);
        // if(node == parent[node]) return node;
        // return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ult_u = findUPar(u);
        int ult_v = findUPar(v);
        if(rank[ult_u] < rank[ult_v]) {
            parent[ult_u] = ult_v;
        }
        else if(rank[ult_u] > rank[ult_v]) {
            parent[ult_v] = ult_u;
        }
        else {
            parent[ult_u] = ult_v;
            rank[ult_v]++;
        }
    }
};
class Solution {
public:
    static bool sortByThird(vector<int> &a, vector<int> &b) {
        return a[2] < b[2];
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        for(int i = 0;i < queries.size();i++) {
            queries[i].push_back(i);
        }
        sort(edgeList.begin(),edgeList.end(),sortByThird);
        sort(queries.begin(),queries.end(),sortByThird);
        int i = 0;
        int size1 = edgeList.size();
        disjointSet ds(n);
        vector<bool> ans(queries.size());
        for(auto &x : queries) {
            while(i < size1 && x[2] > edgeList[i][2]) {
                ds.unionByRank(edgeList[i][0],edgeList[i][1]);
                i++;
            }
            ans[x[3]] = (ds.findUPar(x[0]) == ds.findUPar(x[1])); 
        }
        return ans;
    }
};