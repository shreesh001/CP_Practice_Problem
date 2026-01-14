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
    ll n;
    cin>>n;
    vector<ll>a(n);
    for (int i=0;i<n;i++) cin>>a[i];
    if (a[n-1]<a[n-2]){
        cout<<-1<<endl;
        return;
    }
    if (a[n-1]<0) {
        if (!is_sorted(a.begin(), a.end())) {
            cout << -1 << "\n";
            return;
        }
    }
    int ind=n-3;
    int op=0;
    vector<int>index;
    while(ind>=0){
        if (a[ind]>a[ind+1]){
            ll val=a[ind+1]-a[n-1];
            if (val>a[ind+1]){
                cout<<-1<<endl;
                return;
            }else a[ind]=val;
            index.push_back(ind+1);
            index.push_back(ind+2);
            index.push_back(n);
            op++;
        }
        ind--;
    }
    cout<<op<<endl;
    for (int i=1;i<=index.size();i++){
        cout<<index[i-1]<<" ";
        if (i%3==0) cout<<"\n";
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