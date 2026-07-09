#include <cstdlib>
#include <ctime>

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        srand(static_cast<unsigned int>(time(0))); 
        return rand() % (10) + 1;
        
    }
};