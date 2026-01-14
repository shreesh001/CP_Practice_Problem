#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Use a large value for infinity
const long long INF = 4e18; 

struct State {
    int count;
    long long l, r; // Represents the open interval (l, r) for the current radius
};

void solve() {
    int n;
    cin >> n;
    vector<long long> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    if (n < 2) {
        cout << 0 << "\n";
        return;
    }

    // Initial state at point x[0]: 0 tangent pairs, radius can be anything > 0.
    vector<State> current_states;
    current_states.push_back({0, 0, INF});

    for (int i = 0; i < n - 1; ++i) {
        long long d = x[i+1] - x[i];
        vector<State> next_states;

        for (const auto& s : current_states) {
            // Option 1: Create a Gap (don't connect i and i+1)
            // Valid if we can pick a radius 'r' in (s.l, s.r) such that r < d.
            // This requires the lower bound s.l to be less than d.
            if (s.l < d) {
                // If we gap, the next radius starts fresh, effectively (0, INF)
                next_states.push_back({s.count, 0, INF});
            }

            // Option 2: Connect (make i and i+1 tangent)
            // We need r + r_new = d => r_new = d - r.
            // Input range is (s.l, s.r).
            // New range is roughly (d - s.r, d - s.l).
            // Constraint: r_new > 0 => d - r > 0 => r < d.
            // So effective input r is in (s.l, min(s.r, d)).
            
            // Calculating new interval bounds:
            // new_lower = d - s.r (but must be at least 0)
            // new_upper = d - s.l
            // Note: If s.r is INF, d - s.r is very small (negative), so max(0, ...) handles it.
            
            long long new_l = max(0LL, d - s.r);
            long long new_r = d - s.l;

            if (new_l < new_r) {
                next_states.push_back({s.count + 1, new_l, new_r});
            }
        }

        // Pruning logic to keep complexity O(N)
        // 1. Find the best count achievable with a completely flexible (0, INF) interval.
        int max_unbounded_count = -1;
        for (const auto& s : next_states) {
            if (s.r == INF) {
                max_unbounded_count = max(max_unbounded_count, s.count);
            }
        }

        vector<State> pruned_states;
        
        // Add the best unbounded state if it exists
        if (max_unbounded_count != -1) {
            pruned_states.push_back({max_unbounded_count, 0, INF});
        }

        // Add any restricted states that have a BETTER count than the best unbounded one.
        for (const auto& s : next_states) {
            if (s.count > max_unbounded_count) {
                pruned_states.push_back(s);
            }
        }

        current_states = pruned_states;
    }

    int max_tangent = 0;
    for (const auto& s : current_states) {
        max_tangent = max(max_tangent, s.count);
    }
    cout << max_tangent << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}