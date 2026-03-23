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
    ll n,m;
    cin>>n>>m;
    vector<ll>a(n),b(m),c(m);
    ll maxi=0;
    int ind=-1;
    for (int i=0;i<n;i++) {
        cin>>a[i];
        if (a[i]>maxi){
            maxi=a[i];
            ind=i;
        }
    }
    for (int i=0;i<m;i++) cin>>b[i];
    for (int i=0;i<m;i++) cin>>c[i];

    vector<pair<ll,ll>>phase1;
    for (int i=0;i<m;i++){
        if (c[i]!=0){
            phase1.push_back({b[i],c[i]});
        }
    }
    sort(phase1.begin(),phase1.end());
 
    for (int i=1;i<phase1.size();i++){
        phase1[i].second=max(phase1[i-1].second,phase1[i].second);
    }
    
    int el=0;
    while(true){
        auto it = upper_bound(phase1.begin(), phase1.end(), make_pair(maxi, LLONG_MAX));
        if (it==phase1.begin()) break;
        el=it-phase1.begin();
        --it;
        auto p=*it;
        ll newmaxi=p.second;
        if (newmaxi<=maxi) break;
        if (it==phase1.end()) break;
        maxi=newmaxi;
    }
    ll ans=el;

    vector<ll>phase2;
    for (int i=0;i<m;i++){
        if (c[i]==0){
            phase2.push_back(b[i]);
        }
    }
    a[ind]=maxi;
    sort(a.begin(),a.end());
    sort(phase2.begin(),phase2.end());
    int i=0;
    int j=0;
    while(i<n && j<phase2.size()){
        if (phase2[j]>a[i]) i++;
        else {
            i++;
            j++;
            ans+=1;
        }
    }
    cout<<ans<<"\n";
}

// ---------------- MAIN ----------------
int main() {
    fastio();
    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}