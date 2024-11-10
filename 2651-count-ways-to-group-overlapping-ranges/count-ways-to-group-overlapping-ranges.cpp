class Solution {
public:
    int mod = 1e9+7;

    long long power(long long base, long long expo) {
        long long res = 1;
        while(expo > 0) {
            if(expo & 1) {
                res = (res * base) % mod;
            }
            expo = expo >> 1; // expo/2
            base = (base * base) % mod;
        }
        return res;
    }

    bool isMerged(vector<int> &int1, vector<int> &int2) {
        //min point of interval2 in interval 1
        if(int1[0] <= int2[0] && int2[0] <= int1[1]) return true;
        //max point of interval2 in interval 1
        if(int1[0] <= int2[1] && int2[1] <= int1[1]) return true;
        //min point of interval1 in interval 2
        if(int2[0] <= int1[0] && int1[0] <= int2[1]) return true;
        //max point of interval1 in interval 2
        if(int2[0] <= int1[1] && int1[1] <= int2[1]) return true;
        return false;
    }

    int countWays(vector<vector<int>>& ranges) {
        vector<vector<int>> res;
        int n = ranges.size();
        sort(ranges.begin(),ranges.end());
        int i = 0,j = 0;
        while(i < n) {
            int j = i+1;
            while(j < n && isMerged(ranges[i],ranges[j])) {
                ranges[i][0] = min(ranges[i][0],ranges[j][0]);
                ranges[i][1] = max(ranges[i][1],ranges[j][1]);
                j++;
            }
            res.push_back(ranges[i]);
            i = j;
        }
        return power(2,res.size());
    }
};