class Solution {
public:
    bool isAnagram(string s, string t) {
        std::map<char, int> ana_flag;
        for (const auto& _s: s) {
            if (ana_flag.count(_s) == 0)
                ana_flag[_s] = 1;
            else
                ana_flag[_s] += 1;
        }

        for (const auto& _t: t) {
            if (ana_flag.count(_t) == 0) return false;

            ana_flag[_t] -= 1;
        }

        for (const auto& flag: ana_flag)
            if (flag.second != 0) return false;
        return true;
    }
};
