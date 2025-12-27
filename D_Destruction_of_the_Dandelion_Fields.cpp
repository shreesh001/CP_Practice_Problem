#include<bits/stdc++.h>
#include<iostream>
#define ll long long
using namespace std;
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        ll n;
        cin>>n;
        vector<ll>a(n);
        for (int i=0;i<n;i++){
            cin>>a[i];
        }
        ll ans=0;
        vector<ll> odd;
        for (int i=0;i<n;i++){
            if (a[i]%2!=0) odd.push_back(a[i]);
        }
        int sz=odd.size();
        if (sz==0){
            cout<<ans<<endl;
            continue;
        }
        sort(odd.begin(),odd.end());
        int times=(sz+1)/2;
        int i=1;
        while(i<=times){
            ans+=odd[sz-i];
            i++;
        }
        for (int i=0;i<n;i++){
            if (a[i]%2==0) ans+=a[i];
        }
        cout<<ans<<endl;
    }
}