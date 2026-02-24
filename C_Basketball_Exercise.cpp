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
ll solvedp(int ind,int type,vector<ll>&a,vector<ll>&b,vector<vector<ll>>&dp){
    int n=a.size();
    if (ind==n) return 0;
    if (dp[ind][type]!=-1) return dp[ind][type];
    ll nottake=solvedp(ind+1,type,a,b,dp);
    ll take1=0;
    ll take2=0;
    if (type!=1){
        take1=a[ind]+solvedp(ind+1,1,a,b,dp);
    }
    if (type!=2){
        take2=b[ind]+solvedp(ind+1,2,a,b,dp);
    }
    return dp[ind][type]=max({nottake,take1,take2});
}
void solve() {
    ll n;
    cin>>n;
    vector<ll>a(n),b(n);
    for (int i=0;i<n;i++) cin>>a[i];
    for (int i=0;i<n;i++) cin>>b[i];
    vector<vector<ll>>dp(n,vector<ll>(3,-1));
    ll ans=solvedp(0,0,a,b,dp);
    cout<<ans<<"\n";
}

// ---------------- MAIN ----------------
int main() {
    fastio();
    int t = 1;
    //cin >> t; 
    while (t--) solve();
    return 0;
}