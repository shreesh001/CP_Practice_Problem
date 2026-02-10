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
    cin>>n;
    vector<int>a(n);
    for (int i=0;i<n;i++) cin>>a[i];
    vector<int>even,odd;
    for (int i=0;i<n;i++){
        if (a[i]%2==0) even.push_back(a[i]);
        else odd.push_back(a[i]);
    }
    sort(odd.rbegin(),odd.rend());
    sort(even.rbegin(),even.rend());

    if (odd.size()==0){
        for (int k=1;k<=n;k++) cout<<0<<" ";
        cout<<endl;
        return;
    }
    if (even.size()==0){
        for (int k=1;k<=n;k++){
            if (k%2==1) cout<<odd[0]<<" ";
            else cout<<0<<" ";
        }
        cout<<endl;
        return;
    }

    int coin=0;
    int i=0;
    int j=0;
    int ans1=0;
    int ans2=0;
    int flag=0;
    for (int k=1;k<=n;k++){
        if (k==n && odd.size()%2==0){
            cout<<0<<" ";
            break;
        }
        if (k==1){
            coin+=odd[i];
            i++;
            cout<<coin<<" ";
        }
        else {
            if (j<even.size()){
                coin+=even[j];
                if (j==even.size()-2) ans1=coin;
                if (j==even.size()-1) ans2=coin;
                j++;
                cout<<coin<<" ";
            }
            else {
                if (flag==0){
                    cout<<ans1<<" ";
                    flag=1;
                }else{
                    cout<<ans2<<" ";
                    flag=0;
                }
            }
        }
    }
    cout<<endl;
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