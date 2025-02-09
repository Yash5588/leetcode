class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        //get the least possible index
        unordered_map<int,int> index;
        //assign first occurance index
        for(int i = 0;i < elements.size();i++) {
            if(index.find(elements[i]) == index.end()) index[elements[i]] = i;
        }
        //now get all the divisors and check for hash map
        int n = groups.size();
        vector<int> res(n,INT_MAX);
        //to get the min possible index from elements for each group
        for(int i = 0;i < n;i++) {
            for(int d = 1;d <= sqrt(groups[i]);d++) {
                if(groups[i] % d == 0) {
                    int num1 = d;
                    int num2 = groups[i] / d;
                    if(index.find(num1) != index.end()) {
                        res[i] = min(res[i], index[num1]);
                    }
                    if(index.find(num2) != index.end()) {
                        res[i] = min(res[i], index[num2]);
                    }
                }
            }
            //not found any element
            if(res[i] == INT_MAX) res[i] = -1;
        }
        return res;
    }
};