class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> f_nums;
        for (auto elem: nums) {
            ++f_nums[elem];
        }
        vector<pair<int,int>> freqs(f_nums.begin(), f_nums.end());
        sort(freqs.begin(), freqs.end(), [](auto& a, auto& b) {return a.second > b.second;});
        vector<int> ret(k);
        transform(freqs.begin(), freqs.begin() + k, ret.begin(), [] (const auto& a) {return a.first;});
        return ret;
    }
};
