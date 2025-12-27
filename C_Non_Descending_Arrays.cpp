#include<bits/stdc++.h>
#include<iostream>
using namespace std;
long long mod=998244353;
long long solve(int ind, int prevSwap, vector<int>& a, vector<int>& b, vector<vector<long long> >& dp) {
    int n = a.size();
    if (ind == n) return 1; // reached end safely

    if (dp[ind][prevSwap] != -1) return dp[ind][prevSwap];

    long long ans = 0;
    int prevA = a[ind-1], prevB = b[ind-1];
    if (prevSwap) swap(prevA, prevB);

    // no swap at this index
    if (a[ind] >= prevA && b[ind] >= prevB) {
        ans += solve(ind+1, 0, a, b, dp);
    }

    // swap at this index
    if (b[ind] >= prevA && a[ind] >= prevB) {
        ans += solve(ind+1, 1, a, b, dp);
    }

    return dp[ind][prevSwap] = ans;
}

long long countWays(vector<int>& a, vector<int>& b) {
    int n = a.size();
    vector<vector<long long> > dp(n+1, vector<long long>(2, -1));
    return (solve(1, 0, a, b, dp) + solve(1, 1, a, b, dp))%mod;
}
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        vector<int> a(n);
        vector<int> b(n);
        for (int i=0;i<n;i++) cin>>a[i];
        for (int i=0;i<n;i++) cin>>b[i];
        long long ans=countWays(a,b);
        cout<<ans<<endl;
    }
}