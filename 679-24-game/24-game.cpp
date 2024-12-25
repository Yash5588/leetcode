class Solution {
public:
    //perform all possible operations for that pair 
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
        //perform operations on each combination
        for(int i = 0;i < n;i++) {
            for(int j = i+1;j < n;j++) {
                vector<double> operations = getOperations(cards[i],cards[j]);
                vector<double> newCards;
                //perform all the opertions for those pair
                for(auto &operation : operations) {
                    //build new array [a,b,c,d] a and b are picked
                    //then [a+b,c,d], [a-b,c,d] like this
                    newCards.push_back(operation);
                    for(int k = 0;k < n;k++) {
                        //get the remaining elements 
                        if(k == i || k == j) continue;
                        newCards.push_back(cards[k]);
                    }
                    //after this size is decreased by 1 at each call
                    if(solve(newCards)) return true;
                    //clear array for new operation
                    newCards.clear();
                }
            }
        }
        return false;
    }
    bool judgePoint24(vector<int>& cards) {
        //convert to double to avoid future calculations in double
        vector<double> dou(cards.begin(),cards.end());
        return solve(dou);
    }
};