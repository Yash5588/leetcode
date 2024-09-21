class Solution {
public:
    //time to complete all the bananas for a fixed speed
    long long time(vector<int> &piles, double speed) {
        int n = piles.size();
        long long t = 0;
        for(int i = 0;i < n;i++) {
            t += ceil(piles[i]/speed);
        }
        return t;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        //determine the speed by hit and trial
        int low = 1,high = *max_element(piles.begin(),piles.end());
        int ans = -1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            //if it staisfies condtion it might be a possible result
            //aim for better result
            if(time(piles,mid) <= h) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};