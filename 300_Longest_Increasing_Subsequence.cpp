class Solution {
public:
    // dp/ O(n^2)
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        vector<int> f(n, 1);
        for (int i=0; i<n; ++i) {
            for (int j=0; j<i; ++j) {
                if (nums[i] > nums[j]) {
                    f[i] = max(f[i], f[j] + 1);
                }
            }
        }
        return *max_element(f.begin(), f.end());
    }
    // smarter method. O(nlogn)

    // int lengthOfLIS(vector<int>& nums) {
    //     if (nums.empty())
    //         return 0;
    //     vector<int> s;
    //     s.push_back(nums[0]);
    //     for (int i=0; i<nums.size(); ++i) {
    //         auto pos = lower_bound(s.begin(), s.end(), nums[i]);
    //         if (pos == s.end())
    //             s.push_back(nums[i]);
    //         else
    //             *pos = nums[i];
    //     }
    //     return s.size();
    // }

// O(nlogn). lower_bound implemented by getUp().
    
//     int getUp(vector<int> &s, int k) {
//         int l=-1,r=s.size()-1;
//         while (r-l>1) {
//             int m=l+(r-l)/2;
//             if (s[m] >= k)
//                 r=m;
//             else
//                 l=m;
//         }
//         return r;
//     }
//     int lengthOfLIS(vector<int>& nums) {
//         if (nums.empty())
//             return 0;
//         vector<int> s;
//         s.push_back(nums[0]);
//         for (int i=0; i<nums.size(); ++i) {
//             if (nums[i] < s[0])
//                 s[0] = nums[i];
//             else if (nums[i] > s[s.size()-1])
//                 s.push_back(nums[i]);
//             else
//                 s[getUp(s,nums[i])] = nums[i];
//         }
//         return s.size();
        
//     }
};