#include<bits/stdc++.h>
#include<iostream>
#define ll long long
using namespace std;
int area(vector<ll>&a,ll mid,ll c){
    ll totalarea=0;
    for (int i=0;i<a.size();i++){
        totalarea+=((a[i]+mid)*(a[i]+mid));
        if (totalarea>c){
            return 2;
        }
    }
    if (totalarea<c){
        return 1;
    }
    return 0;
}
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        ll n,c;
        cin>>n>>c;
        vector<ll> a(n);
        for (int i=0;i<n;i++){
            cin>>a[i];
        }
        ll low=1;
        ll high=1e10;
        ll ans=0;
        while(low<=high){
            ll mid=(low+high)/2;
            if (area(a,mid,c)==0){
                ans=mid;
                break;
            }
            else if (area(a,mid,c)==1){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        cout<<ans/2<<endl;
    }

}