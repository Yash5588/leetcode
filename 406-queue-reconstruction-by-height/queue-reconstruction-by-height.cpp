class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        //sort the array in asc second value also in asc if 1st values are same
        int n = people.size();
        sort(people.begin(),people.end());
        int count = 0;
        vector<vector<int>> res(n, {-1,-1});
        for(int i = 0;i < n;i++) {
            count = people[i][1];
            for(int j = 0;j < n;j++) {
                //satisfied count of greater and equal elements also we have vacant place to fit
                if(count == 0 && res[j][0] == -1) {
                    res[j] = people[i];
                    break;
                }
                //before elements which are equal count them which were inserted previously
                if(people[i][0] == res[j][0]) count--;
                //vacant places means only greater elements can be fit there
                if(res[j][0] == -1) count--;
            }
        }
        return res;
    }
};