class Solution {
public:
    vector<int> check(multiset<int> mset, int k) {
        //now it is sorted
        //so we are getting x - k at top of set
        //now find x + k 
        vector<int> ans;
        while(!mset.empty()) {
            int smallest = *mset.begin();
            //x - k 
            //large is smallest + 2*k => ((x - k) + 2*k = x + k)
            int largest = smallest + 2*k;
            //find the other element
            auto iter = mset.find(largest);
            if(iter == mset.end()) {
                return {}; //if not found means this k value is not satisfied
            }
            ans.push_back((smallest + largest)/2); //get original element
            mset.erase(iter); //erase pair 
            mset.erase(mset.find(*mset.begin()));
        } 
        return ans;
    }
    vector<int> recoverArray(vector<int>& nums) {
        int n = nums.size();
        multiset<int> mset(nums.begin(),nums.end());
        //get all possible k values;
        int first = nums[0];
        for(int i = 1;i < n;i++) {
            int second = nums[i];
            //k should be integer so diff should be even
            if(abs(first - second) & 1) continue; //odd diff
            int k = abs(first - second)/2; //we don't know it might be bigger or smaller
            //k = (x - k) - (x + k) => 2*k/2 = k
            //now check this k value
            if(k == 0) continue; //k should be positive integer
            vector<int> ans = check(mset, k);
            if(!ans.empty()) return ans;
        }
        return {};
    }
};