
// Method 1: maintain two vectors which hold prefix- and postfix-ed product result.
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> fwd(n, 1);
        vector<int> bwd(n, 1);  
        for (int i=1; i<n; ++i) {
            fwd[i] = fwd[i-1] * nums[i-1];
            bwd[n-1-i] = bwd[n-i] * nums[n-i];
        }
        vector<int> res(n, 1);
        for (int i=0; i<n; ++i)
            res[i] = fwd[i] * bwd[i];
        return res;
    }
};
// optimization: use vector res hold postfix, nums hold prefix, and product.
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        // vector<int> fwd(n, 1);
        // vector<int> bwd(n, 1);
        vector<int> res(n ,1);
        for (int i=1; i<n; ++i) {
            res[n-1-i] = res[n-i] * nums[n-i];
        }
        for (int i=1; i<n; ++i) {
            nums[i] = nums[i-1] * nums[i];
            
        }
        for (int i=1; i<n; ++i)
            res[i] = res[i] * nums[i-1];
        return res;
    }
};