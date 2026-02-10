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
    int n,p;
    cin>>n>>p;
    string s;
    cin>>s;
    if (p==1 || p==n){
        cout<<1<<endl;
        return;
    }

    int indl=-1;
    int indr=-1;
    
    // Correction: Use temporary variables for searching so you don't break logic later
    int cur_l = p - 2; 
    int cur_r = p; 

    while(cur_l >= 0){
        if (s[cur_l] == '#'){
            indl = cur_l;
            break;
        }
        cur_l--;
    }
    while(cur_r < n){
        if (s[cur_r] == '#'){
            indr = cur_r;
            break;
        }
        cur_r++;
    }
    
    if (indl == -1 && indr == -1){
        cout<<1<<endl;
        return;
    }

    // Correction: Simplify the check for adjacent walls
    if (indl == p-2 || indr == p){
        cout << min(p, n - p + 1) << endl;
        return;
    }
    else {
        // Correction: Handle cases where indl or indr are -1 using ternary operators
        int initleftdays = (indl == -1) ? 1 : indl + 2;
        int initrightdays = (indr == -1) ? 1 : n - indr + 1;
        
        // Scenario 1: Mani blocks immediately to the left
        int leftdays = p; 
        int ans1 = min(leftdays, initrightdays);
        
        // Scenario 2: Mani blocks immediately to the right
        int rightdays = n - p + 1; 
        int ans2 = min(initleftdays, rightdays);
        
        cout << max(ans1, ans2) << endl;
        return;
    }
}

// ---------------- MAIN ----------------
int main() {
    fastio();
    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}