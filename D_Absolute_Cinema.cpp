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
    int n;
    cin >> n;
    vector<long long> f(n);
    for (int i = 0; i < n; ++i) {
        cin >> f[i];
    }

    if (n == 2) {
        cout << f[1] << " " << f[0] << "\n";
        return;
    }

    vector<long long> a(n);
    for (int i = 1; i < n - 1; ++i) {
        a[i] = (f[i - 1] + f[i + 1] - 2 * f[i]) / 2;
    }

    // 2. Solve for a[n] (0-indexed: a[n-1])
    // f(1) = sum_{j=2}^n a_j * (j-1)
    // f[0] = sum_{j=1}^{n-1} a[j] * j  (using 0-based index for a, so a_j is a[j-1])
    // actually, let's stick to 1-based logic for the sum calculation to avoid confusion
    // f(1) = a_2 * 1 + a_3 * 2 + ... + a_{n-1} * (n-2) + a_n * (n-1)
    
    long long current_sum = 0;
    for (int i = 1; i < n - 1; ++i) { // i is 0-based index in array 'a', corresponds to a_{i+1}
        current_sum += a[i] * i; 
    }
    
    // a_n = (f(1) - current_sum) / (n-1)
    a[n - 1] = (f[0] - current_sum) / (n - 1);

    // 3. Solve for a[1] (0-indexed: a[0])
    // f(n) = a_1 * (n-1) + a_2 * (n-2) + ...
    long long current_sum_rev = 0;
    for (int i = 1; i < n; ++i) {
        current_sum_rev += a[i] * (n - 1 - i);
    }
    a[0] = (f[n - 1] - current_sum_rev) / (n - 1);

    for (int i = 0; i < n; ++i) {
        cout << a[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

// ---------------- MAIN ----------------
int main() {
    fastio();
    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}