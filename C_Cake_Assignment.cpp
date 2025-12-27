#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long k;
        unsigned long long x;
        cin >> k >> x;
        vector<int> ops;
        for (long long i = k; i >= 1; --i) {
            unsigned long long mid = 1ULL << i; // 2^i
            if (x == mid) break;
            if (x < mid) {
                ops.push_back(1); // Chocolа -> Vanilla
            } else {
                ops.push_back(2); // Vanilla -> Chocolа
                x -= mid;
            }
        }
        reverse(ops.begin(), ops.end());
        cout << ops.size() << "\n";
        if (!ops.empty()) {
            for (size_t i = 0; i < ops.size(); ++i) {
                if (i) cout << ' ';
                cout << ops[i];
            }
        }
        cout << "\n";
    }
    return 0;
}
