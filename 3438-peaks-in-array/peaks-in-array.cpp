class FenwickTree{
    private:
        vector<int> bit;
        int N;
    public:
        FenwickTree(int n) {
            bit.resize(n+1,0);
            N = n;
        }

        int query(int id) {
            int ans = 0;
            while(id > 0) {
                ans += bit[id];
                id -= (id & -id);
            }
            return ans;
        }

        void update(int id, int val) {
            while(id <= N) {
                bit[id] += val;
                id += (id & -id);
            }
        }

};
class Solution {
public:
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        //mark the peak elements in binary tree
        int n = nums.size();
        vector<int> peaks(n,0);
        for(int i = 1;i < n-1;i++) {
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1]) {
                peaks[i] = 1;
            }
        }
        FenwickTree fen(n);
        vector<int> res;
        //update in fenwick tree
        for(int i = 0;i < n;i++) {
            fen.update(i+1, peaks[i]);
        }
        for(auto &q : queries) {
            if(q[0] == 1) {
                //it is a subarray not sub query
                //so borders are not peaks so remove them if included
                // int val = seg.query(q[1], q[2] ,0 ,0 ,n-1);
                int start = q[1];
                int end = q[2];
                int val = fen.query(end+1) - fen.query(start);
                val -= peaks[q[1]];
                //check if both indices are same
                if(q[1] != q[2]) val -= peaks[q[2]];
                res.push_back(val);
            } 
            else {
                nums[q[1]] = q[2];
                int ind  = q[1];
                if(ind-1 >= 0 && ind+1 < n) {
                    if(nums[ind-1] < nums[ind] && nums[ind+1] < nums[ind]) {
                        //if current ind is peak then we are sure that left and right are not the peaks
                        //remove previous value and update new value
                        fen.update(ind+1, -peaks[ind]);
                        peaks[ind] = 1;
                        fen.update(ind+1, 1);

                        fen.update(ind, -peaks[ind-1]);
                        peaks[ind-1] = 0;

                        fen.update(ind+2, -peaks[ind+1]);
                        peaks[ind+1] = 0;
                    }
                    else {
                        //if current ind is not peak then
                        //left and right may be peaks so check them
                        fen.update(ind+1, -peaks[ind]);
                        peaks[ind] = 0;
                    }
                }
                //check ind -1 and ind +1 as peaks
                if(peaks[ind] != 1) {
                    int left = ind-1;
                    if(left-1 >= 0 && left+1 < n) {
                        if(nums[left-1] < nums[left] && nums[left+1] < nums[left]) {
                            fen.update(left+1, -peaks[left]);
                            peaks[left] = 1;
                            fen.update(left+1, 1);
                        }
                        else {
                            fen.update(left+1, -peaks[left]);
                            peaks[left] = 0;
                        }
                    }
                    int right = ind+1;
                    if(right-1 >= 0 && right+1 < n) {
                        if(nums[right-1] < nums[right] && nums[right+1] < nums[right]) {
                            fen.update(right+1, -peaks[right]);
                            peaks[right] = 1;
                            fen.update(right+1, 1);
                        }
                        else {
                            fen.update(right+1, -peaks[right]);
                            peaks[right] = 0;
                        }
                    }
                }
            }
        }
        return res;
    }
};