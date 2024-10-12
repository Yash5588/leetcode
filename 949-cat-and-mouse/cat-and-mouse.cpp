class Solution {
public:
    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();
        //define variables
        int MOUSE_WIN = 1,CAT_WIN = 2,DRAW = 0;
        int MOUSE = 0,CAT = 1;
        //store the results for all possible combinations
        map<vector<int>,int> result;
        for(int i = 1;i < n;i++) {
            //all mouse win situations 
            result[{0,i,CAT}] = result[{0,i,MOUSE}] = MOUSE_WIN;
            //all cat win situations
            result[{i,i,CAT}] = result[{i,i,MOUSE}] = CAT_WIN;
        }
        //get the degree for each state
        map<vector<int>,int> degree;
        for(int mouse = 1;mouse < n;mouse++) {
            for(int cat = 1;cat < n;cat++) {
                //for all possible combiations get the degree
                //if the curre turn is of MOUSE then it's obviously all nodes of graph
                //connected to mouse
                degree[{mouse,cat,MOUSE}] = graph[mouse].size();
                //but for cat it can't move to 0 so we find 0 in cat options in graph
                if(find(graph[cat].begin(),graph[cat].end(),0) != graph[cat].end()) {
                    //if we find we eliminate one traversal option for cat
                    degree[{mouse,cat,CAT}] = graph[cat].size()-1;
                }
                else degree[{mouse,cat,CAT}] = graph[cat].size();
                //otherwise if no 0 then cat can move to all directions in graph
            }
        }
        queue<vector<int>> que;
        //initialize que with all result states
        for(int i = 1;i < n;i++) {
            que.push({0,i,MOUSE});
            que.push({0,i,CAT});
            que.push({i,i,MOUSE});
            que.push({i,i,CAT});
        }
        while(!que.empty()) {
            //get the result state
            int mouse = que.front()[0];
            int cat = que.front()[1];
            int turn = que.front()[2];
            que.pop();
            //get the result who is the winner of the result
            int current_result = result[{mouse,cat,turn}];
            //next step is get all previous states
            vector<vector<int>> prev_states;
            if(turn == MOUSE) {
                //if the current turn is of mouse then it would have got from cat move right
                for(auto &x : graph[cat]) {
                    //what are the possible previous states of cat
                    //append those states
                    prev_states.push_back({mouse,x,CAT});
                }
            }
            else {
                //if current turn is of cat then previously mouse have moved
                for(auto &x : graph[mouse]) {
                    // so get all those mouse states cat position is same 
                    //the turn is of MOUSE
                    prev_states.push_back({x,cat,MOUSE});
                }
            }
            for(auto &p_state : prev_states) {
                //we have to assign the results for these previous states and get the valid states
                //if the previous state is already a result it is encountered twice
                //in the sense duplicates avoid that this works as dp
                if(result.find(p_state) != result.end()) continue;
                int prev_mouse = p_state[0];
                int prev_cat = p_state[1];
                int prev_turn = p_state[2];
                //if the prev cat == 0 then remove that state also
                if(prev_cat == 0) continue;
                //if everything is fine then reduce the indegree
                degree[p_state]--;
                //if the previous turn was CAT and cat was winner similarly for mouse
                bool isMoverWinner = (current_result == CAT_WIN && prev_turn == CAT) || (current_result == MOUSE_WIN && prev_turn == MOUSE);
                //then current state is valid
                if(isMoverWinner || degree[p_state] == 0) {
                    //assign the current result to the previous state
                    result[p_state] = current_result;
                    //update in queue
                    que.push(p_state);
                }
            }
        }
        //after all traversal
        //if we reach the initial state then it would have contain the winner also in result
        //if the initial state never reached it is definately a draw no one is winner
        if(result.find({1,2,MOUSE}) != result.end()) return result[{1,2,MOUSE}];
        return DRAW;
    }
};