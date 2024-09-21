class Solution {
public:
    long long countZeros(long long num) {
        long long count = 0;
        long long start = 5;
        //to get all the 5's in the product of factorial
        //becoz 5 always contributes for each zero
        //number of 5's = zeros at the end
        //now we have to be careful of 25,125,625...
        //25 - two 5's 125 - three 5's so we add they extra if present inside factorial
        while(start <= num) {
            count += num/start;
            start *= 5;
        }
        return count;
    }
    int preimageSizeFZF(int k) {
        long long ans = 0;
        long long low = 0;
        long long high = 6*(long long)k;
        while(low <= high) {
            long long mid = low + (high - low)/2;
            long long zeros = countZeros(mid);
            if(zeros < k) low = mid + 1;
            else if(zeros > k) high = mid - 1;
            else {
                //every time we will be having result as either 5 or 0
                ans = 5;
                break;
            }
        }
        return ans;
    }
};