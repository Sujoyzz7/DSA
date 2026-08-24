class Solution {
public:
    long long stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        vector<long long> prefix(n);
        prefix[0] = stones[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + stones[i];
        }

        // dp[i] = maximum score difference starting
        // when the first i+1 stones have been merged.
        //
        // Transition:
        // Either stop merging here, or merge further.
        //
        // dp[i] = max(dp[i+1], prefix[i] - dp[i+1])

        long long best = prefix[n - 1];

        for (int i = n - 2; i >= 1; i--) {
            best = max(best, prefix[i] - best);
        }

        return best;
    }
};