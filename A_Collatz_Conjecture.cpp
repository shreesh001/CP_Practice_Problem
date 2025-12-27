#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        long long x,k;
        cin>>k>>x;
        long long ans=(1<<k)*x;
        cout<<ans<<endl;
    }
}