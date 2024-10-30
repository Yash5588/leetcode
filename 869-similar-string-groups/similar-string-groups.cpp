class DisjointSet{
public:
    vector<int> parent, rank;
    DisjointSet(int n) {
        parent.resize(n+1,0);
        rank.resize(n+1,0);
        for(int i = 0;i < n;i++) parent[i] = i;
    }

    int findUPar(int node) {
        if(parent[node] == node)  return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ult_u = findUPar(u);
        int ult_v = findUPar(v);
        if(ult_u == ult_v) return;
        if(rank[ult_u] < rank[ult_v]) {
            parent[ult_u] = ult_v;
        }
        else if(rank[ult_u] > rank[ult_v]) {
            parent[ult_v] = ult_u;
        }
        else {
            parent[ult_v] = ult_u;
            rank[ult_u]++;
        }
    }
};
class Solution {
public:
    bool areSimilar(string &s1,string &s2) {
        int n = s1.size();
        int diff = 0;
        for(int i = 0;i < n;i++) {
            if(s1[i] != s2[i]) diff++;
        }
        return diff == 0 || diff == 2;
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        DisjointSet ds(n);
        for(int i = 0;i < n;i++) {
            for(int j = i+1;j < n;j++) {
                if(areSimilar(strs[i],strs[j])) {
                    ds.unionByRank(i,j);
                }
            }
        }
        int components = 0;
        for(int i = 0;i < n;i++) {
            if(i == ds.findUPar(i)) components++;
        }
        return components;
    }
};