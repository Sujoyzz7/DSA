class Solution {
public:
    bool stoneGameIX(std::vector<int>& stones) {
        int counts[3] = {0, 0, 0};
        
        for (int stone : stones) {
            counts[stone % 3]++;
        }
        
        if (counts[0] % 2 == 0) {
            return counts[1] > 0 && counts[2] > 0;
        } else {
            return std::abs(counts[1] - counts[2]) > 2;
        }
    }
};