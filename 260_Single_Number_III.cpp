
// Method : split into two arrays according some bit with value '1'.
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0;
        for (auto &i:nums) {
            x ^= i;
        }
        int bit = 1;
        while ((x & bit) == 0) bit <<= 1;
        int x1 = 0, x2 = 0;
        for (auto &i:nums) {
            if ((i & bit) == 0) {
                x1 ^= i;
            }
            else {
                x2 ^= i;
            }
        }
        return {x1, x2};
    }
};