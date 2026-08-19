class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        vector<int> freq(128, 0);

        // Count required characters
        for (char c : t) {
            freq[c]++;
        }

        int left = 0;
        int required = t.size();

        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];

            // If this character is still needed
            if (freq[c] > 0) {
                required--;
            }

            freq[c]--;

            // Window contains all characters of t
            while (required == 0) {
                // Update minimum window
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                // Remove left character
                char leftChar = s[left];
                freq[leftChar]++;

                // Removing this character makes window invalid
                if (freq[leftChar] > 0) {
                    required++;
                }

                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};