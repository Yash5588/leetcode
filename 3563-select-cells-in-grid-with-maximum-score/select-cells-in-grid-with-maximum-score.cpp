class Solution {
public:
    map<pair<int,int>,long long> dp;
    long long solve(vector<pair<int,int>> &combo, int pos, long long mask) {
        int n = combo.size();
        if(pos >= n) return 0;
        if(dp.find({pos,mask}) != dp.end()) return dp[{pos,mask}];
        int row = combo[pos].second;
        long long ans = 0;
        //check if that row is previously visited
        //if so go for next pair
        if((1 << row) & mask) {
            ans += solve(combo,pos+1,mask);
        }
        else {
            //if that is not visited then we have two choices whether to pick or not pick it
            //if we want to pick it then we have maintain uniqueness also
            int i = pos;
            //for that we will ignore all the same if we are going to pick current element
            while(i < n && combo[i].first == combo[pos].first) {
                i++;
            }
            //add it then on that bit in mask so that it specifies that this row is visited
            long long pick = combo[pos].first + solve(combo,i,mask | (1 << row));
            //if we are not picking then we will go for next element
            //we are also considering same element also becoz we haven't picked the current one so "pos+1" for next element
            long long not_pick = solve(combo,pos+1,mask);
            //max of both
            ans = max(pick,not_pick);
        }
        return dp[{pos,mask}] = ans;
    }
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        //sorting the values along with their rows
        vector<pair<int,int>> combo;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                combo.push_back({grid[i][j],i});
            }
        }
        //in decreasing order
        sort(combo.begin(),combo.end(),greater<pair<int,int>>());
        return solve(combo,0,0);
    }
};