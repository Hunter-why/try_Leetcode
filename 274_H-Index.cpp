// Method: bucket sort and hash map
class Solution {
public:
    int hIndex(vector<int>& ct) {
        int n = ct.size();
        vector<int> bkt(n+1, 0);
        for (auto &it:ct) {
            if (it >= n)
                bkt[n]++;
            else
                bkt[it]++;
        }
        int cnt = 0;
        for (int i=n; i>=0; --i) {
            cnt += bkt[i];
            if (cnt >= i)
                return i;
        }
        return 0;
    }
};