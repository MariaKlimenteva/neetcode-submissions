class Solution {
public:
    char special_delim = '#';
    string encode(vector<string>& strs) {
        string result;
        for (string s: strs) {
            result += to_string(s.length());
            result.push_back(special_delim);

            result += s;
        }
        return result;
    }

    vector<string> decode(string s) {
        int i = 0;
        vector<string> result;
        while (i < s.length()) {
            int pos = s.find(special_delim, i);
            int len = stoi(s.substr(i, pos - i));
            i = pos + 1;
            result.push_back(s.substr(i, len));
            i += len;

        }
        return result;
    }

};