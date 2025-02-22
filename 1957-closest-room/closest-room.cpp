class Solution {
public:
    static bool sortBySec(vector<int> &a, vector<int> &b) {
        return a[1] > b[1];
    }
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        int n = rooms.size();
        //sort the queries and rooms in descending order of their sizes
        sort(rooms.begin(), rooms.end(),sortBySec);
        //add index for queries
        for(int i = 0;i < queries.size();i++) {
            queries[i].push_back(i);
        }
        sort(queries.begin(), queries.end(), sortBySec);

        //store all the room ids which satisfy min size condition
        set<int> ids;
        int j = 0;
        vector<int> ans(queries.size(),-1);
        for(auto &q : queries) {
            int id = q[0];
            int min_size = q[1];
            int idx = q[2];
            cout << id << endl;
            while(j < n && rooms[j][1] >= min_size) {
                ids.insert(rooms[j][0]);
                j++;
            }
            //get just greater and just smaller for min absolute diff
            auto just_greater = ids.lower_bound(id);
            int mi = INT_MAX;
            if(just_greater != ids.end()) {
                if(mi >= *just_greater - id) {
                    ans[idx] = *just_greater;
                    mi = *just_greater - id;
                }
            }
            if(just_greater != ids.begin()) {
                auto just_smaller = --just_greater;
                if(mi >= id - *just_smaller) {
                    ans[idx] = *just_smaller;
                    mi = id - *just_smaller;
                }
            }
        }
        return ans;
    }
};