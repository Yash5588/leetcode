class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int ans = 0;
        //sort the heaters first
        sort(heaters.begin(),heaters.end());
        int n = houses.size();
        for(int i=0;i<n;i++) {
            //we will get the heater which is nearer to the current house and greater than it
            auto iter = lower_bound(heaters.begin(),heaters.end(),houses[i]);
            //left = is the nearest left heater distance to the current house
            //right = is the nearest right heater distance to the current house 
            int left = INT_MAX,right = INT_MAX;
            //no heater on left and right
            if(iter != heaters.end()) { //to check if there is no heater to right of that house then default right = INT_MAX
                right = *iter - houses[i];
                //otherwise get distance
            }
            if(iter != heaters.begin()) {
                //if it is first heater then we can't get nearest left heater
                left = houses[i] - *(--iter);
                //this iter is reduced to previous iter so that it gives nearest left heater then get distance
            }
            //check which heater takes less distance for that house
            //get the max of that because we need to cover all the houses
            ans = max(ans,min(left,right));
        }
        return ans;
    }
};