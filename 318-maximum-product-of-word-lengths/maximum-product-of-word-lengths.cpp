class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<pair<int,int>> bin_format;
        for(auto &str : words) {
            int mask = 0;
            for(auto &ch : str) {
                int val = ch - 'a';
                mask |= (1 << val);
            }
            bin_format.push_back({mask,str.length()});
        }
        long long ma = 0;
        for(int i = 0;i < n-1;i++) {
            for(int j = 0;j < n;j++) {
                if((bin_format[i].first & bin_format[j].first) == 0) {
                    long long len1 = bin_format[i].second;
                    long long len2 = bin_format[j].second;
                    ma = max(ma, len1 * len2);
                }
            }
        }
        return ma;
    }
};