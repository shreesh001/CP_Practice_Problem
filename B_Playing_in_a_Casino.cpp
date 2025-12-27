#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        long long n,m;
        cin>>n>>m;
        vector<vector<long long>> a(n,vector<long long>(m));
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        long long pot=0;
        for (int col=0;col<m;col++){
            vector<long long> b(n);
            for (int i=0;i<n;i++){
                b[i]=a[i][col];
            }
            sort(b.begin(),b.end());
            for (int j=0;j<n;j++){
                pot+=((-1)*b[j]*(n-1-j))+((1)*b[j]*(j));
            }
        }
        cout<<pot<<endl;
    }
}