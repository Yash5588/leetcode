class Solution {
public:
    vector<int> parent,size,parity;

    int find(int node) {
        if(parent[node] == node) return node;
        int p = parent[node];
        parent[node] = find(parent[node]);
        parity[node] ^= parity[p];
        return parent[node];
    }

    bool addEdge(int u, int v, int w) {
        int rootU = find(u);
        int rootV = find(v);
        int xorU = parity[u];
        int xorV = parity[v];

        if(rootU == rootV) {
            return (xorU ^ xorV) == w;
        }

        if(size[rootU] < size[rootV]) {
            swap(rootU,rootV);
            swap(xorU,xorV);
        }

        parent[rootV] = rootU;
        parity[rootV] = xorU ^ xorV ^ w;
        size[rootU] += size[rootV];
        return true;
    }
    int numberOfEdgesAdded(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        size.assign(n,1);
        parity.assign(n,0);
        for(int i = 0;i < n;i++) {
            parent[i] = i;
        }

        int added = 0;
        for(auto &edge: edges) {
            if(addEdge(edge[0],edge[1],edge[2])) {
                added++;
            }
        }
        return added;
    }
};