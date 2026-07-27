class Solution {
public:
    vector<int> subset;
    vector<vector<int>> ans;

    void allss(int i, vector<int>& nums) {
        if (i == nums.size()) {
            ans.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        allss(i + 1, nums);

        subset.pop_back();
        allss(i + 1, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        allss(0, nums);
        return ans;
    }
};