class Solution {
public:
    //coordinate compression
    int mod = 1e9+7;
    int rectangleArea(vector<vector<int>>& rectangles) {
        int n = rectangles.size();
        //first add coordinates to sets
        set<int> x_coord,y_coord;
        for(auto &rec : rectangles) {
            x_coord.insert(rec[0]);
            x_coord.insert(rec[2]);
            y_coord.insert(rec[1]);
            y_coord.insert(rec[3]);
        }
        //convert to area becoz we need it for area calculation
        vector<int> x(x_coord.begin(),x_coord.end());
        vector<int> y(y_coord.begin(),y_coord.end());
        //secondly map each coordinate with corresponding index
        unordered_map<int,int> x_ind, y_ind;
        for(int i = 0;i < x.size();i++) {
            x_ind[x[i]] = i;
        }
        for(int j = 0;j < y.size();j++) {
            y_ind[y[j]] = j;
        }
        //for marking take a boolean rectangle
        vector grid(x_coord.size(), vector (y_coord.size(),false));
        for(auto &rec : rectangles) {
            //it's a half open interval [x1,x2);
            for(int x_val = x_ind[rec[0]]; x_val < x_ind[rec[2]]; x_val++) {
                for(int y_val = y_ind[rec[1]];  y_val < y_ind[rec[3]]; y_val++) {
                    //mark all the inbetweem indices of both x and y to true
                    grid[x_val][y_val] = true;
                }
            }
        }

        //now we have small pieces of rectangles to take care of
        //we have indices in grid 
        //we need to get original values for area
        long long area = 0;
        for(int i = 0;i < grid.size();i++) {
            for(int j = 0;j < grid[0].size();j++) {
                if(grid[i][j]) {
                    //we have starting indices stored here i and j
                    long long height = (x[i+1] - x[i]);
                    long long width = (y[j+1] - y[j]);
                    area = (area + height * width) % mod;
                }
            }
        }
        return area;
    }
};