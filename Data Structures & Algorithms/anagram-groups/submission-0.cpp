class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> myMap;
        vector<vector<string>> ret;
        for (int i = 0; i < strs.size(); ++i) {
            string not_changed_str = strs.at(i);
            sort(strs.at(i).begin(), strs.at(i).end());
            myMap[strs.at(i)].push_back(not_changed_str);
        }
        for (const auto& [_, value_vec] : myMap) {
            ret.push_back(value_vec);
        }
        return ret;
    }
};
