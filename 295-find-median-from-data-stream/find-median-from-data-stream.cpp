class MedianFinder {
public:
    MedianFinder() {
    }
    priority_queue<int> left;
    priority_queue<int,vector<int>,greater<int>> right;
    void addNum(int num) {
        if(left.empty()) left.push(num);
        else{
            if(left.top() > num) {
                left.push(num);
            }
            else {
                right.push(num);
            }
        }
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