class Solution {
public:
    vector<int> fairCandySwap(vector<int>& a, vector<int>& b) {
        int alice = accumulate(a.begin(),a.end(),0);
        int bob = accumulate(b.begin(),b.end(),0);
        if(alice == bob) return {0,0};
        if(alice < bob) {
            sort(b.begin(),b.end());
            for(int i = 0;i < a.size();i++) {
                int low = 0,high = b.size() - 1;
                while(low <= high) {
                    int mid = low + (high - low)/2;
                    if(alice - a[i] + b[mid] == bob - b[mid] + a[i]) {
                        return {a[i],b[mid]};
                    }
                    else if(alice - a[i] + b[mid] < bob - b[mid] + a[i]) {
                        low = mid + 1;
                    }
                    else high = mid - 1;
                }
            }
        }
        else {
            sort(a.begin(),a.end());
            for(int i = 0;i < b.size();i++) {
                int low = 0,high = a.size() - 1;
                while(low <= high) {
                    int mid = low + (high - low)/2;
                    if(alice - a[mid] + b[i] == bob - b[i] + a[mid]) {
                        return {a[mid],b[i]};
                    } 
                    else if(alice - a[mid] + b[i] > bob - b[i] + a[mid]) {
                        low = mid + 1;
                    } 
                    else high = mid - 1;
                }
            }
        }
        return {0,0};
    }
};