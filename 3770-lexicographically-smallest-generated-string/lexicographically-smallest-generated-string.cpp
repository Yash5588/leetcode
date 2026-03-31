class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size(), len = n + m - 1;
        string res(len, '#');
        vector<int> locked(len);

        for (int i = 0; i < n; i++) {
            if (str1[i] != 'T') continue;
            for (int j = 0; j < m; j++) {
                int k = i + j;
                if (res[k] != '#' && res[k] != str2[j]) return "";
                res[k] = str2[j];
                locked[k] = 1;
            }
        }

        for (int i = 0; i < len; i++) {
            if (res[i] == '#') res[i] = 'a';
        }

        for (int i = 0; i < n; i++) {
            if (str1[i] != 'F') continue;

            bool ok = true;
            for (int j = 0; j < m; j++) {
                if (res[i + j] != str2[j]) {
                    ok = false;
                    break;
                }
            }

            if (!ok) continue;

            int pos = -1;
            for (int j = m - 1; j >= 0; j--) {
                if (!locked[i + j]) {
                    pos = i + j;
                    break;
                }
            }

            if (pos == -1) return "";
            res[pos] = (str2[pos - i] == 'a' ? 'b' : 'a');
        }

        return res;
    }
};