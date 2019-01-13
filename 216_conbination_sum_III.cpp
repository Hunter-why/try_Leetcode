
//Method : Simple backtracing code. 
//        Since combination set contains no dup interger, watch out the index when dfs
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        if (k == 0 || n > 45 || n < 1)
            return res;
        vector<int> tmp;
        
        function<void (int)> dfs = [&](int  val) -> void
        {
            if (tmp.size() == k && val == 0) {
                res.push_back(tmp);
                return;
            }
            int start = tmp.empty()?1:tmp.back()+1;
            for (;start<10; ++start) {
                if (start > val)
                    return;
                tmp.push_back(start);
                dfs(val - start);
                tmp.pop_back();
            }
        };
        
        dfs(n);
        
        return res;     
    }
};