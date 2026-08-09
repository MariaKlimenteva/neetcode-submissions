class Solution {
public:
    vector<vector<int>> twoSum(vector<int>& nums, int sum) {
        int right = nums.size() - 1;
        int left = 0;
        vector<vector<int>> result;
        while (left < right) {
            int s = nums[left] + nums[right];
            if (s == sum) {
                result.push_back({nums[left], nums[right]});
                ++left; --right;
                while (left < right && nums[left] == nums[left-1]) ++left;
                while (left < right && nums[right] == nums[right+1]) --right;
            } else if (s < sum) {
                left++;
            } else {
                right--;
            }
        }
        return result;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        size_t n = nums.size();
        vector<vector<int>> result;
        for (int i = 0; i < n; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            vector<int> sliced(nums.begin() + i + 1, nums.end());
            vector<vector<int>> res = twoSum(sliced, - nums.at(i));
            if (!res.empty()) {
                for (auto vec: res) {
                    result.push_back({nums[i], vec[0], vec[1]});
                }
                
            }
        }
        return result;
    }
};
