class Solution {
public:
    vector<int> prefix;
    Solution(vector<int>& w) {
        prefix.push_back(w[0]);
        for(int i=1;i<w.size();i++) {
            prefix.push_back(prefix.back()+w[i]);
        }
    }
    int inc = 0;
    int pickIndex() {
        //picking random point
        int ind = rand() % prefix.back();

        //checking this point belongs to which weight
        int index = upper_bound(prefix.begin(),prefix.end(),ind) - prefix.begin();
        return index;

    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */