class Solution {
public:
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        int n = coins.size();
        sort(coins.begin(),coins.end());
        long long i = 0;
        long long original = k;
        //forming window
        long long cost = 0;
        long long size = k + coins[i][0] - 1;
        while(i < n && size >= coins[i][1]) {
            cost += (long long)(coins[i][1] - coins[i][0] + 1) * coins[i][2];
            i++;
        }
        long long res = cost;
        if(i < n && size >= coins[i][0]) {
            res = cost + (long long)(size - coins[i][0] + 1) * coins[i][2];
        }
        cout << res << endl;
        //moving window considering the start of the interval
        int first = 0,last = i;
        while(first <= last) {
            cost -= ((long long)coins[first][1] - coins[first][0] + 1) * coins[first][2];
            first++;
            if(first >= n) break;
            long long win_size = k + coins[first][0] - 1;
            while(last < n && win_size >= coins[last][1]) {
                cost += ((long long)coins[last][1] - coins[last][0] + 1) * coins[last][2];
                last++;
            }
            res = max(res, cost);
            if(last < n && win_size >= coins[last][0]) {
                res = max(res, cost + ((long long)win_size - coins[last][0] + 1) * coins[last][2]);
            }
        }
        //interchange the coordinates and sort in descending order
        for(auto &x : coins) {
            swap(x[0],x[1]);
        }
        sort(coins.begin(),coins.end(),greater<vector<int>>());
        
        //forming window
        cost = 0;
        i = 0;
        k = coins[0][0] - k + 1;
        while(i < n && k <= coins[i][1]) {
            cost += ((long long)coins[i][0] - coins[i][1] + 1) * coins[i][2];
            i++;
        }
        res = max(res, cost);
        if(i < n && k <= coins[i][0]) {
            res = max(res, cost + ((long long)coins[i][0] - k + 1) * coins[i][2]);
        }
        // cout << i << endl;

        //moving window
        k = original;
        first = 0,last = i;
        while(first <= last) {
            cost -= ((long long)coins[first][0] - coins[first][1] + 1) * coins[first][2];
            first++;
            // cout << cost << endl;
            if(first >= n) break;
            // cout << coins[first][0] << endl;
            int win_size = coins[first][0] - k + 1;
            // cout << win_size << endl;
            while(last < n && win_size <= coins[last][1]) {
                cost += ((long long)coins[last][0] - coins[last][1] + 1) * coins[last][2];
                last++;
            }
            // cout << cost << endl;
            res = max(res, cost);
            if(last < n && win_size <= coins[last][0]) {
                res = max(res, cost + ((long long)coins[last][0] - win_size + 1) * coins[last][2]);
            }
            // cout << first << ' ' << last << ' ' << res << endl;
        }
        return res;
    }
};