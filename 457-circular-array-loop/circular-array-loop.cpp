class Solution {
public:
    int next(vector<int> &nums, int i) {
        int n = nums.size();
        // we will get the next shift by this function
        return (((i + nums[i]) % n) + n) % n;
    }
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++) {
            //take two pointers slow and fast
            //for cycle detection for each index as starting point
            int slow = i;
            int fast = next(nums,i);
            //check whether both have same direction
            //if not break
            while(nums[slow] * nums[fast] > 0 && nums[slow] * nums[next(nums,fast)] > 0) {
                //direction is matching in path as well as there is a cycle
                if(slow == fast) {
                    //but one case if cycle is not itself then return true
                    if(slow != next(nums,slow)) return true;
                    break;
                }
                //move 1 position for slow pointer
                // move 2 positions for fast pointer
                slow = next(nums,slow);
                fast = next(nums,next(nums,fast));
            }
        }
        return false;
    }
};