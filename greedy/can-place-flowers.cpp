class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // empty
        if (flowerbed.size() == 0) {
            if (n != 0) { return false; }
            return true;
        }
        // one-length
        if (flowerbed.size() == 1) {
            if (n >= 1 && flowerbed[0] == 1) { return false; }
            return true;
        }
        // check first index
        if (flowerbed[0] == 0 && flowerbed[1] == 0) {
            flowerbed[0] = 1;
            n--;
        }
        for (int i = 1; i < flowerbed.size() - 1; i++) {
            if (n == 0) { return true; }
            if (flowerbed[i] != 0) { continue; }
            if (flowerbed[i + 1] != 0 || flowerbed[i - 1] != 0) { continue; }
            flowerbed[i] = 1;
            n--;
        }
        // check last index
        if (flowerbed[flowerbed.size() - 1] == 0 && flowerbed[flowerbed.size() - 2] == 0) {
            flowerbed[flowerbed.size() - 1] = 1;
            n--;
        }
        return (n <= 0);
    }
};