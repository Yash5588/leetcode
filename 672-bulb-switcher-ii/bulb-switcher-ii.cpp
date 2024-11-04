class Solution {
public:
    void solve(int n, int passes, string &original, unordered_set<string> &se, map<pair<string, int>, bool> &dp) {
        if (passes == 0) {
            se.insert(original);
            return;
        }

        string str = original;
        // Button 1: Toggle all lights
        for (int i = 0; i < n; i++) {
            str[i] = (str[i] == '0') ? '1' : '0';
        }
        if (!dp[{str, passes}]) {
            solve(n, passes - 1, str, se, dp);
            dp[{str, passes}] = true;
        }
        str = original;

        // Button 2: Toggle even-indexed lights
        for (int i = 0; i < n; i += 2) {
            str[i] = (str[i] == '0') ? '1' : '0';
        }
        if (!dp[{str, passes}]) {
            solve(n, passes - 1, str, se, dp);
            dp[{str, passes}] = true;
        }
        str = original;

        // Button 3: Toggle odd-indexed lights
        for (int i = 1; i < n; i += 2) {
            str[i] = (str[i] == '0') ? '1' : '0';
        }
        if (!dp[{str, passes}]) {
            solve(n, passes - 1, str, se, dp);
            dp[{str, passes}] = true;
        }
        str = original;

        // Button 4: Toggle lights with indices that are multiples of 3
        for (int i = 0; i < n; i += 3) {
            str[i] = (str[i] == '0') ? '1' : '0';
        }
        if (!dp[{str, passes}]) {
            solve(n, passes - 1, str, se, dp);
            dp[{str, passes}] = true;
        }
    }

    int flipLights(int n, int presses) {
        if (n > 6) n = 6; // Reduce n for optimization
        string str(n, '1');
        map<pair<string, int>, bool> dp;
        unordered_set<string> se;
        solve(n, presses, str, se, dp);
        return se.size();
    }
};
