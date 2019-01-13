// Method : 0-1 knapsack problem, using dp to identify the points can reach, then return.
//          using bitset<> can save space
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0)
            return false;
        int target = sum / 2;
        vector<bool> dp(sum+1,0);
        dp[0] = true;
        for (int i=0; i<nums.size(); ++i) {
            for (int j=sum; j>=nums[i]; --j) {
                if (dp[j-nums[i]] == true)
                    dp[j] = true;
            }
        }
        return dp[target];
    }

};