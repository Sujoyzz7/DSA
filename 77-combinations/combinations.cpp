class Solution {
public:
    vector<vector<int>> ans;
    vector<int> current;

    void backtrack(int start, int n, int k) {
        // Combination is complete
        if (current.size() == k) {
            ans.push_back(current);
            return;
        }

        // Choose next number
        for (int i = start; i <= n; i++) {
            current.push_back(i);

            backtrack(i + 1, n, k);

            current.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        backtrack(1, n, k);
        return ans;
    }
};