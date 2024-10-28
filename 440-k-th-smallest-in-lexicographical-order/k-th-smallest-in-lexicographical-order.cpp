class Solution {
public:
    int countNum(long long curr, long long next, long long n) {
        long long cnt = 0;
        //curr is current subtree's starting element
        //next is next subtree's starting element
        //(next - curr) gives the number of elements in the curr subtree
        //ex 1 and 2 (2-1) = 1 in current level
        //1 -> 10 and 2 -> 20 => (20-10) = 10 
        //total elements in 1 prefix subtree is 1 + 10 = 11;
        //if n = 12 then it stops there
        while(curr <= n) {
            cnt += (next - curr);
            curr *= 10;
            next *= 10;
            //for above ex if n = 11 then 
            //the next will exceed current to avoid that we are adding a check
            //dry run for n = 10 and k = 3 for better understanding 
            next = min(next, n+1);
        }
        return cnt;
    }
    int findKthNumber(int n, int k) {
        long long curr = 1;
        k -= 1; // initial number considered
        while(k > 0) {
            long long cnt = countNum(curr,curr+1,n);
            //the kth element is not in my curr subtree so skip the whole subtree elements with the curr as prefix
            if(cnt <= k) {
                k -= cnt;
                curr++;
            }
            else {
                //the kth element is the same subtree somewhere
                //so explore deeper
                //1 -> explore b/w 10 and 11
                curr *= 10;
                k -= 1;
            }
        }
        return curr;
    }
};