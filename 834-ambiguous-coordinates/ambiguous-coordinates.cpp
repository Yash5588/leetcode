class Solution {
public:
    vector<string> getAllCombos(string &str1, string &str2) {
        vector<string> before,after;
        int n1 = str1.length();
        int n2 = str2.length();
        if(to_string(stoll(str1)) == str1) before.push_back(str1);
        for(int i = 0;i < n1-1;i++) {
            string number = str1.substr(0,i+1);
            string decimal = str1.substr(i+1);
            if(number[0] == '0' && i > 0)  continue;
            if(decimal.back() == '0') continue;
            before.push_back(number + '.' + decimal);
        }

        if(to_string(stoll(str2)) == str2) after.push_back(str2);
        for(int i = 0;i < n2-1;i++) {
            string number = str2.substr(0,i+1);
            string decimal = str2.substr(i+1);
            if(number[0] == '0' && i > 0) continue;
            if(decimal.back() == '0') continue;
            after.push_back(number + '.' + decimal);
        }
        vector<string> combos;
        for(auto &num : before) {
            for(auto &deci : after) {
                combos.push_back('(' + num + ", " + deci + ')');
            }
        }
        return combos;
    }
    vector<string> ambiguousCoordinates(string s) {
        int n = s.length();
        vector<string> res;
        for(int i = 1;i < n-2;i++) {
            string str1,str2;
            str1 = s.substr(1,i);
            str2 = s.substr(i+1);
            str2.pop_back();
            vector<string> strs = getAllCombos(str1,str2);
            for(auto &x : strs) res.push_back(x);
        }
        return res;
    }
};