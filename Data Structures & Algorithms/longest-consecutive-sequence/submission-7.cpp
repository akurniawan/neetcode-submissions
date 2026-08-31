class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        else if (nums.size() == 1) return 1;
        
        int ret = -1;
        std::unordered_set<int> tmp(nums.begin(), nums.end());

        for (const auto& num: nums) {
            if (tmp.find(num - 1) == tmp.end()) {
                int counter = 1;
                while (tmp.find(num + counter) != tmp.end())
                    counter++;
                ret = max(ret, counter);
            }
        }
        return ret;
    }
};

// O(n * log(n))
// int longestConsecutive(vector<int>& nums) {
//     if (nums.size() == 0) return 0;
//     else if (nums.size() == 1) return 1;

//     std::sort(nums.begin(), nums.end());
//     int last_num = nums[0];
//     int counter = 1;
//     int res = 0;

//     for (int i = 1; i < nums.size(); ++i) {
//         const int& num = nums[i];
//         if (num - last_num != 1) {
//             // std::cout << "enter a" << std::endl;
//             if (num - last_num > 1) counter = 1;
//             last_num = num;
//             continue;
//         } else {
//             // std::cout << "enter b" << std::endl;
//             last_num = num;
//             counter += 1;
//             res = max(res, counter);
//         }
//         // std::cout << num << " " << res << " " << counter << std::endl;
//     }

//     return max(res, counter);
// }
