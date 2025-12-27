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
        vector <ll> a(n,0),b(n,0);
        for (int i=0;i<n;i++){
            cin>>a[i];
        }
        for (int i=0;i<n;i++){
            cin>>b[i];
        }
        sort(a.begin(),a.end());
        sort(b.rbegin(),b.rend());
        ll Mod=1e9+7;
        ll result=1;
        for (int i=0;i<n;i++){
            auto add=upper_bound(a.begin(),a.end(),b[i])-a.begin();
            int cnt=a.size()-add;
            result=result*(cnt-i)%Mod;
        }
        cout<<result<<endl;
    }
}