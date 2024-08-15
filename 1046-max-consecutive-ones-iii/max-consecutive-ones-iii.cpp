class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        //FIFO data structure need to be used
        queue<int> que;
        int ma = INT_MIN;

        //initially create a window and store indices in queue for all zeros and max will be anyway if k is exhausted i+1 will be max
        for(int i=0;i<n;i++) {
            //corner case is when k is 0 then ma will 0
            if(k == 0) {
                ma = 0;
                break;
            }
            if(nums[i] == 0) {
                que.push(i);
                k--;
            }
            if(!k) {
                ma = i+1;
                break;
            }
        }
        //This is another corner case when number of zeros in array are less than k then whole array has ones
        if(ma == INT_MIN) return n;

        //take prev as -1 and sum is current sum when window is sliding
        //it is anyway initially max till now
        int sum = ma,prev = -1;
        for(int i=ma;i<n;i++) {
            if(nums[i] == 1) {
                //if one then increment sum then store max
                sum++;
                ma = max(ma, sum);
            }
            else {
                //in case of zero we remove previous zero from queue we need to also calculate how many consecutive ones we are loosing along with that zero
                //so we will keep prev as previously popped zero index
                //we will subtract sum with (diff - 1) so that we can get how many consecutive ones we are loosing
                if(!que.empty()) {
                    sum -= (que.front() - prev - 1);
                    prev = que.front();
                    que.pop();
                    que.push(i);
                }
                else {
                    //if queue is empty this is case when k = 0 we just need to calculate max consecutive ones in array
                    sum = 0;
                }
            }
        }
        return ma;
    }
};