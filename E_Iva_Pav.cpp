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
int Output(vector<int>&left,vector<int>&right,int l,int mid){
    vector<int>number(32,0);
    int maxi=0;
    for (int i=0;i<32;i++){
        number[i]=right[i]-left[i];
        maxi=max(number[i],maxi);
    }
    if (maxi<mid-l+1){
        return -1;
    }
    int k=0;
    for (int i=0;i<32;i++){
        if (number[i]==maxi){
            k+=(1<<i);
        }
    }
    return k;
}
void solve() {
    int n;
    cin>>n;
    vector<int>a(n+1,0);
    for (int i=1;i<=n;i++) cin>>a[i];
    vector<vector<int>>prefdigit(n+1,vector<int>(32,0));
    for (int i=1;i<=n;i++){
        int num=a[i];
        for (int j=0;j<32;j++){
            int bit=(num>>j)&1;
            prefdigit[i][j]=prefdigit[i-1][j]+bit;
        }
    }

    int q;
    cin>>q;
    while(q--){
        int l,k;
        cin>>l>>k;
        if (k>a[l]){
            cout<<-1<<" ";
            continue;
        }
        int low=l;
        int high=n;
        int ans=-1;
        vector<int>left=prefdigit[l-1];
        while(low<=high){
            int mid=(low+high)/2;
            vector<int>right=prefdigit[mid];
            if (Output(left,right,l,mid)>=k){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        cout<<ans<<" ";
    }
    cout<<"\n";
}

// ---------------- MAIN ----------------
int main() {
    fastio();
    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}