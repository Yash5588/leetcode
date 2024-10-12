class Solution {
public:
    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();
        int MOUSE_WIN = 1,CAT_WIN = 2,DRAW = 0;
        int MOUSE = 0,CAT = 1;
        map<vector<int>,int> result;
        for(int i = 1;i < n;i++) {
            result[{0,i,CAT}] = result[{0,i,MOUSE}] = MOUSE_WIN;
            result[{i,i,CAT}] = result[{i,i,MOUSE}] = CAT_WIN;
        }
        map<vector<int>,int> degree;
        for(int mouse = 1;mouse < n;mouse++) {
            for(int cat = 1;cat < n;cat++) {
                degree[{mouse,cat,MOUSE}] = graph[mouse].size();
                if(find(graph[cat].begin(),graph[cat].end(),0) != graph[cat].end()) {
                    degree[{mouse,cat,CAT}] = graph[cat].size()-1;
                }
                else degree[{mouse,cat,CAT}] = graph[cat].size();
            }
        }
        queue<vector<int>> que;
        for(int i = 1;i < n;i++) {
            que.push({0,i,MOUSE});
            que.push({0,i,CAT});
            que.push({i,i,MOUSE});
            que.push({i,i,CAT});
        }
        while(!que.empty()) {
            int mouse = que.front()[0];
            int cat = que.front()[1];
            int turn = que.front()[2];
            que.pop();
            int current_result = result[{mouse,cat,turn}];
            vector<vector<int>> prev_states;
            if(turn == MOUSE) {
                for(auto &x : graph[cat]) {
                    prev_states.push_back({mouse,x,CAT});
                }
            }
            else {
                for(auto &x : graph[mouse]) {
                    prev_states.push_back({x,cat,MOUSE});
                }
            }
            for(auto &p_state : prev_states) {
                if(result.find(p_state) != result.end()) continue;
                int prev_mouse = p_state[0];
                int prev_cat = p_state[1];
                int prev_turn = p_state[2];
                if(prev_cat == 0) continue;
                degree[p_state]--;
                bool isMoverWinner = (current_result == CAT_WIN && prev_turn == CAT) || (current_result == MOUSE_WIN && prev_turn == MOUSE);
                if(isMoverWinner || degree[p_state] == 0) {
                    result[p_state] = current_result;
                    que.push(p_state);
                }
            }
        }
        if(result.find({1,2,MOUSE}) != result.end()) return result[{1,2,MOUSE}];
        return DRAW;
    }
};