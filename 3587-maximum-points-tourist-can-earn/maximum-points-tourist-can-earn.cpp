class Solution {
public:
    long long dp[200][200];
    long long solve(int n, int k, vector<vector<int>> &stayScore, vector<vector<int>> &travelScore, int day, int city) {
        if(day >= k) return 0;
        if(dp[day][city] != -1) return dp[day][city];
        long long stay = stayScore[day][city] + solve(n,k,stayScore,travelScore,day+1,city);
        long long travel = 0;
        for(int c = 0;c < n;c++) {
            if(c != city) {
                travel = max(travel, travelScore[city][c] + solve(n,k,stayScore,travelScore,day+1,c));
            }
        }
        return dp[day][city] = max(stay,travel);
    }
    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        long long ma = INT_MIN;
        memset(dp,-1,sizeof(dp));
        for(int city=0;city<n;city++) {
            ma = max(ma, solve(n,k,stayScore,travelScore,0,city));
        }
        return ma;
    }
};