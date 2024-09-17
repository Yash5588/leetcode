class Solution {
public:
    vector<int> res;
    int res_size = 10000;
    unordered_map<int,int> dp;
    void solve(vector<int> &people_mask, int pos, vector<int> &temp, int mask, int target) {
        int n = people_mask.size();
        if(mask == target) {
            if(temp.size() < res_size) {
                res = temp;
                res_size = temp.size();
            }
            return;
        }
        if(pos >= n) {
            return;
        }
        if(temp.size() > res_size) return;
        long long key = (pos << 16) | mask;
        if(dp.find(key) != dp.end()) {
            if(dp[key] <= temp.size()) return;
        }
        temp.push_back(pos);
        solve(people_mask,pos+1,temp,mask | people_mask[pos],target);
        temp.pop_back();
        solve(people_mask,pos+1,temp,mask,target);
        if(temp.size() > 0) dp[key] = temp.size();
        else dp[key] = -1;
    }
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = req_skills.size();
        int size = people.size();
        unordered_map<string,int> skills;
        long long req_skill = (1 << n) - 1;
        for(int i = 0;i < n;i++) {
            skills[req_skills[i]] = i;
        }
        vector<int> people_mask(size,0);
        for(int i = 0;i < size;i++) {
            for(auto &str : people[i]) {
                people_mask[i] |= (1LL << skills[str]);
            }
        }
        vector<int> temp;
        solve(people_mask,0,temp,0,req_skill);
        return res;
    }
};