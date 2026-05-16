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
void balance(multiset<ll>&msl,multiset<ll>&msr,ll &suml ,ll &sumr){
    if (msr.size()>msl.size()){
        suml+=*msr.begin();
        sumr-=*msr.begin();
        msl.insert(*msr.begin());
        msr.erase(msr.begin());
    }
    if (msl.size()>msr.size()+1){
        suml-=*msl.rbegin();
        sumr+=*msl.rbegin();
        msr.insert(*msl.rbegin());
        msl.erase(prev(msl.end()));
    }
}
void solve() {
    ll n,k;
    cin>>n>>k;
    vector<ll>nums(n);
    for (int i=0;i<n;i++) cin>>nums[i];

    multiset<ll>msl,msr;
    ll suml=0,sumr=0;

    for (int i=0;i<k;i++){
        if (msl.empty() || *msl.rbegin()>=nums[i]){
            msl.insert(nums[i]);
            suml+=nums[i];
        }
        else{
            msr.insert(nums[i]);
            sumr+=nums[i];
        }
        balance(msl,msr,suml,sumr);
    }
    cout<<((msl.size()*(*msl.rbegin()))-suml)+(sumr-(msr.size()*(*msl.rbegin())))<<" ";
    for (int i=k;i<n;i++){
        if (msl.find(nums[i-k])!=msl.end()){
            msl.erase(msl.find(nums[i-k]));
            suml-=nums[i-k];
        } 
        else{
            msr.erase(msr.find(nums[i-k]));
            sumr-=nums[i-k];
        } 
        balance(msl,msr,suml,sumr);
        if (msl.empty() || *msl.rbegin()>=nums[i]){
            msl.insert(nums[i]);
            suml+=nums[i];
        }
        else{
            msr.insert(nums[i]);
            sumr+=nums[i];
        }
        balance(msl,msr,suml,sumr);
        cout<<((msl.size()*(*msl.rbegin()))-suml)+(sumr-(msr.size()*(*msl.rbegin())))<<" ";
    }
    cout<<"\n";
}

// ---------------- MAIN ----------------
int main() {
    fastio();
    int t = 1;
    //cin >> t; 
    while (t--) solve();
    return 0;
}