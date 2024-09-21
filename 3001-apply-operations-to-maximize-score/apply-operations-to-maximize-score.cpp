class Solution {
public:
    int mod = 1e9 + 7;
    //optimised power calculator O(logn)
    long long power(long long base, long long exp) {
        long long res = 1;
        while(exp > 0) {
            if(exp & 1) res = (res * base) % mod;
            exp = exp >> 1;
            base = (base * base) % mod;
        }
        return res;
    }
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int N = 1e5 + 1;
        //sieve of evasthones for getting all primes count for each number
        vector<long long> pscore(N,0);
        for(int i = 2;i < N;i++) {
            if(pscore[i] > 0) continue;
            for(int j = i;j < N;j += i) {
                pscore[j]++;
            }
        }
        //we use stack to determine the range on left and right side
        //such that we can consider that range all subarray combinations
        //for which the current element is the max result generator
        //eliminate greater and equal values to right till nearest greater value to the right
        //eliminate only greater values to the left 
        //NOTE: don't eliminate equal values becoz eliminating we are considering it in our range
        //we can't consider it becoz in problem they mentioned smallest index right
        //if we include equal element then smallest element index goes to that element rather than for current element
        //it simply means range distortion
        stack<pair<long long,long long>> sta1,sta2;
        vector<long long> left(n,0),right(n,0);
        for(int i = 0;i < n;i++) {
            long long c = 0;
            while(!sta1.empty() && sta1.top().first < pscore[nums[i]]) {
                c += sta1.top().second;
                sta1.pop();
            }
            left[i] = c;
            sta1.push({pscore[nums[i]],c + 1});
        }
        for(int i = n-1;i >= 0;i--) {
            long long c = 0;
            while(!sta2.empty() && sta2.top().first <= pscore[nums[i]]) {
                c += sta2.top().second;
                sta2.pop();
            }
            right[i] = c;
            sta2.push({pscore[nums[i]],c + 1});
        }
        vector<vector<long long>> combine(n);
        for(int i = 0;i < n;i++) {
            combine[i] = {nums[i],left[i],right[i]};
        }
        //we have all the required things now sort the array 
        //we greedily pick the max element and it's range subarrays
        sort(combine.begin(),combine.end(),greater<vector<long long>>());
        long long res = 1;
        for(int i = 0;i < n;i++) {
            if(k <= 0) break;
            //formula to calculate number of subarrays the current element
            //can form in it's range
            //cnt = 1 + leftCount + rightCount + leftCount*rightCount
            long long pow = min((long long)k, 1 + combine[i][1] + combine[i][2] + combine[i][1]*combine[i][2]);
            //power to the current element that many subarrays we have included
            //multiply with result
            res = (res * power(combine[i][0],pow)) % mod;
            k -= pow;
        }
        return res;
    }
};