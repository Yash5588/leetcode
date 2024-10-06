class MKAverage {
public:
    multiset<long long> low, mid, high;
    long long midSum = 0;
    long long totalcount = 0;
    queue<long long> que;
    int m,k;
    bool removeFromSet(multiset<long long> &se, long long num) {
        auto iter = se.find(num);
        if(iter == se.end()) return false;
        se.erase(iter);
        return true;
    }
    void remove(int num) {
        if(removeFromSet(low, num)) {
            //mid to low
            int element = *mid.begin();
            low.insert(element);
            midSum -= element;
            mid.erase(mid.find(element));
            //high to mid
            element = *high.begin();
            midSum += element;
            mid.insert(element);
            high.erase(high.find(element));
        }
        else if(removeFromSet(mid, num)) {
            //high to mid
            midSum -= num;
            int element = *high.begin();
            midSum += element;
            mid.insert(element);
            high.erase(high.find(element));
        }
        else {
            removeFromSet(high, num);
        }
    }

    void insert_val(int num) {
        low.insert(num);
        if(low.size() > k) {
            int element = *low.rbegin();
            low.erase(low.find(element));
            midSum += element;
            mid.insert(element);
        }
        if(mid.size() > m - 2*k) {
            int element = *mid.rbegin();
            midSum -= element;
            mid.erase(mid.find(element));
            high.insert(element);
        }
    }
    MKAverage(int m, int k) {
        this->m = m;
        this->k = k;
    }
    
    void addElement(int num) {
        que.push(num);
        insert_val(num);
        totalcount++;
        if(totalcount > m) {
            int n = que.front();
            remove(n);
            que.pop();
            totalcount--;
        }
        cout << midSum << endl;
    }
    
    int calculateMKAverage() {
        if(totalcount < m) return -1;
        return midSum / (m - 2*k);
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */