class Solution {
public:
    vector<vector<int>> ans;
    vector<int> comb;

    void solve(int i, vector<int>& candidates, int target) {
        if (target == 0) {
            ans.push_back(comb);
            return;
        }

        if (i == candidates.size() || target < 0)
            return;

        comb.push_back(candidates[i]);
        solve(i, candidates, target - candidates[i]);
        comb.pop_back();

        solve(i + 1, candidates, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(0, candidates, target);
        return ans;
    }
};