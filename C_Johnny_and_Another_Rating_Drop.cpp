#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void solve() {
    int N;
    long long K;
    if (!(cin >> N >> K)) return;

    vector<int> A(N);
    map<int, int> freqs;
    int initial_distinct_count = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        if (freqs[A[i]] == 0) {
            initial_distinct_count++;
        }
        freqs[A[i]]++;
    }

    // The first element A[0] cannot be changed (no index i < 0).
    // So the distinct value A[0] will always remain.
    int fixed_val = A[0];

    // Collect frequencies of all distinct elements EXCEPT the fixed one.
    // We want to remove elements with the smallest frequencies first.
    vector<int> removal_costs;
    for (auto const& [val, count] : freqs) {
        if (val != fixed_val) {
            removal_costs.push_back(count);
        }
    }

    // Sort costs to remove cheapest distinct elements first (Greedy)
    sort(removal_costs.begin(), removal_costs.end());

    int removed_distinct = 0;
    for (int cost : removal_costs) {
        if (K >= cost) {
            K -= cost;
            removed_distinct++;
        } else {
            // Cannot afford to remove this distinct element completely
            break;
        }
    }

    cout << initial_distinct_count - removed_distinct << endl;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}