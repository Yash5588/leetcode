class Solution {
public:
    bool allVowels(vector<vector<int>> &prefix_vow, int left, int right) {
        bool all = true;
        if(left == 0) {
            all &= (prefix_vow[right]['a'-'a'] != 0);
            all &= (prefix_vow[right]['e'-'a'] != 0);
            all &= (prefix_vow[right]['i'-'a'] != 0);
            all &= (prefix_vow[right]['o'-'a'] != 0);
            all &= (prefix_vow[right]['u'-'a'] != 0);
            return all;
        }
        all &= (prefix_vow[right]['a'-'a'] - prefix_vow[left-1]['a'-'a'] != 0);
        all &= (prefix_vow[right]['e'-'a'] - prefix_vow[left-1]['e'-'a'] != 0);
        all &= (prefix_vow[right]['i'-'a'] - prefix_vow[left-1]['i'-'a'] != 0);
        all &= (prefix_vow[right]['o'-'a'] - prefix_vow[left-1]['o'-'a'] != 0);
        all &= (prefix_vow[right]['u'-'a'] - prefix_vow[left-1]['u'-'a'] != 0);
        return all;
    }

    long long getVowMin(int start, vector<vector<int>> &prefix_vow) {
        int n = prefix_vow.size();
        int low = start, high = n-1;
        int ind = -1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(allVowels(prefix_vow,start,mid)) {
                ind = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ind;
    }

    long long getCount(vector<int> &conso, int left, int right) {
        if(left == 0) return conso[right];
        return conso[right] - conso[left - 1];
    }
    long long getConsoMax(int start, vector<int> &conso, int k) {
        int n = conso.size();
        int low = start, high = n - 1;
        int ind = -1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(getCount(conso,start,mid) >= k) {
                ind = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ind;
    }
    long long getConsoMin(int start, vector<int> &conso, int k) {
        int n = conso.size();
        int low = start, high = n - 1;
        int ind = n;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(getCount(conso,start,mid) <= k) {
                ind = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ind;
    }


    long long countOfSubstrings(string word, int k) {
        int n = word.size();
        vector<vector<int>> prefix_vow(n, vector<int> (26,0));
        prefix_vow[0][word[0] - 'a']++;
        unordered_set<char> vow{'a','e','i','o','u'};
        vector<int> conso(n);
        if(vow.count(word[0]) == 0) conso[0]++;
        for(int i = 1;i < n;i++) {
            prefix_vow[i]['a'-'a'] = prefix_vow[i-1]['a'-'a'];
            prefix_vow[i]['e'-'a'] = prefix_vow[i-1]['e'-'a'];
            prefix_vow[i]['i'-'a'] = prefix_vow[i-1]['i'-'a'];
            prefix_vow[i]['o'-'a'] = prefix_vow[i-1]['o'-'a'];
            prefix_vow[i]['u'-'a'] = prefix_vow[i-1]['u'-'a'];
            prefix_vow[i][word[i] - 'a']++;
            conso[i] = conso[i-1];
            if(vow.count(word[i]) == 0) conso[i]++; 
        }
        // for(auto &x : conso) cout << x << endl;
        long long ans = 0;
        for(int i = 0;i < n-1;i++) {
            int vow_min = getVowMin(i, prefix_vow);
            if(vow_min == -1) continue;
            int low = getConsoMax(i, conso, k);
            if(low == -1) continue;
            int high = getConsoMin(i, conso, k);
            if(high == n) continue;
            int first = max(low,vow_min);
            int last = high;
            if(first <= last) {
                ans += (last - first + 1);
            }
            // cout << ans << endl;
            // cout << i << ' ' << low << ' ' << high << endl;
            // cout << vow_min << endl;
        }
        return ans;
    }
};