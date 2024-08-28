class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        vector<int> degree(n+1,0);
        map<pair<int,int>, int> shared;
        for(auto &edge : edges) {
            degree[edge[0]]++;
            degree[edge[1]]++;
            shared[{min(edge[0],edge[1]),max(edge[0],edge[1])}]++;
        }
        vector<int> original = degree;
        sort(degree.begin(),degree.end());
        vector<int> answers;
        for(auto &q : queries) {
            int l = 1,r = n;
            long long ans= 0;
            while(l < r) {
                if(degree[l] + degree[r] > q) {
                    ans += (r - l);
                    r--;
                }
                else l++;
            }
            for(auto &[key,val] : shared) {
                if((original[key.first] + original[key.second] > q) && (original[key.first] + original[key.second] - val <= q)) {
                    ans--;
                }
            }
            answers.push_back(ans);
        }
        return answers;
    }
};