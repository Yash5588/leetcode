class Solution {
public:
    string defangIPaddr(string address) {
        int n=address.length();
        string ans="";
        for(char i:address){
            if(i=='.'){
                ans+="[.]";
            }else{
                ans+=i;
            }

        }
        return ans;
        
    }
};