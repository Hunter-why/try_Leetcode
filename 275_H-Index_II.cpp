// Method : binary serach. Be very careful about when you find the [l, r] which l = r-1 || l == r, you should check (ct[l], n-l) and (ct[r], n-r) both! 
class Solution {
public:
    int hIndex(vector<int>& ct) {
        int n = ct.size();
        if (n == 0)
            return 0;
        int l=0, r=n-1;
        while (l < r-1) {
            int mid = l+(r-l)/2;
            if (n-mid == ct[mid])
                return ct[mid];
            else if (n - mid > ct[mid])
                l = mid;
            else
                r = mid;
        }
        if (ct[l] >= n-l)
            return n-l;
        if (ct[r] >= n-r)
            return n-r;
        return 0;
    }
};