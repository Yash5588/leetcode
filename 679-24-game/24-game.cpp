class Solution {
public:
    vector<double> getOperations(double &a, double &b) {
        vector<double> operations;
        operations.push_back(a+b);
        operations.push_back(a*b);
        if(a >= b) operations.push_back(a-b);
        else operations.push_back(b-a);
        if(b > 0) operations.push_back(a/b);
        if(a > 0) operations.push_back(b/a);
        return operations;
    }
    bool solve(vector<double> &cards) {
        int n = cards.size();
        if(n == 1) {
            //to check to double numbers equal or not 
            //use this one FLT_EPSILON
            //if the absolute diff is less than this val then both double numbers are equal
            if(abs(24.0 - cards[0]) < FLT_EPSILON) return true;
            return false;
        }
        //perform operations
        for(int i = 0;i < n;i++) {
            for(int j = i+1;j < n;j++) {
                vector<double> operations = getOperations(cards[i],cards[j]);
                vector<double> newCards;
                for(auto &operation : operations) {
                    newCards.push_back(operation);
                    for(int k = 0;k < n;k++) {
                        if(k == i || k == j) continue;
                        newCards.push_back(cards[k]);
                    }
                    if(solve(newCards)) return true;
                    newCards.clear();
                }
            }
        }
        return false;
    }
    bool judgePoint24(vector<int>& cards) {
        vector<double> dou(cards.begin(),cards.end());
        return solve(dou);
    }
};