class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::set<int> flags;
        for (const auto &num : nums) {
            if (flags.count(num) != 0) return true;
            flags.insert(num);
        }
        return false;
    }
};