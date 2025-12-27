#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int x,n;
        cin>>x>>n;
        if (n%2==0) cout<<0<<"\n";
        else cout<<x<<"\n";
    }
}