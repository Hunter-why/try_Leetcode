
// Method : left and right, ++left and --right, untill find the max area
//          note that length is decreasing, so we want to find the larger height.
class Solution {
public:
    // Time Limited
    // int maxArea(vector<int>& a) {
    //     int n=a.size(), res=0;
    //     for (int i=0; i<n; ++i) {
    //         for (int j=0; j<n; ++j) {
    //             res = max(res, min(a[i], a[j]) * abs(i-j));
    //         }
    //     }
    //     return res;
    // }

    //  AC but not that good
    // int maxArea(vector<int>& a) {
    //     int n=a.size(), res=0;
    //     for (int i=0; i<n; ++i) {
    //         for (int j=n-1; j>i; --j) {
    //             res = max(res, min(a[i], a[j]) * abs(i-j));
    //             if (a[i] <= a[j])
    //                 break;
    //         }
    //     }
    //     return res;
    // }

    // AC code
    int maxArea(vector<int>& a) {
        int left = 0, right=a.size()-1, res=0;
        while (left < right) {
            int minh = min(a[left], a[right]);
            res = max(res, minh * (right-left));
            if (a[left] < a[right]) {
                while(a[left] <= minh && left < right) left++;
            }
            else {
                while (a[right] <= minh && left < right) --right;
            }
        }
        return res;
    }
};