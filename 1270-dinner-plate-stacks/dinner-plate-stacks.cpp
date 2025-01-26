class DinnerPlates {
public:
    int size;
    DinnerPlates(int capacity) {
        size = capacity;
    }

    //we need vector named stack becoz we need indices
    //we priority queue to store the latest stack element index to add element

    vector<int> stack;
    //min head that is
    priority_queue<int, vector<int>, greater<int>> pq;

    void push(int val) {
        //remove invalid incides which are removed by pop
        if(!pq.empty() && stack.empty()) pq.pop();
        while (!pq.empty() && pq.top() >= stack.size()) pq.pop();
        if(!pq.empty()) { //there are some free spaces in stacts so we need leftmost stack in pq
            stack[pq.top()] = val;
            pq.pop();
            return;
        }    
        //add at end
        stack.push_back(val);
    }
    
    int pop() {
        //remove all invalid empty spaces which are filled with -1
        while(!stack.empty() && stack.back() == -1) stack.pop_back();
        if(stack.empty()) {
            //no elements 
            return -1;
        }
        int temp = stack.back();
        stack.pop_back();
        return temp;
    }
    
    int popAtStack(int index) {
        //we need to first get to the last index of that stack
        int start_idx = index * size;
        int last_idx = (index + 1) * size - 1;
        //sometimes the index of the stack might be invalid
        if(start_idx >= stack.size()) return -1;
        //now get a valid element in stack
        if(last_idx >= stack.size()) last_idx = stack.size()-1;
        while(last_idx >= start_idx && stack[last_idx] == -1) {
            last_idx--;
        }
        cout << last_idx << endl;
        if(last_idx < start_idx) return -1;
        int temp = stack[last_idx];
        //add empty indices
        pq.push(last_idx);
        stack[last_idx] = -1;
        return temp;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */