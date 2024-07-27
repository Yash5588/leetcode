class Solution {
public:
    // 1) this problem is application of next greater element in array
    // 2) use monotically decreasing stack and iterate from backwards
    // 3) The main Intuition is i need the number of elements popped by current also
    // 4) for this thing i'm implementing pair which first stores value and second stores number
    // of elements the current element has popped
    // 5) while u pop anyelement make sure get the number of elements popped by stack top because those elements are already popped and we need their count this is the purpose
    // 6) while pushing push with number of elements the current element has popped
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        stack<pair<int,int>> sta;
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--) {
            int pops = 0;
            while(!sta.empty() && sta.top().first <= temp[i]) {
                pops += sta.top().second;
                sta.pop();
            }
            if(sta.empty()) ans[i] = 0;
            else ans[i] = pops+1;
            sta.push({temp[i],pops+1}); 
        }
        return ans;
    }
};