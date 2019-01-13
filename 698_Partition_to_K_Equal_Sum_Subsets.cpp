
// Method : backtracing
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if (k == 1)
            return true;
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (k > n || sum % k != 0)
            return false;
        int tar = sum / k;
        sort(nums.begin(), nums.end());
        vector<int> curSum(k, 0);
        vector<bool> taken(n, false);
        
        curSum[0] = nums[n-1];
        taken[n-1] = true;

        function<bool (int, int)> dfs = [&](int curIdx, int limit) -> bool
        {
            if (curSum[curIdx] == tar) {
                if (curIdx == k-2)
                    return true;
                return dfs(curIdx+1, n-1);
            }
            for (int i = limit; i>=0; --i) {
                if (taken[i])
                    continue;
                int tmp = curSum[curIdx] + nums[i];
                if (tmp <= tar) {
                    curSum[curIdx] += nums[i];
                    taken[i] = true;
                    bool res = dfs(curIdx, i-1);
                    taken[i] = false;
                    curSum[curIdx] -= nums[i];
                    if (res)
                        return true;
                }
            }
            return false;
        };
        
        return dfs(0, n-1);
    }
};