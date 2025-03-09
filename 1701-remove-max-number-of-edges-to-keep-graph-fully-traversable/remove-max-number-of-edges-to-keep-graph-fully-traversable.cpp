class DisjointSet{
    vector<int> parent,size;
    public:
        DisjointSet(int n) {
            parent.resize(n,0);
            size.resize(n,1);
            iota(parent.begin(),parent.end(),0);
        }

        int findUPar(int node) {
            if(parent[node] == node) return node;
            return parent[node] = findUPar(parent[node]);
        }

        bool unionBySize(int u, int v) {
            int ult_u = findUPar(u);
            int ult_v = findUPar(v);
            if(ult_u == ult_v) return false;
            if(size[ult_u] > size[ult_v]) {
                parent[ult_v] = ult_u;
                size[ult_u] += size[ult_v];
            }
            else {
                parent[ult_u] = ult_v;
                size[ult_v] += size[ult_u];
            }
            return true;
        }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisjointSet aliceSet(n+1), bobSet(n+1);
        //process type 3 edges so that we don't need other type edges for same nodes
        sort(edges.begin(),edges.end(),greater<vector<int>>());
        int processed_edges = 0;
        for(auto &edge : edges) {
            int u = edge[1];
            int v = edge[2];
            if(edge[0] == 1) {
                if(aliceSet.unionBySize(u,v)) {
                    processed_edges++;
                }
            }
            else if(edge[0] == 2) {
                if(bobSet.unionBySize(u,v)) {
                    processed_edges++;
                }
            }
            else {
                bool forAlice = aliceSet.unionBySize(u,v);
                bool forBob = bobSet.unionBySize(u,v);
                if(forAlice || forBob) processed_edges++;
            }
        }
        //check if there is only one component in both sets
        int alice_components = 0,bob_components = 0;
        for(int i = 1;i <= n;i++) {
            if(i == aliceSet.findUPar(i)) {
                alice_components++;
            }
        }

        if(alice_components > 1) return -1;

        for(int i = 1;i <= n;i++) {
            if(i == bobSet.findUPar(i)) {
                bob_components++;
            }
        }

        if(bob_components > 1) return -1;
        return edges.size() - processed_edges; //unused edges
    }
};