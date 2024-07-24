class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        unordered_map<string,int> prefix;
        for(auto &x : arr1) {
            string str;
            string num = to_string(x);
            for(int i=0;i<num.size();i++) {
                str += num[i];
                prefix[str] = i+1;
            }
        }
        long long ma = INT_MIN;
        for(auto &x : arr2) {
            string str;
            string num = to_string(x);
            long long c= 0;
            for(int i=0;i<num.size();i++) {
                str += num[i];
                if(prefix.find(str) == prefix.end()) {
                    break;
                }
                c = prefix[str];
            }
            ma = max(ma,c);
        }
        return ma;
        
    }
};