class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // positive asteroids move right
        // first negative asteroid collides with first positive asteroid before
        if (asteroids.size() <= 1) return asteroids;
        vector<int> result;
        for (int b : asteroids) {
            bool exploded = false;
            while (!exploded && b < 0 && !result.empty() && result.back() > 0) {
                if (abs(result.back()) < abs(b)) {
                    result.pop_back();
                } else if (abs(result.back()) == abs(b)) {
                    result.pop_back();
                    exploded = true;
                } else {
                    exploded = true;
                }
            }
            if (!exploded) result.push_back(b);
        }
        return result;
    }
};