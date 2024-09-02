class Solution {
public:
    //we are considering an ideal jug which is total we are pouring and removing both jugs water in it.
    bool dfs(int jug1, int jug2, int target, int total, vector<bool> &visited) {
        //if our ideal jug water exceeds total jug water 
        //if it becomes less than 0 which is not possible
        //and that score is previously visited we will block all these paths
        if(total > jug1+jug2 || total < 0 || visited[total]) return false;
        //if we reach target in that particular path
        if(total == target) return true;
        //mark the total as visited
        visited[total] = true;
        bool ans = false;
        //we will be going in four possible routs
        bool addjug1 = dfs(jug1,jug2,target,total+jug1,visited); 
        bool removejug1 = dfs(jug1,jug2,target,total-jug1,visited); 
        bool addjug2 = dfs(jug1,jug2,target,total+jug2,visited); 
        bool removejug2 = dfs(jug1,jug2,target,total-jug2,visited);
        //check which route is best possible to reach if can reach target in any one route otherwise false
        ans = addjug1 || removejug1 || addjug2 || removejug2;
        return ans;
    }
    bool canMeasureWater(int x, int y, int target) {
        //check even if we fill both jugs full we can't reach that target
        //handle that case
        if(x + y < target) return false;
        //prepare a visited array which is helping for not computing again and again the already checked score
        //it's size is max score score possible which is (x + y)
        vector<bool> visited(x+y+1,false);
        return dfs(x,y,target,0,visited);
    }
};