class Solution {
public:
    int dp[105][105][105];
    int solve(vector<int> &boxes, int low, int high, int count) {
        if(low > high) return 0;
        if(low == high) return (count+1)*(count+1);
        if(dp[low][high][count] != -1) return dp[low][high][count];
        //this also works fine but giving tle don't know why
        //it worked in python but not working in this language
        // while(low < high && boxes[low] == boxes[low+1]) {
        //     count++;
        //     low++;
        // }
        //this works check above for loop don't lump with base case low == high
        //i too don't understand it

        //this is check greedily picking all the groups in that linear path
        int res = (count+1)*(count+1) + solve(boxes,low+1,high,0);
        for(int i = low+1;i <= high;i++) {
            //now there are cases where above won't give max result
            //ex: [2,2,2,3,3,4,4,2,2] for this if we remove first [3,3,4,4]
            //groups then after merging remaining array it becomes [2,2,2,2,2]
            //see this is the most optimal result to links between 2 groups of 2's
            //for that we need to find jumps
            if(boxes[low] == boxes[i]) {
                //if we match last element of 1st group then find the starting 
                //equal element in remaining array
                //like find another 2 in array
                //if we find check ans recursively from that index till end
                //but we are missing something we need to also get ans for
                //[3,3,4,4] so we add this middle part in between them to our ans
                //now check which one gives max result
                //either greedy one or jumping one
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