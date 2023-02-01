class Solution {
public:
    bool div(string s, string t) {
        string curr = t;
        while (curr.size() < s.size()) curr += t;
        return curr == s;
    }
    string gcdOfStrings(string str1, string str2) {
        string curr = str2;
        while (curr.size()) {
            if (div(str1, curr) && div(str2, curr)) return curr;
            curr.pop_back();
        }
        return "";
    }
};