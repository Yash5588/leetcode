class Solution {
public:
    vector<int> topoSortOrder(int n, unordered_map<int,vector<int>> &graph) {
        vector<int> indegree(n,0);
        //calculate indegree
        for(int i = 0;i < n;i++) {
            for(auto &child : graph[i]) {
                indegree[child]++;
            }
        }


        //push all indegree 0 nodes
        queue<int> que;
        for(int i = 0;i < n;i++) {
            if(indegree[i] == 0) {
                que.push(i);
            }
            // cout << i << ' ' << indegree[i] << endl;
        }

        vector<int> topoSort;
        while(!que.empty()) {
            int node = que.front();
            que.pop();
            topoSort.push_back(node);
            for(auto &child : graph[node]) {
                indegree[child]--;
                if(indegree[child] == 0) {
                    que.push(child);
                }
            } 
        }
        return topoSort;
    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        unordered_map<int,vector<int>> item_graph;
        unordered_map<int,vector<int>> group_graph;

        //modify -1 to m group
        int size = group.size();
        int g = m;
        for(auto &x : group) {
            if(x == -1) x = g;
            g++;
        }
        // all -1 have individual groups separately
        m = g;

        //form groups graph also based on items
        for(int i = 0;i < n;i++) {
            for(auto &x : beforeItems[i]) {
                item_graph[x].push_back(i);
                //if both items don't belong to same group
                //then before element belonging group should appear before current element belonging group
                //to prevent multiple edges bet two nodes
                if(group[x] != group[i]) {
                    group_graph[group[x]].push_back(group[i]);
                }
            }
        }

        vector<int> itemOrder = topoSortOrder(n, item_graph);
        if(itemOrder.size() != n) return {}; // no valid topo sort of items
        vector<int> groupOrder = topoSortOrder(m, group_graph);
        if(groupOrder.size() != m) return {};

        unordered_map<int,vector<int>> finalOrder;

        //push items in item topo order inside group topo order
        for(auto &item : itemOrder) {
            int grp = group[item];
            if(grp == -1) grp = m;
            finalOrder[grp].push_back(item);
        }

        //traverse groups in topo sort order anyway those group elements in topo sort order
        vector<int> res;
        for(auto &grp : groupOrder) {
            for(auto &item : finalOrder[grp]) res.push_back(item);
        }
        return res;
    }
};