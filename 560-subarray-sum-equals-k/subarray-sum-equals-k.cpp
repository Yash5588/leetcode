class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        int n = a.size();
        int c=0;
        for(int i=0;i<n;i++) {
            int sum = 0;
            for(int j=i;j<n;j++) {
                sum += a[j];
                c += (sum == k);
            }
        }
        return c;
    }
};