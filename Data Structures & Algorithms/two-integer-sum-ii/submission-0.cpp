class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int length = numbers.size();
        for (int i = 0, j = length - 1; i < j;) {
            if (numbers[i] + numbers[j] != target) {
                int orig = numbers[i] + numbers[j];
                int a = numbers[i + 1] + numbers[j];
                int b = numbers[i] + numbers[j - 1];
                if (orig > target) {
                    if (a > b) j--;
                    else if (a < b) i++;
                    else {
                        i++;
                        j--;
                    }
                } else if (orig < target) {
                    if (a > b) i++;
                    else if (a < b) j--;
                    else {
                        i++;
                        j--;
                    }
                }
            } else {
                return {i+1, j+1};
            }
        }
    }
};
