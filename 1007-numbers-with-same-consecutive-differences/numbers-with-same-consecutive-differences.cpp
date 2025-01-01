class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        queue<string> que;
        unordered_set<int> res;
        for(int i = 1;i <= 9;i++) {
            que.push(to_string(i));
        }
        while(!que.empty()) {
            string num = que.front();
            que.pop();
            if(res.find(stoll(num)) != res.end()) continue;
            if(num.length() >= n) {
                res.insert(stoll(num));
                continue;
            }
            int digit = num.back() - '0';
            if(digit + k < 10) {
                que.push(num + to_string(digit + k));
            }
            if(digit - k >= 0) {
                que.push(num + to_string(digit - k));
            }
        }
        return vector<int> (res.begin(),res.end());
    }
};