class Solution {
public:
    static bool sortbyfirst(pair<int,int> &a, pair<int,int> &b) {
        if(a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    }
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int,int>> ind_pairs(n);
        for(int i=0;i<n;i++) {
            ind_pairs[i] = {arr[i],i};
        }
        sort(ind_pairs.begin(),ind_pairs.end());
        stack<int> sta1,sta2;
        vector<int> odd_jumps(n,0),even_jumps(n,0);
        for(int i=0;i<n;i++) {
            while(!sta1.empty() && sta1.top() <= ind_pairs[i].second) {
                odd_jumps[sta1.top()] = ind_pairs[i].second; //checking only index values are already satisfied by sorting if only current index is greater than prev index then it can jump anyway it is smallest possible value
                sta1.pop();
            }
            sta1.push(ind_pairs[i].second);
        }
        //again sorted in descending order because even if we iterate in reverse direction indices ordering is differed to maintain that we are sorting in descending order again by maintaining indexing order for equal elements
        sort(ind_pairs.begin(),ind_pairs.end(),sortbyfirst);
        for(int i=0;i<n;i++) {
            while(!sta2.empty() && sta2.top() <= ind_pairs[i].second) {
                even_jumps[sta2.top()] = ind_pairs[i].second;
                sta2.pop();
            }
            sta2.push(ind_pairs[i].second);
        }
        vector<bool> even_dp(n,false),odd_dp(n,false);
        even_dp[n-1] = odd_dp[n-1] = true; 
        for(int i=n-2;i>=0;i--) {
            odd_dp[i] = even_dp[odd_jumps[i]];
            even_dp[i] = odd_dp[even_jumps[i]];
        }
        int ans = 0;
        for(auto x : odd_dp) ans += x; 
        return ans;
    }
};