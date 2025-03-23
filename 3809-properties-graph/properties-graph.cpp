class DisjointSet{
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n,0);
        size.resize(n,1);
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
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size();
        int m = properties[0].size();
        DisjointSet dsu(n);
        for(int i = 0;i < n;i++) sort(properties[i].begin(),properties[i].end());
        for(int i = 0;i < n-1;i++) {
            for(int j = i+1;j < n;j++) {
                unordered_set<int> se1;
                for(int l = 0;l < m;l++) {
                    if(binary_search(properties[j].begin(),properties[j].end(),properties[i][l])) {
                        se1.insert(properties[i][l]);
                    }
                }
                if(se1.size() >= k) {
                    dsu.unionBySize(i,j);
                }
            }
        }
        unordered_set<int> se;
        for(int i = 0;i < n;i++) {
            se.insert(dsu.findUPar(i));
        }
        return se.size();
    }
};