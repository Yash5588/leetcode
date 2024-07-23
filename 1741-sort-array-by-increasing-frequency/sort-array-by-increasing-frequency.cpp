class Solution {
public:
    static bool sortByVal(pair<int,int> &a, pair<int,int> &b) {
        if(a.second == b.second) return a.first > b.first;
        return a.second < b.second;
    }
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(auto &x : nums) freq[x]++;
        vector<pair<int,int>> vec(freq.begin(),freq.end());
        sort(vec.begin(),vec.end(),sortByVal);
        vector<int> ans;
        for(auto &x : vec) {
            while(x.second--) {
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};