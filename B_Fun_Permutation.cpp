#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        vector<int> p(n);
        for (int i=0;i<n;i++){
            cin>>p[i];
        }
        vector<int> ans(n);
        for (int i=0;i<n;i++){
            ans[i]=n+1-p[i];
        }
        for (int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}