class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int, int> map_idx;

        for (int i = 0; i < nums.size(); ++i)
            map_idx[nums[i]] = i;

        for (int i = 0; i < nums.size(); ++i) {
            int diff = target - nums[i];
            if (map_idx.count(diff) && map_idx[diff] != i)
                return {i, map_idx[diff]};
        }

        return {};
    }
};
