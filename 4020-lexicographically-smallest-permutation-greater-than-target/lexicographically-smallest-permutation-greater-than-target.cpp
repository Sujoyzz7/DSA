class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        vector<int> cnt(26, 0);
        for (char c : s) {
            cnt[c - 'a']++;
        }

        string prefix;

        // Match target from left to right
        int i = 0;
        for (; i < n; i++) {
            int c = target[i] - 'a';

            if (cnt[c] == 0)
                break;

            prefix += target[i];
            cnt[c]--;
        }

        /*
            Case 1:
            We could not match target completely.

            Try to make the first unmatched position greater.
        */
        if (i < n) {
            int cur = target[i] - 'a';

            for (int c = cur + 1; c < 26; c++) {
                if (cnt[c] > 0) {
                    string ans = prefix;
                    ans += char('a' + c);
                    cnt[c]--;

                    // Smallest possible suffix
                    for (int x = 0; x < 26; x++) {
                        ans.append(cnt[x], char('a' + x));
                    }

                    return ans;
                }
            }
        }

        /*
            If we cannot make the unmatched position greater,
            backtrack through the matched prefix.
        */

        for (int j = i - 1; j >= 0; j--) {

            // Restore target[j]
            cnt[target[j] - 'a']++;

            int cur = target[j] - 'a';

            // Find the smallest character greater than target[j]
            for (int c = cur + 1; c < 26; c++) {
                if (cnt[c] > 0) {

                    string ans = target.substr(0, j);
                    ans += char('a' + c);
                    cnt[c]--;

                    // Append all remaining characters in sorted order
                    for (int x = 0; x < 26; x++) {
                        ans.append(cnt[x], char('a' + x));
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};