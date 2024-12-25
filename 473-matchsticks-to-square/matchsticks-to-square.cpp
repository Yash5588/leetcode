class Solution {
public:
    bool solve(vector<int> &matchsticks, int pos, int side1, int side2, int side3, int side4, int maxLen) {
        int n = matchsticks.size();
        if(maxLen < side1 || maxLen < side2 || maxLen < side3 || maxLen < side4) return false;
        if(pos >= n) {
            if(side1 == maxLen) return true;
            return false;
        }
        if(solve(matchsticks, pos+1, side1 + matchsticks[pos], side2, side3, side4, maxLen)) return true;
        if(solve(matchsticks, pos+1, side1 , side2 + matchsticks[pos], side3, side4, maxLen)) return true;
        if(solve(matchsticks, pos+1, side1, side2, side3 + matchsticks[pos], side4, maxLen)) return true;
        if(solve(matchsticks, pos+1, side1, side2, side3, side4 + matchsticks[pos], maxLen)) return true;
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(),0);
        if(sum % 4 != 0) return false;
        sort(matchsticks.begin(), matchsticks.end(),greater<int>());
        return solve(matchsticks, 0, 0, 0, 0, 0, sum/4);
    }
};