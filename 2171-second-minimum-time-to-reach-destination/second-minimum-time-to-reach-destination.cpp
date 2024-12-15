class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        unordered_map<int, vector<int>> adj;
        //create a graph
        for(auto &x : edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> que;
        vector<int> firstMinDist(n+1,INT_MAX);
        vector<int> secondMinDist(n+1,INT_MAX);

        firstMinDist[1] = 0;
        que.push({0,1});

        while(!que.empty()) {
            int totalTime = que.top().first;
            int node = que.top().second;
            que.pop();
            //destination node is visited twice then break
            if(node == n && secondMinDist[n] != INT_MAX) return secondMinDist[n];
            int div = totalTime/change;
            //red zone
            if(div & 1) { //wait for green zone to occur 
                totalTime = (totalTime/change + 1) * change;
            }
            for(auto &child : adj[node]) {
                //edgeWeight is time which is fixed
                if(totalTime + time < firstMinDist[child]) { //first arrival is the 1st shortest of that node
                    secondMinDist[child] = firstMinDist[child];
                    firstMinDist[child] = totalTime + time;
                    que.push({firstMinDist[child], child});
                }
                //it should be less as well the second min dist should be STRICTLY LESS THAN 1st min dist
                else if(totalTime + time < secondMinDist[child] && totalTime + time != firstMinDist[child]) { 
                    //second min dist in second arrival 
                    secondMinDist[child] = totalTime + time;
                    que.push({secondMinDist[child], child});
                }
                //here every node is visited  twice not more than that
            }
        }
        // cout << firstMinDist[n] << endl;
        return -1;
    }
};