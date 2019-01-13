// Method: this is so called a "trial and error" algorithm.
// 		  Firstly, sort the vector<>, the maxDist is nums[n-1] - nums[0].
// 		  Solution Space is [0, maxDist], we use binary search to find the answer "m".
//        for each region of vector with start idx i (0 <= i < n), check every [i, j] (i < j < n) that nums[j]-nums[i] <= m, 
//		  in which m is the possible answer when doing binary search.
//		  count every region [i, j] ti get the pair numbers "cnt" that dist<= m.
//	      if cnt < k, then current m is too small, else if cnt >= k, current m maybe too big, we want the exact "m".

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0, r = nums[n-1] - nums[0];
        int cnt;
        while (l<r) {
            cnt = 0;
            int m = l+(r-l)/2;
            for (int i=0, j=i+1; i<n; ++i) {
                while (j < n && nums[j]-nums[i] <= m) ++j;
                cnt += j-i-1;
            }
            if (cnt < k)
                l = m+1;
            else 
                r = m;
        }
        return l;
    }
};