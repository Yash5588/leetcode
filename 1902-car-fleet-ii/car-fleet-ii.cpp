class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        vector<double> res(n);
        stack<int> sta;
        for(int i = n-1;i >= 0;i--) {
            //check what is the next car we can collide
            while(!sta.empty() && cars[sta.top()][1] >= cars[i][1]) {
                sta.pop();
            }
            //if no car found
            if(sta.empty()) res[i] = -1;
            else {
                //but even if we find the next car
                //there is a chance that it's collision time is less than 
                //current car collision time
                //like if our current car collision time with that car is 3sec
                //and that other car collision time is 1.5sec
                //then think logically it will collide 1st right before we collide
                //it so we have to collide with the car with which this 1.5sec car
                //collide so remove lesser time than current car collision from stack
                while(!sta.empty()) {
                    double dist = cars[sta.top()][0] - cars[i][0];
                    double speed = cars[i][1] - cars[sta.top()][1];
                    double time = dist/speed;
                    if(time <= res[sta.top()] || res[sta.top()] == -1) {
                        res[i] = time;
                        break;
                    }
                    sta.pop();
                }
            }
            sta.push(i);
        }
        return res;
    }
};