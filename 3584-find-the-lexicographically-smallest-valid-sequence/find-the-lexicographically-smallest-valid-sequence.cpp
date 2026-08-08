class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        if (m == 1) {
            return {0};
        }

        // suf[i] = number of characters of word2
        // that can be matched as a subsequence in word1[i...n-1]
        vector<int> suf(n + 1, m);

        int j = m - 1;

        for (int i = n - 1; i >= 0; --i) {
            if (j >= 0 && word1[i] == word2[j]) {
                --j;
            }

            suf[i] = j + 1;
        }

        vector<int> ans;

        int j2 = 0;
        bool usedMismatch = false;

        for (int i = 0; i < n && j2 < m; ++i) {

            // Normal exact match
            if (word1[i] == word2[j2]) {
                ans.push_back(i);
                ++j2;
            }
            else {
                // We already used the one mismatch
                if (usedMismatch) {
                    continue;
                }

                /*
                 * If we use i as the mismatch:
                 *
                 *   j2 characters already matched
                 *   + current mismatching character
                 *   + maximum suffix characters
                 *
                 * must be enough to form word2.
                 */
                if ((m - suf[i + 1]) + j2 + 1 >= m) {
                    ans.push_back(i);
                    ++j2;
                    usedMismatch = true;
                }
            }
        }

        if ((int)ans.size() != m) {
            return {};
        }

        return ans;
    }
};