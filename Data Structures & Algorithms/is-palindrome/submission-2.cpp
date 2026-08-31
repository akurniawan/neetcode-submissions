using sv = std::string_view;

class Solution {
public:
    bool isPalindrome(string s) {
        string trimmed = "";

        for (int i = 0; i < s.size(); ++i)
            if (std::isalpha(s[i]) || std::isdigit(s[i])) trimmed += std::tolower(s[i]);

        // std::cout << trimmed << std::endl;

        int length = trimmed.size();
        for (int i = 0, j = length - 1; i < j; ++i, --j)
            if (trimmed[i] != trimmed[j]) return false;

        return true;
    }
};
