class Solution {
public:
    //why if width is same we are sorting decreasing order for same width
    //WHY?
    //becoz if we sort it in ascending order for same width
    //when we apply LIS we are going to include same width values
    //only one width of one value can be included
    //ex :[2,3],[6,2],[6,4],[6,5] if it is like this
    //when we apply LIS we get result as 3 is it correct? 6 width 
    //envelopes included 3 times
    //if we sort in DESC order then [2,3],[6,5],[6,4],[6,2] 
    //by this we get LIS as 2 ans it is true so we do this.
    static bool sortIfEqual(vector<int> &a, vector<int> &b) {
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(),envelopes.end(),sortIfEqual);
        vector<int> lis_len;
        //general LIS anyway width wise it is sorted if we know the LIS 
        //then we can fit envelopes
        for(int i = 0;i < n;i++) {
            int ind = lower_bound(lis_len.begin(),lis_len.end(),envelopes[i][1]) - lis_len.begin();
            if(ind == lis_len.size()) lis_len.push_back(envelopes[i][1]);
            else lis_len[ind] = envelopes[i][1];
        }
        return lis_len.size();
    }
};