class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n=hours.size(),mx=0,count=0;
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++){
            if(hours[i]>8) count++;
            else count--;

            if(count>0){
                mx=max(mx,i+1);
                continue;
            }else{
                if(!mp.count(count)){
                    mp[count]=i;
                }
            }
            if(mp.count(count-1)){
                mx=max(mx,i-mp[count-1]);
            }
        }
        return mx;
    }
};