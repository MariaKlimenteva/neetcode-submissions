class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::set<int> unique_nums = {};
        for (auto num: nums) {
            unique_nums.insert(num);
        }
        return unique_nums.size() != nums.size();
    }
};