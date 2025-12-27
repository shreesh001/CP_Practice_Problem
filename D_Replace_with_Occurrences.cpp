#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> b(n);
        for (int i = 0; i < n; i++) cin >> b[i];
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) {
            groups[b[i]].push_back(i);
        }
        bool possible = true;
        vector<int> ans(n, 0);
        int label = 1; 
        for (auto &p : groups) {
            int k = p.first;
            auto &indices = p.second;
            if ((int)indices.size() % k != 0) {
                possible = false;
                break;
            }
            for (int i = 0; i < (int)indices.size(); i += k) {
                for (int j = 0; j < k; j++) {
                    ans[indices[i + j]] = label;
                }
                label++;
            }
        }
        if (!possible) {
            cout << -1 << "\n";
        } else {
            for (int x : ans) cout << x << " ";
            cout << "\n";
        }
    }
}
