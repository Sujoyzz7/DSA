#include <vector>
#include <unordered_map>

class Solution {
public:
    int maxNumberOfFamilies(int n, std::vector<std::vector<int>>& reservedSeats) {
        // Map row number -> bitmask representing reserved seats (2 to 9)
        std::unordered_map<int, int> reservedMap;
        
        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            
            // Ignore seats 1 and 10 as they don't affect 4-person groups
            if (col >= 2 && col <= 9) {
                reservedMap[row] |= (1 << (col - 2));
            }
        }
        
        // Bitmasks for the three possible seat blocks
        const int LEFT_MASK   = 0b00001111; // Seats 2, 3, 4, 5
        const int RIGHT_MASK  = 0b11110000; // Seats 6, 7, 8, 9
        const int MIDDLE_MASK = 0b00111100; // Seats 4, 5, 6, 7
        
        // Assume every row can hold 2 groups initially
        int totalGroups = 2 * n;
        
        for (const auto& [row, mask] : reservedMap) {
            bool left   = (mask & LEFT_MASK) == 0;
            bool right  = (mask & RIGHT_MASK) == 0;
            bool middle = (mask & MIDDLE_MASK) == 0;
            
            int groupsPossible = 0;
            if (left && right) {
                groupsPossible = 2;
            } else if (left || right || middle) {
                groupsPossible = 1;
            }
            
            // Subtract the lost potential groups for this specific row
            totalGroups -= (2 - groupsPossible);
        }
        
        return totalGroups;
    }
};