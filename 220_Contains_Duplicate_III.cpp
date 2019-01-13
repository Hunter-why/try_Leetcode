class Solution {
public:
    // time complexity O(nk), time limitation
    // bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    //     int n = nums.size();
    //     if (n == 0)
    //         return false;
    //     for (int i=0; i<n; ++i) {
    //         for (int j=1; j<=k && i+j<n; ++j) {
    //             if (abs((long long)nums[i+j]-nums[i])<=t) {
    //                 // cout << j << " " << i <<endl;
    //                 return true;
    //             }
    //         }
    //     }
    //     return false;
    // }
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        if (n < 2 || k < 1 || t < 0)
            return false;
        set<long long> ss;
        for (int i=0; i<n; ++i) {
            if (i > k)
                ss.erase(nums[i-k-1]);
            auto lb = ss.lower_bound((long long)nums[i] - t);
            if (lb != ss.end() && *lb <= (long long)nums[i]+t)
                return true;
            ss.insert(nums[i]);
        }
        return false;
    }
};