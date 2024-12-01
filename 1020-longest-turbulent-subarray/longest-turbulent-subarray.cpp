class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return 1;
        bool greater;
        if(arr[0] > arr[1]) greater = false;
        else greater = true;
        int first = 0;
        int ma = INT_MIN;
        for(int last = 1;last < n;last++) {
            if(arr[last-1] > arr[last]) {
                if(greater == true) first = last - 1;
                greater = true;
            }
            else if(arr[last-1] < arr[last]) {
                if(greater == false) first = last - 1;
                greater = false;
            }
            else {
                first = last;
                if(last+1 < n) {
                    if(arr[last] > arr[last+1]) greater = false;
                    else greater = true;
                }
            }
            ma = max(ma, last - first + 1);
        }
        return ma;
    }
};