class MedianFinder {
public:
    MedianFinder() {
    }
    priority_queue<int> left;
    priority_queue<int,vector<int>,greater<int>> right;
    void addNum(int num) {
        //check if left portion is empty or not
        if(left.empty()) left.push(num);
        else{
            //compare with top so that the current element belongs which portion
            if(left.top() > num) {
                left.push(num);
            }
            else {
                right.push(num);
            }
        }
        //balancing is done here when the diff exceeds 1 we have to balance to get median
        if(abs((int)left.size() - (int)right.size()) > 1) {
            if(left.size() > right.size()) {
                right.push(left.top());
                left.pop();
            }
            else {
                left.push(right.top());
                right.pop();
            }
        }
    }
    double findMedian() {
        //check  sizes and return the median accordingly
        if(left.size() == right.size()) {
            return (left.top() + right.top())/2.0;
        }
        else if(right.size() > left.size()) return right.top();
        return left.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */