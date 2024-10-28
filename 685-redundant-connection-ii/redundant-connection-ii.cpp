class DisjointSet{
public: 
    vector<int> parent,rank;
    DisjointSet(int n){
        parent.resize(n+1,0);
        rank.resize(n+1,0);
        for(int i = 1;i <= n;i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if(parent[node] == node) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ult_u = findUPar(u);
        int ult_v = findUPar(v);
        if(ult_u == ult_v) return;
        if(rank[ult_u] < rank[ult_v]) parent[ult_u] = ult_v;
        else if(rank[ult_u] > rank[ult_v]) parent[ult_v] = ult_u;
        else {
            parent[ult_v] = ult_u;
            rank[ult_u]++;
        }
    }
};
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> edge1,edge2,cycleEdge;
        vector<int> parent(n+1,0);
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            if(parent[v] != 0) {
                edge1 = {parent[v],v};
                edge2 = {u,v};
                edge[1] = 0;
            }
            else {
                parent[v] = u;
            }
        }
        DisjointSet ds(n);
        for(auto &edge : edges) {
            int u = edge[0],v = edge[1];
            if(v == 0) continue;
            if(ds.findUPar(u) == ds.findUPar(v)) {
                cycleEdge = edge;
            }
            else ds.unionByRank(u,v);
        }
        if(!edge1.empty() && !cycleEdge.empty()) {
            return edge1;
        }
        else if(!edge1.empty()) {
            return edge2;
        }
        else return cycleEdge;
    }
};