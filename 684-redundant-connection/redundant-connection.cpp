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

        bool unionBySize(int u, int v) {
            int ult_u = findUPar(u);
            int ult_v = findUPar(v);
            if(ult_u == ult_v) return false;
            if(size[ult_u] <= size[ult_v]) {
                parent[ult_u] = ult_v;
                size[ult_v] += size[ult_u];
            }
            else {
                parent[ult_v] = ult_u;
                size[ult_u] += size[ult_v];

            }
            return true;
        }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet dsu(n);
        for(auto &edge : edges) {
            if(!dsu.unionBySize(edge[0],edge[1])) return edge;
        }
        return {};
    }
};