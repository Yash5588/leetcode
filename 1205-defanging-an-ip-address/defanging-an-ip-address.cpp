class Solution {
public:
    string defangIPaddr(string address) {
        string ans="";
        string res="[.]";
        for(int i=0;i<address.size();i++){
            if(address[i]=='.') ans+=res;
            else ans+=address[i];
        }
        return ans;
    }
};