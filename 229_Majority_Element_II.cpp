
// Method : similar to find the element appears more than n/2. there are at most 2 elements appears more than n/3
//          so keep two register e1 & e2, at last, check if they are valid. 
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int e1 = 0, e2 = 0;
        int cnt1 = 0, cnt2 = 0;
        for (auto &i:nums) {
            if (i == e1) {
                ++cnt1;
            }
            else if (i == e2) {
                ++cnt2;
            }
            else if (cnt1 == 0) {
                e1 = i;
                ++cnt1;
            }
            else if (cnt2 == 0) {
                e2 = i;
                ++cnt2;
            }
            else {
                --cnt1;
                --cnt2;
            }
        }
        cnt1 = 0, cnt2 = 0;
        for (auto &i:nums) {
            if (i == e1) {
                ++cnt1;
            }
            else if (i == e2) {
                ++cnt2;
            }
        }
        vector<int> res;
        if (cnt1 > nums.size() / 3)
            res.push_back(e1);
        if (cnt2 > nums.size() / 3)
            res.push_back(e2);
        
        return res;
    }
};