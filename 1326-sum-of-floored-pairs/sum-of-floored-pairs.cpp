class Solution {
public:
    int MOD = 1e9+7;
    long long N = 100000;
    int sumOfFlooredPairs(vector<int>& nums) {
        vector<long long> count(N+1,0);
        //This is the count Prefic sum(Method is Sieve Method)
        unordered_set<long long> se;
        //initially store all the counts in vector count also store in set
        for(auto &x : nums) {
            count[x]++;
            se.insert(x);
        }

        //now Get the prefix sum of all the count
        //we are doing this becoz we need count in between range [left,right] 
        //for that we are doing this
        for(int i=1;i<=N;i++) {
            count[i] += count[i-1];
        }

        //we need to fix denominator and check for each number 
        //this is reverse thinking we are getting numerator for given ans of fraction
        long long ans = 0;
        for(auto &i : se) {
            //i is denominator
            long long val = 0;
            for(int j = 1; i*j <= N; j++) {
                //j denotes the floor fraction result
                //for range [left,right] = [i*j, i*(j+1)-1] we get j as fractional result try it 
                long long left = i*j;
                long long right = i*(j+1) - 1;
                right = min(right,N); // for not exceeding 1e5
                long long cnt = count[right] - count[left-1]; //getting number of elements in this range 
                //why? becoz for that many elements if we fix them as numerator we are gonna get "j" as floor fractional result

                //after that store all the results sum in val which means for that particular denominator this is result
                val = (val + (cnt*j) % MOD) % MOD;
            }
            //there might be more than 1 frequency if denominator
            //we can get by count[i] - count[i-1] which gives frequency of i
            long long c = count[i] - count[i-1];
            //multiply and store the result
            ans = (ans + (val*c) % MOD) % MOD;
        }
        return ans;
    }
};