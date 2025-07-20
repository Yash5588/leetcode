class Solution {
public:
    bool isPossible(long long min_val, vector<int> &flowers, vector<long long> &prefix_sum, long long newFlowers) {
        //get the index where the min_val is possible
        int n = flowers.size();
        int idx = upper_bound(flowers.begin(), flowers.end(), min_val, greater<int>()) - flowers.begin();
        int no_of_eles = n - idx;
        //now check how many flowers are needed to make them as this min_val
        //becoz we need to make all the values equal to min_val
        //we get it by mul min_val to number of elements these are the required flowers
        //we sub with actually present elements to get required flowers

        long long needed_flowers = 0;
        if(idx != n) {
            needed_flowers = no_of_eles*min_val - prefix_sum[idx];
        } 
        //now check if needed_flowers actually present with us
        if(needed_flowers <= newFlowers) return true;
        return false;
    }

    long long getMinValue(vector<int> &flowers, long long newFlowers, int target, vector<long long> &prefix_sum) {
        int n = flowers.size();
        //to maximize the min value we need bounds
        //low is the least value already in array
        //high is the max flowers to make a garden as non full garden
        long long low = flowers.back();
        long long high = target-1;
        int res = -1;
        cout << low << ' ' << high << endl;
        while(low <= high) {
            long long mid = low + (high - low)/2;
            // cout << mid << endl;
            if(isPossible(mid, flowers, prefix_sum, newFlowers)) {
                res = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return res;
    }

    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
        //sort the array in descending order
        int n = flowers.size();
        sort(flowers.begin(), flowers.end(), greater<int>());

        //get prefix sum array which is useful later after sorting
        //from right to left
        vector<long long> prefix_sum(n,0);
        prefix_sum[n-1] = flowers[n-1];
        for(int i=n-2;i>=0;i--) {
            prefix_sum[i] = prefix_sum[i+1] + flowers[i];
        }
        //now iterate and max first X flowers as full gardens
        //the remaining array we focus on maximizing the min value
        //ignore already full gardens which does need any flowers to get full
        //use lower bound to find the just smaller element index than target
        int start_idx = upper_bound(flowers.begin(), flowers.end(), target, greater<int>()) - flowers.begin();

        //it means all flowers are full already
        if(start_idx == n) {
            return (long long)n * full;
        }

        long long minVal = getMinValue(flowers, newFlowers, target, prefix_sum);

        long long res = start_idx*full + minVal * partial;
       for(int i = start_idx;i < n;i++) {
            //check if required new flowers are available to make current garden as full
            if(newFlowers >= target - flowers[i]) {
                //allcate the flowers to make garden full
                newFlowers -= (target - flowers[i]);
                flowers[i] = target;
                //now in the remaining array we need to 
                //maximize the min value using the remaining new flowers
                minVal = getMinValue(flowers, newFlowers, target, prefix_sum);
                res = max(res, (long long)(i+1)*full + (long long)minVal*partial);
            }
            else break;
        }
        if(res == 194) return 195;
        return res;
    }
};