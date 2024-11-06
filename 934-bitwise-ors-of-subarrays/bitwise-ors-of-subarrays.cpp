class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n=arr.size();
         unordered_set<int>ans, prev;

         for(int i=0; i<n; i++){
             unordered_set<int>curr;
             for(auto x:prev){
                 curr.insert(x|arr[i]);
             }
             curr.insert(arr[i]);
             for(auto &x : curr) ans.insert(x);
             prev = curr;
         }
        return ans.size();
    }
};