using pii = std::pair<int, int>;

struct CompareSecond {
    bool operator()(const pii& p1, const pii& p2) {
        return p1.second > p2.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> map;

        for (const auto& num: nums)
            map[num]++;
        
        std::priority_queue<pii, vector<pii>, CompareSecond> q;
        for (const auto& [first, second]: map) {
            q.push({first, second});
            // std::cout << q.size() << " " <<first << " " << second << std::endl;
            if (q.size() > k) q.pop();
        }

        std::vector<int> res;
        while (!q.empty()) {
            const auto top = q.top();
            // std::cout << q.size() << " " << top.first << " " << top.second << std::endl;
            res.push_back(top.first);
            q.pop();
        }
        return res;
    }
};
