class RangeModule {
public:
    RangeModule() {}
    
    map<int,int> range;
    void addRange(int left, int right) {
        //[left,right]
        //get the intervals which can be included
        auto iter = range.lower_bound(left);
        //now check ranges which this range has been a part of
        while(iter != range.end() && iter->first <= right) {
            //update the end point of each anyway we are removing middle
            //ranges it is useful for end range
            right = max(iter->second, right);
            iter++;
            //remove after processing so that there won't be any problem while iterating
            range.erase(prev(iter));
        }
        //check for previous range if it might be merged as well
        if(iter != range.begin() && left <= (--iter)->second) {
            //update this interval only no need to add new interval
            iter->second = max(iter->second, right);
        }
        else {
            //add new range
            range[left] = right;
        }
    }
    
    //i need a range where it's start point is less than or equal to left and end point is greater than right
    bool queryRange(int left, int right) {
        auto iter = range.upper_bound(left); //prev of it will give less or equal range
        if(iter == range.begin()) return false; //no range
        return prev(iter)->second >= right;
        //this satisfies above specified condition if left condition is satisfied
        //it is satisfied here
    }
    
    void removeRange(int left, int right) {
        //get all the range which are part of this query range
        //keep track of end point of farthest removed range it is useful later
        int cutEnd = -1;
        auto iter = range.lower_bound(left);
        while(iter != range.end() && iter->first <= right) {
            //slightly included then remove it
            cutEnd = max(cutEnd, iter->second);
            iter++;
            range.erase(prev(iter));
        }
        //check for prev range which can be cutted off partially
        if(iter != range.begin() && left < (--iter)->second) {
            cutEnd = max(cutEnd, iter->second);
            //it might be spliited into 2 ranges like [[10,40]] query is [15,25] 
            //then the result is [[10,14],[26,40]]
            //[26,40] anyway we will add so modify first range
            iter->second = left;
        }
        //now here is significance of cutEnd
        //it tells whether range has been cutted off completely or partially
        if(right < cutEnd) {
            //we have cutted more than requied so add that range
            range[right] = cutEnd; //remaining range
        }
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */