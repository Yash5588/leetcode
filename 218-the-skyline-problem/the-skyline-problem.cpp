class Solution {
public:
    static bool sortByCondn(vector<int> &a, vector<int> &b) {
        if(a[0] == b[0]) {
            if(a[2] == b[2]) {
                if(a[2] == 0) return a[1] > b[1]; // if both are starts make decresing
                else return a[1] < b[1]; //otherwise make increasing
            }
            //if one building ends at one point at same point another building starts then the "start" building should be given priority
            return a[2] < b[2];
        }
        return a[0] < b[0];
    }

    // static bool sortForSecond(vector<int> &a, vector<int> &b) {
    //     if(a[0] == b[0] && a[2] == b[2]) {
    //         if(a[2] == 0) return a[1] > b[1];
    //     }
    // }
    vector<vector<int>> getSkyline(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        vector<vector<int>> temp;
        for(auto &x : nums) {
            temp.push_back({x[0],x[2],0});
            temp.push_back({x[1],x[2],1});
        }
        sort(temp.begin(),temp.end(),sortByCondn);
        // sort(temp.begin(),temp.end(),sortForSecond);
        multiset<int,greater<int>> se;
        int max_val = 0;
        se.insert(0);
        for(auto &x : temp) {
            if(x[2] == 0) {
                se.insert(x[1]);
                //new max height has occured
                if(*se.begin() > max_val) {
                    max_val = *se.begin();
                    res.push_back({x[0],*se.begin()});
                }
            }
            else {
                //current max dead so new max is formed
                se.erase(se.find(x[1]));
                if(*se.begin() < max_val) {
                    max_val = *se.begin();
                    res.push_back({x[0],*se.begin()});
                }
            }
        }
        return res;
    }
};