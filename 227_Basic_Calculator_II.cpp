// Method: just handle it...
class Solution {
public:
    template <typename T>
    void print(T &a) {
        for (auto &it:a)
            cout << it <<" ";
        cout <<endl;
    }

    int calculate(string s) {
        deque<int> que;
        string op;
        string tmp;
        // int num = 0;
        tmp.clear();
        op.clear();
        int  i=0;
        while (i < s.size()) {
            // print(que);
            // cout << s[i] <<endl;
            if (s[i] == ' ') {
                ++i;
                continue;
            }
            if (s[i] <= '9' && s[i] >= '0')
                tmp.push_back(s[i++]);
            else {
                if (!tmp.empty()) {
                    que.push_back(stoi(tmp));
                    tmp.clear();
                }
                if (s[i] == '+' || s[i] == '-') {
                    op.push_back(s[i]);
                    ++i;
                }
                else {
                    int j;
                    int fst = que.back();
                    que.pop_back();
                    for (j = i+1;j<s.size(); ++j) {
                        if (s[j] == ' ')
                            continue;
                        if (s[j] <='9' && s[j] >= '0')
                            tmp.push_back(s[j]);
                        else
                            break;
                    }
                    // cout << tmp <<endl;
                    int snd = stoi(tmp);
                    tmp.clear();
                    que.push_back(s[i]=='*'?(fst*snd):(fst/snd));   
                    i = j;
                }
            }
        }
        if (!tmp.empty()) {
            // cout << tmp <<endl;
            que.push_back(stoi(tmp));
        }
        // print(que);
        if (op.size() == 0)
            return que.back();
        int res = que.front();
        que.pop_front();
        for (auto &ch:op) {
            auto snd = que.front();
            que.pop_front();
            if (ch == '+')
                res += snd;
            else
                res -= snd;
        }
        return res;
    }
};