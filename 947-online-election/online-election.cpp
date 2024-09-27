class TopVotedCandidate {
public:
    vector<int> maxInd;
    vector<int> time;
    int size;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int n = persons.size();
        vector<int> cnt(n);
        size = persons.size();
        int ma = INT_MIN,person = 0;
        for(int i = 0;i < n;i++) {
            cnt[persons[i]]++;
            if(cnt[persons[i]] >= ma) {
                ma = cnt[persons[i]];
                person = persons[i];
            }
            maxInd.push_back(person);
        }
        time = times;
        for(auto &x : maxInd) cout << x << endl;
    }
    
    int q(int t) {
        int ind = lower_bound(time.begin(),time.end(),t) - time.begin();
        if(ind >= size || time[ind] != t) {
            if(ind != 0) ind--;
        }  
        return maxInd[ind];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */