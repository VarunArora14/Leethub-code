class Solution {
public:
    int minimumPartition(string s, int k) {
    long long n = 0, res = 1;
    for (int i = 0; i < s.size(); ++i) {
        n = n * 10 + s[i] - '0';
        if (n > k) {
            ++res;
            n = s[i] - '0';
        }
        if (n > k)
            return -1;
    }
    return res;
}
};
// partition not possible only when k<9 and any digit>9 
// here we have to check if the new number <k so we maitain currnum and prevnum