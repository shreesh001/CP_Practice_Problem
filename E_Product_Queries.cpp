#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> a(n);
    bool has_one = false;
    vector<int> distinct;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // 1. Preprocess: Sort and extract unique numbers > 1
    sort(a.begin(), a.end());
    for (int x : a) {
        if (x == 1) {
            has_one = true;
        } else {
            // Add to distinct if it's the first element or different from the previous
            if (distinct.empty() || distinct.back() != x) {
                distinct.push_back(x);
            }
        }
    }

    // 2. BFS Initialization
    // dist[i] stores min elements to reach product i. -1 means unreachable.
    vector<int> dist(n + 1, -1);
    queue<int> q;

    // Start from multiplicative identity
    dist[1] = 0;
    q.push(1);

    // 3. Run BFS
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : distinct) {
            long long prod = (long long)u * v;
            
            // Optimization: If product exceeds n, larger v will also exceed n
            if (prod > n) break;

            if (dist[(int)prod] == -1) {
                dist[(int)prod] = dist[u] + 1;
                q.push((int)prod);
            }
        }
    }

    // 4. Output Results
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            // Special rule: must select at least one element
            cout << (has_one ? 1 : -1) << " ";
        } else {
            cout << dist[i] << " ";
        }
    }
    cout << "\n";
}

int main() {
    // Fast I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}