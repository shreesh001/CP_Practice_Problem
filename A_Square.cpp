#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if (a!=b || a!=c || a!=d){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
        }
    }
}