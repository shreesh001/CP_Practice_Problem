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
    ll n,x,y;
    cin>>n>>x>>y;
    vector<ll>a(n);
    for (int i=0;i<n;i++) cin>>a[i];

    int mini=n+1;
    int ind=-1;
    for (int i=x;i<y;i++){
        if (a[i]<mini){
            mini=a[i];
            ind=i;
        }
    }
    vector<int>back;
    int ind2=-1;
    for (int i=0;i<x;i++){
        if (a[i]>mini){
            ind2=i;
            while(i<x){
                back.push_back(a[i]);
                i++;
            }
        }
    }
    if (back.size()!=0){
        for (int i=0;i<ind2;i++){
            cout<<a[i]<<" ";
        }
        for (int i=ind;i<y;i++){
            cout<<a[i]<<" ";
        }
        for (int i=x;i<ind;i++){
            cout<<a[i]<<" ";
        }
        for (int i=0;i<back.size();i++){
            cout<<back[i]<<" ";
        }
        for (int i=y;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<"\n";
        return;
    }

    vector<int>front;
    for (int i=y;i<n;i++){
        while (i<n && a[i]<mini){
            front.push_back(a[i]);
            ind2=i;
            i++;
        }
        if (a[i]>mini) break;
    }
    if (front.size()!=0){
        for (int i=0;i<x;i++){
            cout<<a[i]<<" ";
        }
        for (int i=0;i<front.size();i++){
            cout<<front[i]<<" ";
        }
        for (int i=ind;i<y;i++){
            cout<<a[i]<<" ";
        }
        for (int i=x;i<ind;i++){
            cout<<a[i]<<" ";
        }
        for (int i=ind2+1;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<"\n";
        return;
    }

    for (int i=0;i<x;i++){
        cout<<a[i]<<" ";
    }
    for (int i=ind;i<y;i++){
        cout<<a[i]<<" ";
    }
    for (int i=x;i<ind;i++){
        cout<<a[i]<<" ";
    }
    for (int i=y;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    return;

    

    

    
}

// ---------------- MAIN ----------------
int main() {
    fastio();
    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}