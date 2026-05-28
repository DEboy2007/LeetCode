class Solution {
public:
    string predictPartyVictory(string senate) {
        deque<int> radiant;
        deque<int> dire;
        int n = senate.length();
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') radiant.push_back(i);
            if (senate[i] == 'D') dire.push_back(i);
        }
        while (true) {
            if (radiant.empty()) return "Dire";
            else if (dire.empty()) return "Radiant";
            int r = radiant.front();
            int d = dire.front();
            dire.pop_front();
            radiant.pop_front();
            if (r < d) {
                radiant.push_back(r + n);
            } else {
                dire.push_back(d + n);
            }
        }
        
    }
};