class Solution {
public:
    string bin(int num) {
        string b;
        for(int i = 31;i >= 0;i--) {
            int p = num >> i;
            if(p & 1) b += '1';
            else if(p > 0) b += '0';
        }
        return b;
    }
    int maxGoodNumber(vector<int>& nums) {
        string str;
        string b1 = bin(nums[0]);
        string b2 = bin(nums[1]);
        string b3 = bin(nums[2]);
        str = b1 + b2 + b3;
        cout << str << endl;
        int p = 0;
        long long ans = 0;
        long long ma = INT_MIN;
        for(int i = str.size()-1;i >= 0;i--) {
            ans += (str[i]-'0')*pow(2,p);
            p++;
        }
        ma = max(ma, ans);
        b1 = bin(nums[0]);
        b2 = bin(nums[2]);
        b3 = bin(nums[1]);
        str = b1 + b2 + b3;
        cout << str << endl;
        p = 0;
        ans = 0;
        for(int i = str.size()-1;i >= 0;i--) {
            ans += (str[i]-'0')*pow(2,p);
            p++;
        }
        ma = max(ma, ans);
         b1 = bin(nums[1]);
         b2 = bin(nums[0]);
         b3 = bin(nums[2]);
        str = b1 + b2 + b3;
        p = 0;
        ans = 0;
        for(int i = str.size()-1;i >= 0;i--) {
            ans += (str[i]-'0')*pow(2,p);
            p++;
        }
        ma = max(ma, ans);
         b1 = bin(nums[1]);
         b2 = bin(nums[2]);
         b3 = bin(nums[0]);
        str = b1 + b2 + b3;
        p = 0;
        ans = 0;
        for(int i = str.size()-1;i >= 0;i--) {
            ans += (str[i]-'0')*pow(2,p);
            p++;
        }
        ma = max(ma, ans);
         b1 = bin(nums[2]);
         b2 = bin(nums[0]);
         b3 = bin(nums[1]);
        str = b1 + b2 + b3;
        p = 0;
        ans = 0;
        for(int i = str.size()-1;i >= 0;i--) {
            ans += (str[i]-'0')*pow(2,p);
            p++;
        }
        ma = max(ma, ans);
         b1 = bin(nums[2]);
         b2 = bin(nums[1]);
         b3 = bin(nums[0]);
        str = b1 + b2 + b3;
        p = 0;
        ans = 0;
        for(int i = str.size()-1;i >= 0;i--) {
            ans += (str[i]-'0')*pow(2,p);
            p++;
        }
        ma = max(ma, ans);
        return ma;
    }
};