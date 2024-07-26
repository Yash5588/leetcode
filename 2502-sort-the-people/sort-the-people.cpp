class Solution {
public:
    vector<string> sortPeople(vector<string>& a, vector<int>& h) {
        vector<string> name(100010,"");
        for(int i=0;i<a.size();i++) {
            name[h[i]] = a[i];
        }
        vector<string> ans;
        for(int i=100000;i>=0;i--) {
            if(name[i].size()) ans.push_back(name[i]);
        }
        return ans;
    }
};