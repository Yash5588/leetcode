class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.length();
        queue<int> radiant;
        queue<int> dire;
        for(int i = 0;i < n;i++) {
            if(senate[i] == 'R') {
                radiant.push(i);
            }
            else {
                dire.push(i);
            }
        }
        while(!radiant.empty() && !dire.empty()) {
            //The radiant can eliminate dire
            //push radiant at end and remove dire
            if(radiant.front() < dire.front()) {
                radiant.push(radiant.front()+n);
                radiant.pop();
                dire.pop();
            }
            //The dire can eliminate radiant
            //push dire at end and remove radiant
            else {
                dire.push(dire.front()+n);
                dire.pop();
                radiant.pop();
            }
        }
        if(radiant.empty()) return "Dire";
        return "Radiant";
    }
};