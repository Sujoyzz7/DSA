class Solution {
public:
    vector<vector<int>> ans;
    vector<int> current;

    void backtrack(int start, vector<int>& nums) {
        // Every current selection is a valid subset
        ans.push_back(current);

        for (int i = start; i < nums.size(); i++) {
            // Choose
            current.push_back(nums[i]);

            // Explore
            backtrack(i + 1, nums);

            // Undo choice
            current.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(0, nums);
        return ans;
    }
};