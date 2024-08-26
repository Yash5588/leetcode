class Solution {
public:
    string lastSubstring(string s) {
        int n = s.length();
        int i=0,j = 1,offset = 0;
        //i is the pointer which points to first substring
        //j is the pointer which points to second substring
        //offset is like building substring used to compare characters in that specific position in both substrings
        //we don't need to compare whole substrings
        //it will become O(n^2)
        //we can ignore all the previously compared characters
        while(j + offset < n) {
            //compare the two substrings
            //if both characters are equal increment offset so that we can compare next character
            if(s[i + offset] == s[j + offset]) {
                offset++;
            }
            //if first substring is less than 2nd one
            //then we have to change our substring i to next one becoz it is not greater one anymore
            //we need to ignore previous compared characters 
            //offset basically means that that many characters of 2nd substring matches with 1st
            //we found a bigger one so eliminate that many characters
            else if(s[i + offset] < s[j + offset]) {
                //new i and j positions
                //for more clarity check for these test cases
                //1) aaaaaa
                //2) caacad
                //3) cacacb
                i = max(i + offset + 1, j);
                j = i + 1;
                offset = 0;
                //make offset 0 becoz we are starting fresh substring
            }
            else {
                //if our 1st substring is only greater then 
                //check for next substring also ignore previous equal characters that is add offset
                j = j + offset + 1;
                offset = 0;
            }
        }
        return s.substr(i,n);
    }
};