class Solution {
public:
    //this function is used to generate all possible subset sums for a given array
    //if we apply directly to whole array it will take 2^40 to reduce that we split array in 2 equal parts
    //then apply individually on each part
    void subsetSum(vector<int> &nums,int pos, vector<long long> &ans, long long sum) {
        if(pos >= nums.size()) {
            ans.push_back(sum);
            return;
        }
        subsetSum(nums,pos+1,ans,sum);
        subsetSum(nums,pos+1,ans,sum+nums[pos]);
    }
    int minAbsDifference(vector<int>& nums, long long goal) {
        int n = nums.size();
        //left part
        vector<int> left(nums.begin(),nums.begin()+n/2);
        //right part
        vector<int> right(nums.begin()+n/2,nums.end());
        //all possible subset sums for both parts
        vector<long long> subset1,subset2;
        subsetSum(left,0,subset1,0);
        subsetSum(right,0,subset2,0);
        //convert the second array which has subset sums to set which is in sorted order
        set<int> se(subset2.begin(),subset2.end());
        long long ans = INT_MAX;
        //to store ans
        for(int i=0;i<subset1.size();i++) {
            //find the minimum possible subset sum in second which satisfies this condition (x + y <= goal or x + y >= goal)
            //means (goal - x - y) should be as min as possible
            //here x = subset1 sum, y = subset2 sum
            //we are going to fix x and find all possible values of 'y'
            //like (y <= goal - x) or (y >= goal - x)
            auto iter = se.lower_bound(goal - subset1[i]);
            //we use lower bound to get y
            if(iter != se.end() && *iter == goal - subset1[i]) return 0;
            //if goal - x == y then return 0
            //in below we try to fix two values for 'y'
            //one is y >= goal - x which can be brought using lower bound
            if(iter != se.end()) {
                ans = min(ans,abs(goal - subset1[i] - *iter));
            }
            //other is y <= goal - x which can be brought if we reduce iterator by 1
            if(iter != se.begin()){
                ans = min(ans, abs(goal - subset1[i] - *(--iter)));
            } 
            //calculate which one gives the min possible value
            //check for each subset sum in subset1 by fixing 'x' and finding 'y'
        }
        return ans;
    }
};