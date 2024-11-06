class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n=arr.size();
         unordered_set<int>ans, prev;

         for(int i=0; i<n; i++){
             unordered_set<int>curr;
             //curr is for only ith index not for whole array
             //check till i-1 and get all possible XORS
             for(auto x:prev){
                 curr.insert(x|arr[i]);
             }
             //insert curr element as well
             curr.insert(arr[i]);
             //later insert all unique xors in result to get all unique xors
             for(auto &x : curr) ans.insert(x);
             //modify prev with curr
             prev = curr;
         }
        return ans.size();
    }
};