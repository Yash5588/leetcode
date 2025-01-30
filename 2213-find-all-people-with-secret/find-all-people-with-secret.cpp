class DisjointSet{
    vector<int> parent,size;
    public:
        DisjointSet(int n) {
            parent.resize(n);
            iota(parent.begin(),parent.end(),0);
            size.resize(n,1);
        }

        int findUPar(int node) {
            if(node == parent[node]) return node;
            return parent[node] = findUPar(parent[node]);
        }

        void unionBySize(int u, int v) {
            int ult_u = findUPar(u);
            int ult_v = findUPar(v);
            if(ult_u == ult_v) return;
            if(ult_u == 0) {
                parent[ult_v] = ult_u;
                size[ult_u] += size[ult_v];
            }
            else if(ult_v == 0) {
                parent[ult_u] = ult_v;
                size[ult_v] += size[ult_u];
            }
            else {
                if(size[ult_u] > size[ult_v]) {
                    parent[ult_v] = ult_u;
                    size[ult_u] += size[ult_v];
                }
                else {
                    parent[ult_u] = ult_v;
                    size[ult_v] += size[ult_u];
                }
            }
        }

        //removing nodes connection if ult p is not 0
        void reset(vector<int> &nodes) {
            for(auto &x : nodes) {
                if(findUPar(x) != 0) {
                    //make them as their parent and size as 1
                    parent[x] = x;
                    size[x] = 1;
                }
            }
        }
};
class Solution {
public:
    static bool sortByTime(vector<int> &a, vector<int> &b) {
        return a[2] < b[2];
    }

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        int size = meetings.size();
        //sorting
        sort(meetings.begin(), meetings.end(), sortByTime);
        int first = 0,last = 0;
        DisjointSet dsu(n);

        //connect 0 and firstperson
        dsu.unionBySize(0, firstPerson);

        //use two pointer to connect meetings of same time
        while(last < size) {
            vector<int> sameTime;
            while(last < size && meetings[first][2] == meetings[last][2]) {
                //while connecting make sure to store them
                //why becoz if no one knows secret of a meeting 
                //then we have to revoke the connection
                int u = meetings[last][0];
                int v = meetings[last][1];
                sameTime.push_back(u);
                sameTime.push_back(v);
                dsu.unionBySize(u,v);
                last++;
            }
            //revoke if node's ultimate parent is not 0
            //remove them from connection
            dsu.reset(sameTime);
            first = last;
        }
        //get all the nodes whose ultimate parent is 0
        vector<int> res;
        for(int i = 0;i < n;i++) {
            if(dsu.findUPar(i) == 0) res.push_back(i);
        }
        return res;
    }
};