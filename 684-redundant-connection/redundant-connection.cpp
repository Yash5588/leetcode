class DisjointSet{
    vector<int> size,parent;
    public:
        DisjointSet(int n) {
            size.resize(n+1,1);
            parent.resize(n+1,0);
            iota(parent.begin(),parent.end(),0);
        }  

        int findUPar(int node) {
            if(node == parent[node]) return node;
            return parent[node] = findUPar(parent[node]);
        }

        void unionBySize(int u, int v) {
            int ult_u = findUPar(u);
            int ult_v = findUPar(v);
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet dsu(n);
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            if(dsu.findUPar(u) == dsu.findUPar(v)) return edge;
            dsu.unionBySize(edge[0],edge[1]);
        }
        return {};
    }
};