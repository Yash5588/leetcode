class Solution {
public:
    
    bool isAnagram(string s, string t) {
        int c[26]={0};
        if(s.length()!=t.length()){
            return false;
        }else{
        for(int i=0;i<s.length();i++){
            c[s[i]-'a']++;
            c[t[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(c[i]!=0){
                return false;
            }}}
            return true;
        
    }
};