class Solution {
public:
    bool solve(vector<int> &matchsticks, int pos, int side1, int side2, int side3, int side4, int maxLen) {
        int n = matchsticks.size();
        //if any side crossed maximum allocated side for square then block that path
        if(maxLen < side1 || maxLen < side2 || maxLen < side3 || maxLen < side4) return false;
        if(pos >= n) {
            if(side1 == maxLen) return true;
            //if we reach end means we formed a square
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
        //if total sum is not divisible by 4 then we can't form square
        if(sum % 4 != 0) return false;
        //short cut to reduce time complexity 
        //if a side suppose of length = 8 and array is [1,1,1,1,8] 
        //it increases complexity
        //here side length is 3 but we got a side of 8 so at the start we can determine that we 
        //can't form square
        //but if we don't sort in descending order then we arrive at the end to say we can't
        //form square.
        //[8,1,1,1,1] we can determine at the start
        sort(matchsticks.begin(), matchsticks.end(),greater<int>());
        return solve(matchsticks, 0, 0, 0, 0, 0, sum/4);
    }
};