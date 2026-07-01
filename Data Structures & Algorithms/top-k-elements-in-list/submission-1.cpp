class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int, int>> freqs;
        for (auto elem: nums) {
            if (auto it = find_if(freqs.begin(), freqs.end(), [elem](auto& a) {
                return a.first == elem;
            });
             it != freqs.end()) {
                (*it).second++;
            } else {
                freqs.emplace_back(elem, 1);
            }
        }
        sort(freqs.begin(), freqs.end(), [](auto& a, auto& b) {return a.second > b.second;});
        vector<int> ret(k);
        transform(freqs.begin(), freqs.begin() + k, ret.begin(), [] (const auto& a) {return a.first;});
        return ret;
    }
};
