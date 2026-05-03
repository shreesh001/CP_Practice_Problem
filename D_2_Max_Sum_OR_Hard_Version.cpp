#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

/**
 * find_permutation: Recursively fills the permutation array 'a' 
 * and calculates the total OR sum for the range [l, r].
 */
void find_permutation(int l, int r, vector<int>& a, ll& current_sum) {
    if (l > r) return;

    // Base case: single element
    if (l == r) {
        a[l] = l;
        current_sum += l;
        return;
    }

    // Find the highest bit k such that 2^k <= r
    int k = 31 - __builtin_clz(r);
    int p2 = 1 << k;

    if (p2 <= l) {
        // Case 1: All numbers in [l, r] have the k-th bit set.
        // Solve for the range without the k-th bit, then add it back.
        ll sub_sum = 0;
        find_permutation(l - p2, r - p2, a, sub_sum);
        
        // Map the results back to the original range [l, r]
        for (int i = l; i <= r; ++i) {
            // The value stored in a[i-p2] was for the shifted range
            int val = a[i - p2];
            a[i] = val + p2;
            current_sum += (i | a[i]);
        }
    } else {
        // Case 2: The bit boundary p2 is within (l, r].
        // We pair elements from [p2, r] with their complements in [p2-len, p2-1].
        int mask = (1 << (k + 1)) - 1;
        int len = r - p2 + 1;
        int L_match = p2 - len;

        for (int i = 0; i < len; ++i) {
            int u = p2 + i;     // Element in upper part
            int v = u ^ mask;   // Complement in lower part
            a[u] = v;
            a[v] = u;
            current_sum += (ll)(u | v) * 2;
        }

        // Recurse on the remaining elements in the range [l, L_match - 1]
        find_permutation(l, L_match - 1, a, current_sum);
    }
}

void solve() {
    int l, r;
    if (!(cin >> l >> r)) return;

    // Using a vector to store the permutation for indices [l, r]
    // Size r+1 to allow direct indexing
    vector<int> a(r + 1);
    ll total_sum = 0;

    find_permutation(l, r, a, total_sum);

    // Output the maximum sum
    cout << total_sum << "\n";

    // Output the permutation a_l, a_{l+1}, ..., a_r
    for (int i = l; i <= r; ++i) {
        cout << a[i] << (i == r ? "" : " ");
    }
    cout << "\n";
}

int main() {
    // Optimize I/O operations
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}