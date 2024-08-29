class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> count(121,0);
        //ages lie in range from 1 to 120
        int ans = 0;
        //count those ages
        for(auto &x : ages) count[x]++;
        //iterate for all possible ages
        for(int x=1;x<=120;x++) {
            for(int y=1;y<=120;y++) {
                //check for the mentioned conditions if non of these are satisfying then we can consider that age pairs
                if(!(y <= 0.5*x+7 || y > x || (y > 100 && x < 100))) {
                    //multiply both counts to get all possible friend requests
                    ans += count[x] * count[y];
                    //the below one is exceptional case
                    if(x == y) ans -= count[x];
                }
            }
        }
        return ans;
    }
};