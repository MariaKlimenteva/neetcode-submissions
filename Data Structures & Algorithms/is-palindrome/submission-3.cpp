class Solution {
public:
    bool isPalindrome(string s) {
        s.erase(remove_if(s.begin(), s.end(), [](unsigned char c) {
            return !isalnum(c);
        }), s.end());
        int r = 0;
        int l = s.size() - 1;
        while(r < l) {
            if (tolower(s.at(r)) != tolower(s.at(l))) return false;
            ++r; --l;
        }
        return true;
    }
};
