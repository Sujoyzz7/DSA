class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int dp1 = 0, dp2 = 0, dp3 = 0;

        for (int i = n - 1; i >= 0; i--) {
            int best = INT_MIN;
            int sum = 0;

            sum += stoneValue[i];
            best = max(best, sum - dp1);

            if (i + 1 < n) {
                sum += stoneValue[i + 1];
                best = max(best, sum - dp2);
            }

            if (i + 2 < n) {
                sum += stoneValue[i + 2];
                best = max(best, sum - dp3);
            }

            dp3 = dp2;
            dp2 = dp1;
            dp1 = best;
        }

        if (dp1 > 0) return "Alice";
        if (dp1 < 0) return "Bob";
        return "Tie";
    }
};