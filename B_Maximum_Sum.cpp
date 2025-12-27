#include<bits/stdc++.h>
#include<iostream>
#define ll long long
using namespace std;
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        ll n,k;
        cin>>n>>k;
        vector<ll> a(n);
        for (int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        ll sum = accumulate(a.begin(), a.end(), 0ll);
        vector<ll> suffixsum(n+1,0);
        suffixsum[n-1]=a[n-1];
        for (int i=n-2;i>=0;i--){
            suffixsum[i]=a[i]+suffixsum[i+1];
        }
        vector<ll> prefixsum(n+1,0);
        prefixsum[1]=a[0];
        for (int i=1;i<n;i++){
            prefixsum[i]=a[i-1]+prefixsum[i-1];
        }
        ll sum1=0;
        for (int i=0;i<=k;i++){
            int j=k-i;
            sum1=max(sum1,(sum-prefixsum[2*i]-suffixsum[n-j]));
        }
        cout<<sum1<<endl;
    }
}
