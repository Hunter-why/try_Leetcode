// Method : two vector<> which record number of appearance of char '0' ~ '9'.
class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> s(10, 0);
        vector<int> g(10, 0);
        int c1=0, c2=0;
        for (int i=0; i<secret.size(); ++i) {
            if (secret[i] == guess[i])
                ++c1;
            ++s[secret[i]-'0'];
            ++g[guess[i]-'0'];
        }
        for (int i=0; i<10; ++i) {
            c2 += min(s[i], g[i]);
        }
        c2 -= c1;
        string res = to_string(c1)+"A" + to_string(c2)+ "B";
        return res;
        // vector<unordered_set<int>> mp(10);
        // vector<int> count(10, 0);
        // int cnt1=0, cnt2=0;
        // for (int i=0; i<secret.size(); ++i)
        //     mp[secret[i]-'0'].insert(i);
        // for (int i=0; i<guess.size(); ++i) {
        //     int val = guess[i]-'0';
        //     if (mp[val].find(i) != mp[val].end()) {
        //         ++cnt1;
        //         mp[val].erase(i);
        //     }
        //     else {
        //         ++count[val];
        //     }
        // }
        // for (int i=0; i<10; ++i)
        //     cnt2 += min((int)count[i], (int)mp[i].size());
        // string res = to_string(cnt1)+"A" + to_string(cnt2)+ "B";
        // return res;
    }
};