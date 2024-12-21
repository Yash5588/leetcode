class Solution {
public:
    string sumString(const string &first, const string &second) {
        string res;
        int carry = 0, i = first.size() - 1, j = second.size() - 1;

        while (i >= 0 || j >= 0 || carry > 0) {
            int a = (i >= 0) ? first[i--] - '0' : 0;
            int b = (j >= 0) ? second[j--] - '0' : 0;
            int sum = a + b + carry;
            res += (sum % 10) + '0';
            carry = sum / 10;
        }

        reverse(res.begin(), res.end());
        return res;
    }
    bool backtrack(string &num, string &first, string &second, int pos) {
        string sum;
        int n = num.length();
        for (int i = pos + 1; i < n; i++) {
            if (i > pos+1 && num[pos+1] == '0') return false;
            sum += num[i];
            string add = sumString(first, second);
            if (add == sum) {
                if (i == n - 1) return true;
                if (backtrack(num, second, sum, i)) return true;
            }
        }
        return false;
    }

    bool isAdditiveNumber(string num) {
        int n = num.length();
        string first;
        for (int i = 0; i < n / 2; ++i) {
            first += num[i];
            if (i > 0 && num[0] == '0') return false;
            string second;
            for (int j = i + 1; j < n; ++j) {
                second += num[j];
                if (j > i + 1 && num[i+1] == '0') break;
                if (backtrack(num, first, second, j)) return true;
            }
        }
        return false;
    }
};
