#include<ranges>

#define SEP "kucingberanak"

class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for (const auto& str: strs) {
            std::string cstr;
            if (str == "") cstr = "empty";
            else cstr = str;

            if (encoded != "")
                encoded += SEP + cstr;
            else
                encoded += cstr;
        }

        return encoded;
    }

    vector<string> decode(string s) {
        std::cout << s << std::endl;
        if (s == "empty") return {""};
        if (s.size() == 0) return {};

        auto parts = s | std::views::split(std::string{SEP});
        vector<string> decoded;

        for (const auto&& part: parts) {
            std::string s(part.begin(), part.end());
            if (s == "empty") decoded.push_back("");
            else decoded.push_back(s);
        }
        return decoded;
    }
};
