class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> left;
        int c = 0;
        for(char &x : s) {
            if(x == '(') {
                left.push(x);
            }
            else {
                if(!left.empty()) {
                    left.pop();
                }
                else {
                    c++;
                }
            }
        }
        return c + left.size();

    }
};