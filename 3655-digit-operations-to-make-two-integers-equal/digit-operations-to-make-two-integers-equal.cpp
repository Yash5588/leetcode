class Solution {
public:
    bool isPrime(int n) {
        if(n == 1) return false;
        if(n == 2) return true;
        if(n % 2 == 0) return false;
        for(int i = 3;i <= sqrt(n);i++) {
            if(n % i == 0) return false;
        }
        return true;
    }
    vector<long long> getNeighbors(int n) {
        string s = to_string(n);
        vector<long long> neighbors;
        for(int i = 0;i < s.length();i++) {
            int digit = s[i]-'0';
            if(digit < 9) {
                string temp = s;
                temp[i] = (char)((digit + 1) + '0');
                long long val = stoll(temp);
                if(!isPrime(val)) {
                    neighbors.push_back(val);
                }
            }
            if(digit > 0) {
                string temp = s;
                temp[i] = (char)((digit - 1) + '0');
                long long val = stoi(temp);
                if(!isPrime(val)) {
                    neighbors.push_back(val);
                }
            }
        }
        // for(auto &x : neighbors) cout << x << ' ';
        // cout << endl;
        return neighbors;
    }
    int minOperations(int n, int m) {
        vector<int> dist(1e5,INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> que;
        dist[n] = n;
        if(!isPrime(n) && !isPrime(m)) {
            que.push({dist[n],n});
        }
        while(!que.empty()) {
            int cost = que.top().first;
            int node = que.top().second;
            que.pop();
            if(node == m) return cost;
            vector<long long> neighbors = getNeighbors(node);
            for(auto &child : neighbors) {
                if(cost + child < dist[child]) {
                    dist[child] = cost + child;
                    que.push({dist[child],child});
                }
            }
        }
        return -1;
    }
};