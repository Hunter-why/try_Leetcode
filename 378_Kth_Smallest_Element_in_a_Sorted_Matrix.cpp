
// Method 1: min heap, every time pop the min elem, add a new elem in corresponding vector<int> if it still has one.
//          repeat K times.
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int row = matrix.size();
        if (row == 0)
            return -1;
        int col = matrix[0].size();
        if (col == 0)
            return -1;
        vector<pair<int, int>> minhp;
        vector<int> nowidx(row, 0);
        auto cmp = [](pair<int, int> x, pair<int, int> y) {
            return x.first > y.first;
        };
        for (int i=0; i<row; ++i) {
            minhp.push_back({matrix[i][0], i});
        }
        make_heap(minhp.begin(), minhp.end(), cmp);
        while (k--) {
            pop_heap(minhp.begin(), minhp.end(), cmp);
            auto tmp = minhp.back();
            if (k == 0)
                return tmp.first;
            if (nowidx[tmp.second] == col-1) {
                minhp.pop_back();
                continue;
            }
            else {
                ++nowidx[tmp.second];
                minhp.pop_back();
                minhp.push_back({matrix[tmp.second][nowidx[tmp.second]], tmp.second});
                push_heap(minhp.begin(), minhp.end(), cmp);
            }
        }
        return -1;
    }
};

// Method 2: "Trial and error". test [min_val, max_val] via binary search and check if it is the K-th element.
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int row = matrix.size();
        if (row == 0)
            return -1;
        int col = matrix[0].size();
        if (col == 0)
            return -1;
        int l = matrix[0][0], r = matrix[row-1][col-1];
        int cnt;
        while (l < r) {
            cnt = 0;
            int m = l+(r-l)/2;
            for (int i=0; i<row; ++i) {
                auto pos = upper_bound(matrix[i].begin(), matrix[i].end(), m);
                cnt += pos-matrix[i].begin();
            }
            if (cnt < k)
                l = m+1;
            else 
                r = m;
        }
        return l;
    }
};






