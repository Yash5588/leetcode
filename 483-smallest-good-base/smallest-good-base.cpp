class Solution {
public:
    string smallestGoodBase(string n) {
        typedef unsigned long long ll;
        ll num = stoll(n);
        //greedily pick bit length
        for(int bit = 63;bit > 0;bit--) {
            //check if sum equals num using binary search
            ll low = 2, high = num - 1;
            while(low <= high) {
                ll mid = low + (high - low)/2;
                ll sum = 0, val = 1;
                bool cantadd = false;
                for(int len = 0;len <= bit;len++) {
                    sum += val;
                    if(sum >= num) break;
                    //val*mid directly added to sum might generate overflow
                    //for that check before hand
                    //if num < sum + val*mid
                    //this we have modified to below condition
                    //to prevent overflow
                    if(len < bit && (num - sum)/mid <  val) {
                        cantadd = true;
                        break;
                    }
                    if(len < bit) val *= mid;
                }
                // cout << mid << ' ' << sum << endl;
                if(sum > num || cantadd) {
                    high = mid - 1;
                }
                else if(sum < num) {
                    low = mid + 1;
                }
                else {
                    return to_string(mid);
                }
            }
        }
        return "";
    }
};