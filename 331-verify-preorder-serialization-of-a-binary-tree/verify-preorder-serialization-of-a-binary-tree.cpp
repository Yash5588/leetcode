class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n = preorder.length();
        int vacancy = 1;
        int i = 0;
        while(i < n) {
            string temp;
            while(i < n && preorder[i] != ',') {
                temp += preorder[i];
                i++;
            }
            i++;
            vacancy--;
            if(vacancy < 0) return false;
            if(temp != "#") vacancy += 2;
        }
        return vacancy == 0;
    }
};