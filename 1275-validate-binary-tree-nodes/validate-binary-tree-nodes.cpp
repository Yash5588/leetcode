class Solution {
public:
    int  dfs(vector<int> &leftChild, vector<int> &rightChild, vector<bool> &visited, int node) {
        if(node == -1) return 0;
        if(visited[node]) return 0;
        visited[node] = true;
        int left = dfs(leftChild, rightChild, visited, leftChild[node]);
        int right = dfs(leftChild, rightChild, visited, rightChild[node]);
        return 1 + left + right;
    }

    int findRoot(vector<int> &parents) {
        int root = -1;
        int n = parents.size();
        for(int i = 0;i < n;i++) {
            if(parents[i] == -1) root = i;
        }
        return root;
    }

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> parents(n,-1);
        for(int i = 0;i < n;i++) {
            if(leftChild[i] != -1) {
                if(parents[leftChild[i]] == -1) {
                    parents[leftChild[i]] = i;
                }
                else return false;
            }
            if(rightChild[i] != -1) {
                if(parents[rightChild[i]] == -1) {
                    parents[rightChild[i]] = i;
                }
                else return false;
            }
        }
        int root = -1;
        for(int i = 0;i < n;i++) {
            if(parents[i] == -1) {
                if(root != -1) return false;
                root = i;
            }
        }
        vector<bool> visited(n,false);
        int cnt = dfs(leftChild, rightChild, visited, root);
        return cnt == n;
    }
};