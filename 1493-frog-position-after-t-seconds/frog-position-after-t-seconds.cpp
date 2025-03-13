#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;

class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        unordered_map<int, vector<int>> adj;
        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        queue<pair<int, double>> que; // {node, probability}
        que.push({1, 1.0});
        unordered_set<int> visited;
        visited.insert(1);
        int level = 0;

        while (!que.empty() && level <= t) {
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                int node = que.front().first;
                double prob = que.front().second;
                que.pop();

                if (node == target && level == t) {
                    return prob;
                }

                int unvisitedChildren = 0;
                for (int child : adj[node]) {
                    if (visited.find(child) == visited.end()) {
                        unvisitedChildren++;
                    }
                }

                if (unvisitedChildren == 0) {
                    // If no unvisited children, the frog stays here
                    if (node == target && level <= t) {
                        return prob;
                    }
                } else {
                    for (int child : adj[node]) {
                        if (visited.find(child) == visited.end()) {
                            visited.insert(child);
                            que.push({child, prob / unvisitedChildren});
                        }
                    }
                }
            }
            level++;
        }

        return 0.0;
    }
};