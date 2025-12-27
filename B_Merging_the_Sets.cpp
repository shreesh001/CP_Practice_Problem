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

// ---------------- SOLVE FUNCTION ----------------

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> sets(n);
    vector<int> freq(m + 1, 0);
    // Input + frequency count
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        sets[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> sets[i][j];
            freq[sets[i][j]]++;
        }
    }
    // If any number in [1..m] appears zero times → no way
    for (int x = 1; x<= m; x++) {
        if (freq[x] == 0) {
            cout << "NO\n";
            return;
        }
    }
    // Count forced sets
    int forcedSets = 0;
    for (int i = 0; i < n; i++) {
        bool forced = false;
        for (int x : sets[i]) {
            if (freq[x] == 1) {
                forced = true;
                break;
            }
        }
        if (forced) forcedSets++;
    }

    int optional = n - forcedSets;

    // Need at least 2 optional sets → 2^optional ≥ 3
    if (optional >= 2)
        cout << "YES\n";
    else
        cout << "NO\n";
}

// ---------------- MAIN ----------------
int main() {
    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}