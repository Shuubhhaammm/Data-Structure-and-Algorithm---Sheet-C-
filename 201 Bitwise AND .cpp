class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
       int cnt = 0;
        while (left != right) {
            left >>= 1;
            right >>= 1;
            cnt++;
        }
        return (left << cnt);
    }
};

/// 1111
/// 0101
/// 0110
/// 0111

/// 0100