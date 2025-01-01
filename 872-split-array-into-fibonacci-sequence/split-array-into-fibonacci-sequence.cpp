class Solution {
public:
    string sumString(string &first, string &second) {
        int i = first.length()-1;
        int j = second.length()-1;
        int carry = 0;
        string res;
        while(i >= 0 || j >= 0 || carry > 0) {
            int a = (i >= 0) ? first[i--] - '0' : 0;
            int b = (j >= 0) ? second[j--] - '0' : 0;
            int sum = a + b + carry;
            res += (sum % 10) + '0';
            carry = sum/10;
        }
        reverse(res.begin(),res.end());
        return res;
    }

    bool inIntegerRange(string &str) {
        if(str.length() > 10) return false;
        long long n = stoll(str);
        if(n <= INT_MAX) return true;
        return false;
    }
    bool backtrack(string &num, string &first, string &second, int pos, vector<int> &temp) {
        int n = num.length();
        string sum;
        string add = sumString(first, second);
        for(int i = pos+1;i < n;i++) {
            if(i > pos+1 && num[pos+1] == '0') return false;
            sum += num[i];
            if(!inIntegerRange(sum)) return false;
            if(sum == add) {
                temp.push_back(stoll(sum));
                if(i == n-1) return true;
                if(backtrack(num, second, sum, i, temp)) return true;
                temp.pop_back();
            }
        }
        return false;
    }
    vector<int> splitIntoFibonacci(string num) {
        int n = num.length();
        string first;
        for(int i = 0;i < n/2;i++) {
            if(i > 0 && num[0] == '0') return {};
            first += num[i];
            if(!inIntegerRange(first)) return {};
            string second;
            for(int j = i+1;j < n;j++) {
                if(j > i+1 && num[i+1] == '0') break;
                second += num[j];
                if(!inIntegerRange(second)) break;
                vector<int> temp;
                temp.push_back(stoll(first));
                temp.push_back(stoll(second));
                if(backtrack(num, first, second, j, temp)) return temp; 
                temp.pop_back();
                temp.pop_back();
            }
        }
        return {};
    }
};