class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        //i and j for group checking
        //k is to form array
        int i=0,j=1,k=0;
        if(n == 1) return 1;
        //edge case if last group has only one character then it will
        //not be considered in below snippet
        //so we are checking initially before manipulating the original array
        bool flag = false;
        if(chars[n-1] != chars[n-2]) flag = true; 
        while(j < n) {
            chars[k] = chars[i];
            while(j < n && chars[i] == chars[j]) {
                j++;
            }
            k++;
            if(j-i != 1) {
                //if count > 1 and has more digits assign all in array
                string str = to_string(j-i);
                for(auto &x : str) {
                    chars[k] = x;
                    k++;
                }
            }
            //again check for next group
            i = j;
            j++;
        }
        //The above mentioned edge case 
        //ex : ["a","b","c"],["b","b","b","c"] last group count is 1 for that case
        if(flag) {
            chars[k] = chars.back();
            k++;
        }
        return k;
    }
};