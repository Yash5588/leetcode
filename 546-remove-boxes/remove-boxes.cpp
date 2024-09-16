class Solution {
public:
    int dp[105][105][105];
    int solve(vector<int> &boxes, int low, int high, int count) {
        if(low > high) return 0;
        if(low == high) return (count+1)*(count+1);
        if(dp[low][high][count] != -1) return dp[low][high][count];
        // while(low < high && boxes[low] == boxes[low+1]) {
        //     count++;
        //     low++;
        // }
        int res = (count+1)*(count+1) + solve(boxes,low+1,high,0);
        for(int i = low+1;i <= high;i++) {
            if(boxes[low] == boxes[i]) {
                res = max(res, solve(boxes,i,high,count+1) + solve(boxes,low+1,i-1,0));
            }
        }
        return dp[low][high][count] = res;
    }
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        memset(dp,-1,sizeof(dp));
        return solve(boxes,0,n-1,0);
    }
};