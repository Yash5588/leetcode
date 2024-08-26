class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int n = s.length();
        //mid is the index which keeps track if length odd then it means that one char has odd occurance to address that we are using mid
        int i = 0,j = n-1,mid = -1;
        int ans = 0;
        while(i < j) {
            //now find the other occurance of character and fix it's position
            int k = j;
            while(k > i && s[k] != s[i]) {
                k--;
            }
            //k becomes equal to i of no other occurance of s[i] is present bet i and j mainly for odd length strings
            //ex: abcbc for 'a', (k == i)
            if(k != i) {
                ans += (j - k); //swapping operations
                for(int l=k;l<j;l++) { //left rotate by one shift
                    s[l] = s[l+1];
                }
                s[j] = s[i];
                //got for next pointer
                i++;
                j--;
            }
            else {
                //for above mentioned case we will ignore that for now and store the index of that like in "abcbc" we store index of 'a' in mid
                mid = i;
                i++;
            }
        }
        //later it show be in middle position right
        //so add the opeations to move it to middle
        if(mid != -1) {
            ans += (n/2 - mid);
        }
        return ans;
    }
};