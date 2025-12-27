#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    if (!(cin >> T)) return 0;
    vector<pair<int, vector<int>>> tests;
    tests.reserve(T);
    int global_max_val = 0;
    for (int tc = 0; tc < T; ++tc) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            global_max_val = max(global_max_val, a[i]);
        }
        tests.emplace_back(n, move(a));
    }
    
    // Precompute divisors up to global_max_val
    int A = max(1, global_max_val);
    vector<vector<int>> divisors(A+1);
    for (int d = 1; d <= A; ++d) {
        for (int m = d; m <= A; m += d) divisors[m].push_back(d);
    }
    
    // Solve each test
    for (auto &pr : tests) {
        int n = pr.first;
        vector<int> &a = pr.second;
        
        // cnt[d] = how many elements in current prefix divisible by d
        // only divisors up to A matter; we will only touch divisors[a[i]]
        vector<int> cnt(A+1, 0);
        // freqCount[c] = number of divisors that currently have count == c
        // max possible c is n
        vector<int> freqCount(n+2, 0);
        
        int curMax = 0; // largest c with freqCount[c] > 0 (may be adjusted)
        vector<int> ans(n, 0);
        for (int i = 0; i < n; ++i) {
            int x = a[i];
            // update counts for divisors of x
            for (int d : divisors[x]) {
                int old = cnt[d];
                if (old > 0) {
                    --freqCount[old];
                }
                ++cnt[d];
                ++freqCount[cnt[d]];
                if (cnt[d] > curMax) curMax = cnt[d];
            }
            
            int len = i + 1;
            // find the largest c such that freqCount[c] > 0 and c != len
            int pick = curMax;
            // if pick == len or freqCount[pick]==0, step down until valid or zero
            while (pick > 0 && (freqCount[pick] == 0 || pick == len)) --pick;
            ans[i] = pick;
            
            // optional: keep curMax consistent (move it down if no divisors have that count)
            while (curMax > 0 && freqCount[curMax] == 0) --curMax;
        }
        
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << (i+1==n ? '\n' : ' ');
        }
    }
    return 0;
}
