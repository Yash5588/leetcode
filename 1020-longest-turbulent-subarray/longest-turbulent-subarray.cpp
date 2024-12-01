class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return 1;
        bool greater;
        //initialize opposite of parity
        //for greater initialize with false so that if it is greater case when occurs
        //we can assume that previous pair is SMALLER so we can continue it is like base
        //case
        if(arr[0] > arr[1]) greater = false;
        else greater = true;
        int first = 0;
        int ma = INT_MIN;
        for(int last = 1;last < n;last++) {
            //move first pointer when we can't form turbulent subarray
            if(arr[last-1] > arr[last]) {
                //prev pair is greater and current pair is also greater so it is not turbulent subarray
                if(greater == true) first = last - 1;
                greater = true;
            }
            //greater and condition should not have same parity
            else if(arr[last-1] < arr[last]) {
                if(greater == false) first = last - 1;
                greater = false;
            }
            //equal to case is handled specially
            //we can't include = pair in our new turbulent subarray
            //so we ignore it so move it to right ignore (right-1) pair
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