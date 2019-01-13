// Method : add a sentinel makes it easier
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (nums.empty())
            return res;
        string tmp;
        nums.push_back(nums[nums.size()-1]);
        tmp.append(to_string(nums[0]));
        bool flag = 1;
        for (int i=1; i<nums.size(); ++i) {
            if (nums[i-1] == nums[i] - 1){
                if (flag == 1) {
                    flag = 0;
                    tmp.append("->");
                }
                else
                    continue;
            }
            else {
                if (flag == 0) {
                    tmp.append(to_string(nums[i-1]));
                    res.push_back(tmp);
                    tmp.clear();
                    tmp.append(to_string(nums[i]));
                    flag = 1;
                }
                else {
                    res.push_back(tmp);
                    tmp.clear();
                    tmp.append(to_string(nums[i]));
                }
            }
        }
        
        return res;
    }
};