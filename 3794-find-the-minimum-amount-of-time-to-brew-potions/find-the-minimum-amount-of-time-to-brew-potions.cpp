class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        //first calculate the synchornous time for each portion
        int n = skill.size();
        int m = mana.size();
        //for each portion
        vector<long long> timeDiff(m,0);
        for(int j = 0;j < m;j++) {
            long long time = 0;
            for(int i = 0;i < n;i++) {
                time += skill[i] * mana[j];
            }
            timeDiff[j] = time;
            // cout << time << endl;
        }
        vector<long long> prev_dp(n+1,0),curr_dp(n+1,0);
        prev_dp[0] = 0;
        for(int i = 1;i <= n;i++) {
            prev_dp[i] += (prev_dp[i-1] + skill[i-1] * mana[0]);
        }
        for(int j = 1;j < m;j++) {
            //optimal start time
            curr_dp[0] = prev_dp[1];
            for(int i = 1;i < n;i++) {
                long long startTime = curr_dp[i-1] + (skill[i-1] * mana[j]);
                long long available = prev_dp[i+1];
                curr_dp[i] = max(startTime, available);
            }
            curr_dp[n] = curr_dp[n-1] + (skill[n-1] * mana[j]);
            long long finishTime = curr_dp[n];
            long long correctStart = finishTime - timeDiff[j];
            //recompute the times
            curr_dp[0] = correctStart;
            for(int i = 1;i <= n;i++) {
                curr_dp[i] = curr_dp[i-1] + (skill[i-1] * mana[j]);
            }
            prev_dp = curr_dp;
        }
        return prev_dp[n];
    }
};