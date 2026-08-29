class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int num_arr = nums.size();
        std::array<int, 100000> larr;
        std::array<int, 100000> rarr;
        larr[0] = 1;
        rarr[0] = 1;

        for (int i = 1, j = num_arr - 1; i <= num_arr; ++i, --j) {
            larr[i] = larr[i - 1] * nums[i - 1];
            rarr[i] = rarr[i - 1] * nums[j];
        }

        // for (int i = 0; i <= num_arr; ++i)
        //     std::cout << larr[i] << " " << rarr[i] << std::endl;
        // std::cout << "===" << std::endl;
        std::vector<int> res;
        for (int i = 1; i <= num_arr; ++i) {
            const int j = num_arr - i;
            // std::cout << larr[i - 1] << " " << rarr[j] << std::endl;
            res.push_back(larr[i - 1] * rarr[j]);
        }
        return res;
    }
};

// simulation ex 1
// it 0: 2 * 4 * 6 -> rarr[1:3]
// it 1: 1 * 4 * 6 -> larr[0] * rarr[2:3]
// it 2: 1 * 2 * 6 -> larr[0:1] * rarr[3]
// it 3: 1 * 2 * 4 -> larr[0:2]
// simulation ex 2
// it 0: 0 * 1 * 2 * 3 -> rarr[1:4]
// it 1: -1 * 1 * 2 * 3 -> larr[0] * rarr[2:4]
// it 2: -1 * 0 * 2 * 3 -> larr[0:1] * rarr[3:4]
// it 3: -1 * 0 * 1 * 3 -> larr[0:2] * rarr[4]
// it 4: -1 * 0 * 1 * 2 -> larr[0:3]
// 2 arrays:
// prefix (total array + 1 to cover 0): larr[1, 2, 8, 48] -> 0,0-1,0-2,0-3
// suffix (total array + 1 to cover len(arr)): rarr[6, 24, 48, 48] -> 3,2-3,1-3,0-3
// 1-3 -> larr[-1] * rarr[2]
// 0 * 2-3 -> larr[0] * rarr[1]
// 0-1 * 3 -> larr[1] * rarr[0]
// 0-2 -> larr[2] * rarr[-1]