#include <bits/stdc++.h>
#include <iostream>
using namespace std;

using ll = long long;
using ld = long double;

// ---------------- TYPE SHORTCUTS ----------------
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vpi = vector<pii>;
using vpl = vector<pll>;
using umll = unordered_map<ll,ll>;
using umii = unordered_map<int,int>;

#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr);

// ---------------- DEBUG (disabled in judge) ----------------
#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << " = " << x << "\n";
    #define debugv(v) cerr << #v << " : "; for(auto &x : v) cerr << x << " "; cerr << "\n";
#else
    #define debug(x)
    #define debugv(v)
#endif

// ---------------- MODULAR UTILITIES ----------------
const ll MOD = 1e9 + 7;
ll addmod(ll a, ll b) { a %= MOD; b %= MOD; return (a + b + MOD) % MOD; }
ll mulmod(ll a, ll b) { return (a % MOD) * (b % MOD) % MOD; }
ll powmod(ll a, ll b) { ll r = 1; while (b) { if (b & 1) r = mulmod(r, a); a = mulmod(a, a); b >>= 1; } return r; }
ll invmod(ll a) { return powmod(a, MOD - 2); }

// ---------------- DISJOINT SET UNION (DSU) ----------------
struct DSU {
    vector<int> parent, sz;
    DSU(int n) { parent.resize(n); sz.assign(n, 1); iota(all(parent), 0); }
    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }
    void merge(int a, int b) {
        a = find(a); b = find(b);
        if (a != b) {
            if (sz[a] < sz[b]) swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    }
};

// ---------------- BINARY SEARCH HELPERS ----------------
template<typename T, typename F>
T binary_search_first(T lo, T hi, F ok) {
    while (lo < hi) {
        T mid = lo + (hi - lo) / 2;
        if (ok(mid)) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

template<typename T, typename F>
T binary_search_last(T lo, T hi, F ok) {
    while (lo < hi) {
        T mid = lo + (hi - lo + 1) / 2;
        if (ok(mid)) lo = mid;
        else hi = mid - 1;
    }
    return lo;
}

#include <iostream>
#include <vector>

using namespace std;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

// ---------------- SOLVE FUNCTION ----------------
void solve() {
    int n, k, q;
    cin >> n >> k >> q;

    // Track which indices are covered by which type of queries
    vector<bool> type1(n + 1, false);
    vector<bool> type2(n + 1, false);

    for (int i = 0; i < q; i++) {
        int c, l, r;
        cin >> c >> l >> r;
        if (c == 1) {
            for (int j = l; j <= r; j++) type1[j] = true;
        } else {
            for (int j = l; j <= r; j++) type2[j] = true;
        }
    }

    vector<int> ans(n + 1, 1e9);
    int cycle_val = 0;

    for (int i = 1; i <= n; i++) {
        if (type1[i]) {
            // If it's in a Type 1 constraint, it must be >= k
            if (type2[i]) {
                // If it's also in Type 2, it CANNOT be k. Set it higher.
                ans[i] = 1e9; 
            } else {
                // Safe to use as the minimum for Type 1
                ans[i] = k;   
            }
        } else {
            // Not restricted by Type 1, so use it to feed the MEX requirement
            ans[i] = cycle_val % k;
            cycle_val++;
        }
    }

    // Output the array
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

// ---------------- MAIN ----------------
int main() {
    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}