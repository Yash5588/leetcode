class BrowserHistory {
public:
vector<string>h;
int c;
    BrowserHistory(string homepage) {
        h.push_back(homepage);
        c=0;
        
    }
    
    void visit(string url) {
        h.resize(c+1);
        h.push_back(url);
        c++;
    }
    
    string back(int steps) {
        c=max(0,c-steps);
        return h[c];
        
    }
    
    string forward(int steps) {
        c=min((int)h.size()-1,c+steps);
        return h[c];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */