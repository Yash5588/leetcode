class StockSpanner {
public:
    stack<pair<long long,long long>> sta;
    int next(int price) {
        int c= 0;
        while(!sta.empty() && sta.top().first <= price) {
            c += sta.top().second;
            sta.pop();
        }
        sta.push({price,c+1});
        return c+1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */