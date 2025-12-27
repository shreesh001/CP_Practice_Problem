#include<bits/stdc++.h>
#include<iostream>
#define ll long long
using namespace std;
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        ll n,k,a,b;
        cin>>n>>k>>a>>b;
        vector<ll> x(n+1),y(n+1);
        for (int i=1;i<=n;i++){
            cin>>x[i];
            cin>>y[i];
        }
        ll ans=(abs(x[a]-x[b])+abs(y[a]-y[b]));
        ll mina=1e17;
        ll minb=1e17;
        for (int i=1;i<=k;i++){
            mina=min(mina,(abs(x[a]-x[i])+abs(y[a]-y[i])));
            minb=min(minb,(abs(x[b]-x[i])+abs(y[b]-y[i])));
        }
        ans=min(ans,mina+minb);
        cout<<ans<<endl;
    }
}