
// Method 1: trial and error. O(nlogn).
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size()-1;
        int l=1, r=n;
        while (l < r) {
            int mid = l+(r-l)/2;
            int cnt = 0;
            for (int i=0; i<=n; ++i) {
                if (nums[i] <= mid && nums[i] >= l)
                    ++cnt;
            }
            if (cnt <= mid-l+1)
                l = mid + 1;
            else 
                r = mid;
        }
        return l;
    }
};

// Method 2: like the problem "find the entry of the cycle link list", in which node->next is similar to nums[i]. O(n).
class Solution {
public:
    
    int findDuplicate(vector<int>& nums) {
        if (nums.size() < 2)
            return -1;
        int fast = nums[nums[0]], slow = nums[0];
        while (fast != slow) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        slow = 0;
        while (fast != slow) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};