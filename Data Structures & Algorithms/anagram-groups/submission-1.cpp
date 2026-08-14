class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::map<std::map<char, int>, vector<string>> store;

        for (const auto& str: strs) {
            std::map<char, int> count;
            for (int i = 0; i < str.size(); ++i) {
                if (count.count(str[i]) == 0) count[str[i]] = 1;
                else count[str[i]] += 1;
            }

            store[count].push_back(str);
            // std::cout << std::endl << bin << std::endl;
        }

        std::vector<vector<string>> res;
        for (const auto &map_pair: store)
            res.push_back(map_pair.second);

        return res;
    }
};