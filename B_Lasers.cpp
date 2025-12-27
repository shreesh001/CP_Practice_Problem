#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n,m,x,y;
        cin>>n>>m>>x>>y;
        vector<int> a(n),b(m);
        for (int i=0;i<n;i++) cin>>a[i];
        for (int i=0;i<m;i++) cin>>b[i];
        cout<<n+m<<"\n";
    }
}