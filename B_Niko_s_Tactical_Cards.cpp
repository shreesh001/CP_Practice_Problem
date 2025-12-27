#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int solve(int ind,int n,vector<long long>&a,vector<long long>&b){
    if (ind>=n) return 0;
    int k=a[ind];
    int takea=max(k-solve(ind+1,n,a,b),solve(ind+1,n,a,b)-k);
    int takeb=0;
             
}
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        long long k=0;
        vector<long long>a(n),b(n);
        for (int i=0;i<n;i++){
            cin>>a[i];
        }
        for (int i=0;i<n;i++){
            cin>>b[i];
        }
        for (int i=0;i<n;i++){
            if ((k-a[i])>(b[i]-k)){
                k=k-a[i];
            }
            else{
                k=b[i]-k;
            }
        }
        cout<<k<<endl;
    }
}