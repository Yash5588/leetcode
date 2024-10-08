class Solution {
public:
    string ans;
    void dfs(int k,int cnt, string &str, unordered_map<string,bool> &visited) {
        if(cnt <= 0) return;
        visited[str] = true;
        for(int i = k-1;i >= 0;i--) {
            string dig = to_string(i);
            string s = str.substr(1) + dig;
            if(!visited[s]) {
                ans += dig;
                dfs(k,cnt-1,s,visited);
                return;
            }
        }
    }
    string crackSafe(int n, int k) {
        unordered_map<string,bool> visited;
        string str;
        for(int i = 0;i < n;i++) {
            str += '0';
        }
        ans = str;
        dfs(k,pow(k,n),str,visited);
        return ans;
    }
};