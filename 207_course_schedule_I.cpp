
// Method 1: for every vertex that has not been visited, DFS and see if his prerequisites already in the "pre list".
//          if yes, cycle exits, return false; if not, continue dfs untill a isolated vertex, return yes.
class Solution {
public:
    bool dfs(int v, vector<int> &pre, vector<bool> &vst, vector<vector<int>> &mp) {
        if (find(pre.begin(), pre.end(), v) != pre.end())
            return false;
        if (mp[v].empty()) {
            vst[v] = true;
            return true;
        }
        pre.push_back(v);
        for (auto it:mp[v]) {
            if (vst[it])
                continue;
            // pre.push_back(it);
            if (!dfs(it, pre, vst, mp))
                return false;
            vst[it] = true;
            // pre.pop_back();
        }
        pre.pop_back();
        return true;
    }
    bool canFinish(int n, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> mp(n, vector<int>{});
        for (auto &i:prerequisites) {
            mp[i.first].push_back(i.second);
        }
        vector<int> pre;
        vector<bool> vst(n, false);
        for (int i=0; i<n; ++i) {
            if (mp[i].empty()) {
                vst[i] = true;
                continue;
            }
            pre.push_back(i);
            for (auto it:mp[i]) {
                if (vst[it])
                    continue;
                if (!dfs(it, pre, vst, mp))
                    return false;
                vst[it] = true;
            }
            pre.pop_back();
        }
        return true;
    }
};

// Method 2: see annotations below
class Solution {
public:
    bool canFinish(int n, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>>  base(n, vector<int>{});    // course i support courses in base[i].
        vector<int> counter(n, 0);      // how many courses must be done before course i.

        for (auto &i:prerequisites) {
            base[i.second].push_back(i.first);
            ++counter[i.first];
        }
        deque<int> que;
        for (int i=0; i<n; ++i) {
            if (counter[i] == 0)
                que.push_back(i);   // this que store the ready courses that depends on no course
        }
        int cnt = 0;
        while (!que.empty()) {
            int x = que.front();
            que.pop_front();        // travesal the ready course's base list
            ++cnt;
            for (auto &it:base[x]) {
                if (--counter[it] == 0) // for every supported courses, minus one to see if it has any prerequisites
                    que.push_back(it);  // course it depends on no course now.
            }
        }
        return cnt == n;    // if handles all courses, return true
    }
};




