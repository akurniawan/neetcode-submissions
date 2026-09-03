class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<vector<int>> res;
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            int l = i + 1;
            int r = nums.size() - 1;
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            while (l < r) {
                int total = nums[l] + nums[r] + nums[i];
                if (total == 0) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    ++l; --r;
                    while (l < r && nums[l] == nums[l - 1]) ++l;
                    // while (l < r && nums[r] == nums[r - 1]) --r;
                } else if (total < 0) {
                    ++l;
                } else {
                    --r;
                }
            }
        }
        return res;
    }
};

//[-1,0,1,2,-1,-4] -> [-4,-1,-1,0,1,2]