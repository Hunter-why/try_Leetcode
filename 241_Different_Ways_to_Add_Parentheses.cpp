// Method : Divide and Conquer. res.push_back(BinaryOp(every elem in left, every elem in right)).  
//      if no Binary Op Char, then return as int.
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        vector<int> left, right;
        for (int i=0; i<input.size(); ++i) {
            char now = input[i];
            if (now == '+' || now == '-' || now == '*') {
                left = diffWaysToCompute(input.substr(0, i));
                right = diffWaysToCompute(input.substr(i+1));
                for (auto &l:left) {
                    for (auto &r:right) {
                        res.push_back(now=='+'?l+r:(now=='-'?l-r:l*r));
                    }
                }
            }
        }
        if (res.empty()) {
            res.push_back(stoi(input));
            return res;
        }
        return res;
    }
};