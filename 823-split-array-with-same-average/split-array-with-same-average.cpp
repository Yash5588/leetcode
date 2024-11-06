class Solution {
public:
    void subsetSum(vector<int> &nums, int pos, map<int,vector<int>> &subset, int sum, int cnt) {
        int n = nums.size();
        if(pos >= n) {
            subset[cnt].push_back(sum);
            return;
        }
        subsetSum(nums,pos+1,subset,sum+nums[pos],cnt+1);
        subsetSum(nums,pos+1,subset,sum,cnt);
    }

    pair<double,double> getAvgs(long long curSum, long long curlen, long long total, long long len) {
        long long remSum = total - curSum;
        long long remlen = len - curlen;
        return {curSum/double(curlen),remSum/double(remlen)};
    }
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(nums.begin(),nums.begin()+n/2);
        vector<int> right(nums.begin()+n/2,nums.end());
        map<int,vector<int>> subset1, subset2;
        subsetSum(left,0,subset1,0,0);
        subsetSum(right,0,subset2,0,0);
        long long total = accumulate(nums.begin(),nums.end(),0);
        for(auto &[cnt2,sumsList2] : subset2) {
            sort(sumsList2.begin(),sumsList2.end());
        }
        //this all for the first subset sum
        //second subset and it's count can be brought by total sum and size of original array
        for(auto &[cnt1,sumsList1] : subset1) {
            for(auto &sum1 : sumsList1) {
                for(auto &[cnt2, sumsList2] : subset2) {
                    //both are empty
                    if(cnt1 + cnt2 == 0) continue;
                    int low = 0, high = sumsList2.size()-1;
                    while(low <= high) {
                        int mid = low + (high - low)/2;
                        int sum2 = sumsList2[mid];
                        pair<double,double> avg_pair = getAvgs(sum1+sum2,cnt1+cnt2,total,n);
                        if(avg_pair.first == avg_pair.second) return true;
                        else if(avg_pair.first < avg_pair.second) {
                            low = mid + 1;
                        }
                        else high = mid - 1;
                    }
                }
            }
        }
        return false;
    }
};